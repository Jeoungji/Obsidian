#pragma once

typedef int ElementType;

#ifndef __STRUCT_NODE__
#define __STRUCT_NODE__
typedef struct _node {
	ElementType Data;
	struct _node* next;
} Node;
#endif

void SLL_print(Node* haed);
Node* SLL_CreateNode(ElementType data);
void SLL_DestroyNode(Node** dnode);
void SLL_AppendNode(Node** head, Node* newnode);
void SLL_RemoveNode(Node** head, ElementType value);
void SLL_Insert(Node** head, Node* newnode, int pos);