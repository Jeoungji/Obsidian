#pragma once

typedef int ElementType;

#ifndef __STRUCT_NODE__
#define __STRUCT_NODE__
typedef struct _node {
	ElementType Data;
	struct _node* next;
} Node;
#endif

void SLL2_print(Node* haed);
Node* SLL2_CreateNode(ElementType data);
void SLL2_DestroyNode(Node** dnode);
void SLL2_AppendNode(Node* head, Node* newnode);
void SLL2_RemoveNode(Node* head, ElementType value);
void SLL2_Insert(Node* head, Node* newnode, int pos);