#include "DLL.h"
#include <stdio.h>

void DLL_init(DLLNode* head, DLLNode* tail) {
	head->next = tail;
	head->prev = NULL;

	tail->next = NULL;
	tail->prev = head;
}

void DLL_printC(DLLNode* head, Direction dir, ALLPART m) {
	if (m == ALL) {
		switch (dir) {
		case INVERSE:
			for (; head->next != NULL; head = head->next);
			break;
		case FORWARD:
			for (; head->prev != NULL; head = head->prev);
			break;
		}
	}

	switch (dir) {
	case FORWARD:
		for (; head != NULL; head = head->next) 
			printf("%c ", head->data);
		break;
	case INVERSE:
		for (; head != NULL; head = head->prev) 
			printf("%c ", head->data);
		break;
	}
	printf("\n");
}

void DLL_print(DLLNode* head, DLLNode* tail) {
	DLLNode* curr = head->next;
	for (; curr != tail; curr = curr->next) {
		printf("%c ", curr->data);
	}
	printf("\n");
	for (curr = tail->prev; curr != head; curr = curr->prev) {
		printf("%c ", curr->data);
	}
	printf("\n");
}

DLLNode* DLL_CreateNode(DLL_ElementType data) {
	DLLNode* newnode = (DLLNode*)calloc(1, sizeof(DLLNode));
	if (newnode == NULL) {
		printf("메모리 부족\n");
		return NULL;
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

void DLL_DestroyNode(DLLNode** dnode) {
	free(*dnode);
	*dnode = NULL;
}

DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data) {
	if (head == NULL || tail == NULL) return NULL;
	if (head->next == NULL || tail->prev == NULL) return NULL;

	head = head->next;
	for (; head != tail && head != NULL; head = head->next) {
		if (head->data == data) return head;
	}
	printf("%c 를 찾을 수 없습니다.\n", data);
	return NULL;
}

void DLL_RemoveNode(DLLNode* rnode) {
	rnode->prev->next = rnode->next;
	rnode->next->prev = rnode->prev;

	DLL_DestroyNode(&rnode);
}

DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos) {
	if (head == NULL || tail == NULL) return NULL;
	if (head->next == NULL || tail->prev == NULL) return NULL;

	DLLNode* curr = head->next;
	for (; curr != NULL && curr != tail; curr = curr->next, --pos) {
		if (pos == 0) break;
	}

	if (curr == NULL) return NULL; // 링크드 리스트가 중간에 끊김

	if (pos > 0) {
		printf("out of range\n");
		return NULL;
	}
	return curr;
}

void DLL_InsertIndex(DLLNode*head, DLLNode*tail, DLLNode* newnode, int pos) {
	DLLNode* temp;
	temp = DLL_GetAt(head, tail, pos);
	if (temp == NULL) {
		printf("Can't insert : %c\n", newnode->data);
		return;
	}
	DLL_InsertBefore(temp, newnode);
}

void DLL_InsertAfter(DLLNode* temp, DLLNode* newnode) {
	if (temp == NULL || newnode == NULL) return;
	newnode->prev = temp;
	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
}

void DLL_InsertBefore(DLLNode* next, DLLNode* newnode) {
	if (next == NULL) return;

	DLLNode* prev = next->prev;

	newnode->prev = prev;
	newnode->next = next;

	prev->next = newnode;
	next->prev = newnode;
}