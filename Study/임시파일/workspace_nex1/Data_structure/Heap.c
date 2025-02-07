#include <stdlib.h>
#include <stdio.h>

#include "Heap.h"


heapTree* HT_CreateTree(int capacity, compFunc comp) {
	heapTree* tree;
	tree = (heapTree*)calloc(1, sizeof(heapTree));
	if (tree == NULL) {
		printf("메모리가 부족\n");
		return NULL;
	}
	tree->node = (htNode*)calloc(capacity, sizeof(htNode));
	if (tree->node == NULL) {
		printf("메모리가 부족 노드 생성 불가\n");
		free(tree);
		return NULL;
	}
	tree->capacity = capacity;
	tree->usesize = 0;
	tree->comp = comp;
	return tree;
}

void HT_SwapNode(htNode* a, htNode* b) {
	htNode temp = *a;
	*a = *b;
	*b = temp;
}

int comp_min(ElementType a, ElementType b) {
	return (a < b);
}

int comp_max(ElementType a, ElementType b) {
	return (a > b);
}

// min heap
/*
1	힙의 최고 깊이 가장 우측에 새 노드를 추가 (이때 힙은 완전 이진 트리를 유지하도록)
2	삽입한 노드를 부모 노드와 비교
	- 삽입한 노드가 부모 노드보다 크면 제 위치에 삽입된 것이므로 연산을 종료
	- 반대로 부모 노드보다 작은 경우에는 다음 단계를 진행
3	삽입한 노드가 부모 노드보다 작으면 부모 노드와 삽입한 노드의 위치를 서로 바꿈
	- 바꾼 후에는 단계 2를 다시 진행
*/
void HT_InsertNode(heapTree* tree, ElementType newdata) {
	int cur, parent;
	htNode* node = tree->node;;

	if (tree == NULL) return;

	tree->usesize += 1;
	cur = tree->usesize;

	node[cur].data = newdata;
	parent = cur / 2;

	while (cur > 1 && tree->comp(node[cur].data, node[parent].data)) {
		// SWAP
		HT_SwapNode(node + cur, node + parent);

		cur = parent;
		parent = cur / 2;
	}
}

//힙의 최솟값 삭제 : 뿌리 노드를 삭제
//뿌리 노드를 삭제한 후 ‘힙 순서 속성’을 유지하기 위한 뒤처리 과정
//❶ 힙의 최고 깊이 가장 우측에 있던 노드를 뿌리 노드로 옮김
//- 이때 힙 순서 속성이 파괴됩니다.이를 복원하기 위한 작업을 다음 단계부터 시작
//❷ 옮겨온 노드의 양쪽 자식을 비교하여 작은 쪽 자식과 위치를 교환
//- 힙 순서 속성을 지키려면 부모 노드는 양쪽 자식보다 작은 값을 가져야 하기 때문임
//❸ 옮겨온 노드가 더 이상 자식이 없는 잎 노드로 되거나 양쪽 자식보다 작은 값을 갖는 경우 삭제 연산을 종료
//- 그렇지 않으면 단계 ❷를 반복

htNode HT_PopRoot(heapTree* tree) {
	htNode ret = { 0 };
	htNode* node;
	int child1, child2, parent;
	int minchild;
	if (tree == NULL) return ret;
	if (tree->usesize == 0) return ret; // heap에 데이터가 없으면
	node = tree->node;

	ret = node[1];
	node[1] = node[tree->usesize];
	tree->usesize -= 1;

	parent = 1;
	child1 = parent * 2;
	child2 = child1 + 1;
	while (child1 <= tree->usesize) // child1이 tree 사용 사이즈 보다 크면 child2도 없음
	{
		minchild = child1;
		if (child2 <= tree->usesize) {
			minchild = tree->comp(node[child1].data, node[child2].data) ? child1 : child2;
		}

		if (tree->comp(node[parent].data, node[minchild].data)) break;

		HT_SwapNode(node + parent, node + minchild);
		parent = minchild;
		child1 = parent * 2;
		child2 = child1 + 1;
	}
	return ret;
}

void HT_DestroyTree(heapTree* tree) {
	free(tree->node);
	free(tree);
}

void HT_PrintTree(heapTree* tree) {
	int i, size = tree->usesize;
	htNode* node = tree->node;

	for (i = 1; i <= size; ++i) {
		printf("%d ", node[i].data);
	}
	printf("\n");
}
