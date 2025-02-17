#include "SLL2.h"
#include <stdio.h>

void SLL2_print(Node* head) {
	if ((head = head->next) == NULL) {
		printf("출력할 노드가 없습니다.");
	}
	for (; head != NULL; head = head->next)
		printf("%d ", head->Data);
	printf("\n");
	return;
}

Node* SLL2_CreateNode(ElementType data) {
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

void SLL2_DestroyNode(Node** dnode) {
	free(*dnode);
	*dnode = NULL;
}

void SLL2_AppendNode(Node* head, Node* newnode) {
	if (head == NULL || newnode == NULL) return;

	for (; head->next != NULL; head = head->next);
	head->next = newnode;

	return;
}

void SLL2_RemoveNode(Node* head, ElementType value) {
	if (head == NULL) return;

	Node* curr = head->next;
	Node* prev = head;

	for (; curr != NULL; prev = curr, curr = curr->next) {
		if (curr->Data == value) {
			prev->next = curr->next;
			SLL2_DestroyNode(&curr);
			return;
		}
	}

	printf("삭제할 데이터가 없습니다.\n");
	return;
}

void SLL2_Insert(Node* head, Node* newnode, unsigned int pos) {
	if (head == NULL || newnode == NULL) return;

	Node* curr = head->next;
	Node* prev = head;

	for (;curr != NULL && pos > 0; --pos) {
		prev = curr;
		curr = curr->next;
	}

	if (pos > 0) {
		printf("index가 너무 큽니다.\n");
		return;
	}

	newnode->next = prev->next;
	prev->next = newnode;

	return;
}