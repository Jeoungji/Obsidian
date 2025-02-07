#pragma once

typedef int ElementType;

#ifndef __STRUCT_NODE__
#define __STRUCT_NODE__
typedef struct _node {
	ElementType Data;
	struct _node* next;
} Node;
#endif

typedef struct SLL_3 {
	Node head;
	int size;
	void (*print)(int );
}SSL3;

void SLL_init(SSL3* header);

//void print(void);
//Node* CreateNode(ElementType data);
//void DestroyNode(Node** dnode);
//void AppendNode(Node* head, Node* newnode);
//void RemoveNode(Node* head, ElementType value);
//void Insert(Node* head, Node* newnode, int pos);