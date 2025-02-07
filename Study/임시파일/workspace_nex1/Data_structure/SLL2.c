#include "SLL2.h"
#include <stdio.h>

void SLL2_print(Node* head) {
	if ((head = head->next) == NULL) {
		printf("����� ��尡 �����ϴ�.");
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
		printf("�޸� ����\n");
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

	printf("������ �����Ͱ� �����ϴ�.\n");
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
		printf("index�� �ʹ� Ů�ϴ�.\n");
		return;
	}

	newnode->next = prev->next;
	prev->next = newnode;

	return;
}