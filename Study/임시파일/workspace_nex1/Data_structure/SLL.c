#include "SLL.h"
#include <stdio.h>

void SLL_print(Node* head) {
	if (head == NULL) {
		printf("출력할 노드가 없습니다.");
	}
	for (;head != NULL; head = head->next)
		printf("%d ", head->Data);
	printf("\n");
	return;
}

Node* SLL_CreateNode(ElementType data) {
	Node* new_node = NULL;
	new_node = (Node*)calloc(1, sizeof(Node));

	if (new_node == NULL) {
		printf("메모리 부족\n");
		exit(0);
	}
	new_node->Data = data;
	new_node->next = NULL;
	return new_node;
}

void SLL_DestroyNode(Node** dnode) {
	free(*dnode);
	*dnode = NULL;
}

void SLL_AppendNode(Node** head, Node* newnode) {
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	Node* curr = *head;
	for (; curr->next != NULL; curr = curr->next);
	curr->next = newnode;

	return;
}

void SLL_RemoveNode(Node** head, ElementType value) {
	Node* curr = *head;
	Node* prev = NULL;

	for (; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->Data == value) {
			if (*head == curr)
				*head = curr->next;
			else
				prev->next = curr->next;

			SLL_DestroyNode(&curr);
		}
	}
	printf("삭제할 데이터가 없습니다.\n");
	return;
}

void SLL_Insert(Node** head, Node* newnode, int pos) {
	Node* curr = NULL;
	Node* prev = NULL;

	//if (pos == 0) { // (1)
	//	newnode->next = *head;
	//	*head = newnode;
	//	return;
	//}

// [0] -> [1] -> [2] -> [3] -> ...
	// search index
	for (curr = *head;
		curr != NULL && pos > 0;
		prev = curr, curr = curr->next, --pos);

	if (pos > 0) {
		printf("index가 너무 큽니다.\n");
		return;
	}

	if (prev == NULL) { // (2)
		newnode->next = *head;
		*head = newnode;
		return;
	}

	newnode->next = prev->next;
	prev->next = newnode;

	return;
}