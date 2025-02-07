#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if 0

typedef int ElementType;

typedef struct _treeNode {
	ElementType data;
	struct _treeNode* left;
	struct _treeNode* right;
} tNode;

typedef tNode* tNodeP;

tNode* Tree_CreateNode(ElementType data) {
	tNode* newnode;
	newnode = (tNode*)calloc(1, sizeof(tNode));
	if (newnode != NULL) {
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	return newnode;
}

void Tree_DestroyNode(tNode** node) {
	free(*node);
	*node = NULL;
}

void Tree_PreorderPrint(tNodeP Node) {
	if (Node == NULL) return;

	printf("%d ", Node->data);

	Tree_PreorderPrint(Node->left);
	Tree_PreorderPrint(Node->right);
}

void Tree_InorderPrint(tNodeP Node) {
	if (Node == NULL) return;

	Tree_PreorderPrint(Node->left);
	printf("%d ", Node->data);
	Tree_PreorderPrint(Node->right);
}

void Tree_PostorderPrint(tNodeP Node) {
	if (Node == NULL) return;

	Tree_PreorderPrint(Node->left);
	Tree_PreorderPrint(Node->right);
	printf("%d", Node->data);
}

void Tree_DestroyTree(tNodeP node) {
	if (node == NULL) return;

	Tree_DestroyTree(node->left);
	Tree_DestroyTree(node->right);
	Tree_DestroyNode(node);
}

int main(void) {
	tNodeP a, b, c;
	tNodeP root;

	a = Tree_CreateNode(10);
	b = Tree_CreateNode(20);
	c = Tree_CreateNode(30);

	root = a;
	root->left = b;
	root->right = c;

	printf("Preorder : ");
	Tree_PreorderPrint(root);

	printf("\nInorder : ");
	Tree_InorderPrint(root);

	printf("\nPostorder : ");
	Tree_PostorderPrint(root);

	Tree_DestroyTree(root);
	root = NULL;

	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main(void) {
	heapTree* hTree;
	htNode result;
	int N, num;
	FILE* fp = NULL;

	fp = fopen("data_heap.txt", "r");
	if (fp == NULL) {
		printf("Can't open File\n");
		return 1;
	}
	(void)fscanf(fp, "%d", &N);
	hTree = HT_CreateTree(10, comp_max);

	for (int i = 0; i < N; ++i) {
		(void)fscanf(fp, "%d", &num);
		printf("Inset : %d\n", num);
		HT_InsertNode(hTree, num);
	}

	HT_PrintTree(hTree);


	for (int i = 0; i < N; ++i) {
		result = HT_PopRoot(hTree);
		printf("Pop : %d\n", result.data);
	}
	HT_PrintTree(hTree);

	HT_DestroyTree(hTree);
	hTree = NULL;

	return 0;
}
#endif



// 이진 탐색
#if 0
#include <stdio.h>
#include <stdlib.h>

int comp_init(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void print_ary(int* arr, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int BinarySearch(int* arr, int size, int data) {
	int mid;
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == data) {
			return mid;
		}
		if (arr[mid] < data) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
	
}

int main(void) {
	int arr[] = { 4, 10, 3, 5, 2, 8, 1, 9, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, size, sizeof(int), comp_init);
	print_ary(arr, size);

	int data = 46;
	int ret = BinarySearch(arr, size, data);

	if (ret == -1)	printf("못 찾았습니다.\n");
	else			printf("arr[%d] = %d\n", ret, data);

	return 0;
}
#endif



#if 0
#include "Heap.h"

void solution() {
	int n, num, i;
	int sum, ret = 0;
	(void)scanf("%d", &n);

	heapTree *heap = HT_CreateTree(n+1, comp_min);
	
	for (i = n; i > 0; --i) {
		(void)scanf("%d", &num);
		HT_InsertNode(heap, num);
	}
	
	for (i = n-1; i > 0; --i)  {
		htNode d1, d2;
		d1 = HT_PopRoot(heap);
		d2 = HT_PopRoot(heap);
		if (d1.data == 0 || d2.data == 0) break;

		sum = d1.data + d2.data;
		HT_InsertNode(heap, sum);
		ret += sum;
	}
	printf("%d\n", ret);
}

int main(void) {
#ifdef _MSC_VER
	int n;
	(void)freopen("card_testcase.txt", "r", stdin);
	(void)scanf(" %d", &n);
	for (; n > 0; --n) {
#endif
		solution();
#ifdef _MSC_VER
	}
#endif
}

#endif

// 백준 1656
#if 0
#include "Heap.h"

void solution() {
	int n, num;
	heapTree* maxtree;
	heapTree* mintree;
	htNode small, big;

	(void)scanf("%d", &n);

	maxtree = HT_CreateTree(n / 2 + 2, comp_max);
	mintree = HT_CreateTree(n / 2 + 1, comp_min);

	for (; n > 0; --n) {
		(void)scanf("%d", &num);
		if (maxtree->usesize == mintree->usesize) {
			HT_InsertNode(maxtree, num);
		}
		else {
			HT_InsertNode(mintree, num);
		}

		if (mintree->usesize > 0 && maxtree->node[1].data > mintree->node[1].data) {
			small = HT_PopRoot(maxtree);
			big = HT_PopRoot(mintree);

			HT_InsertNode(maxtree, big.data);
			HT_InsertNode(mintree, small.data);
		}
		printf("%d\n", maxtree->node[1].data);
	}
}

int main(void) {
#ifdef _MSC_VER
	int n;
	(void)freopen("center_testcase.txt", "r", stdin);
	(void)scanf(" %d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("case %d :\n", i);
#endif
		solution();
#ifdef _MSC_VER
		printf("\n");
	}
#endif
}

#endif


#if 0
#include "Heap.h"

int comp_int(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	int N, d1, d2;
	int cnt = 0;
	int arr[1001] = { 0 };

	(void)freopen("data_j1788.txt", "r", stdin);
	(void)scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", arr + i);
	}
	qsort(arr, N, sizeof(int), comp_int);
	cnt = 0;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			d1 = arr[j] - arr[i];
			for (int k = j + 1; k < N; ++k) {
				d2 = arr[k] - arr[j];
				if (d1 <= d2 && (2 * d1) >= d2) {
					++cnt;
					printf("%d %d %d\n", arr[i], arr[j], arr[k]);
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}

#endif

#if 01
#include <stdio.h>
#include <stdlib.h>

int comp_int (const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void print_ary(int* arr, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int BinarySearch_upper(int* arr, int size, int data) {
	int mid, curr = -1;
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == data) {
			return mid;
		}
		if (arr[mid] < data) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			curr = mid;
		}
	}
	return curr;
}

int BinarySearch_lower(int* arr, int size, int data) {
	int mid, curr = 0;
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == data) {
			return mid;
		}
		if (arr[mid] < data) {
			start = mid + 1;
			curr = mid;
		}
		else {
			end = mid - 1;
		}
	}
	return curr;
}

int main(void) {
	int N, d1, d2;
	int cnt = 0;
	int arr[1001] = { 0 };

	(void)freopen("data_j1788.txt", "r", stdin);
	(void)scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", arr + i);
	}
	qsort(arr, N, sizeof(int), comp_int);
	print_ary(arr, N);

	//for (int i = 0; i < 12; ++i) {
	//	d1 = BinarySearch_lower(arr, N, i);
	//	d2 = BinarySearch_upper(arr, N, i);
	//	printf("%d %d %d\n", arr[d1], i, arr[d2]);
	//}

	int r1, r2;

	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			d1 = arr[j] - arr[i];
			r1 = BinarySearch_upper(arr, N, arr[j] + d1);
			if (r1 == -1) continue;
			r2 = BinarySearch_lower(arr, N, arr[j] + d1 * 2);
			cnt += (r2 - r1 + 1);
			printf("%d %d\n", r1, r2);
		}
	}
}
#endif