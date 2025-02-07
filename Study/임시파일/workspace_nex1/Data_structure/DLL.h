#pragma once

typedef char DLL_ElementType;

#ifndef __STRUCT_DLLNODE__
#define __STRUCT_DLLNODE__
typedef struct _dllnode {
	DLL_ElementType data;
	struct _dllnode* prev;
	struct _dllnode* next;
} DLLNode;
#endif

typedef enum Direction{
	FORWARD,
	INVERSE
}Direction;

typedef enum ALLPART {
	ALL,
	PART
}ALLPART;

void DLL_init(DLLNode* head, DLLNode* tail);
void DLL_printC(DLLNode* head, Direction dir, ALLPART m);
void DLL_print(DLLNode* head, DLLNode* tail);
DLLNode* DLL_CreateNode(DLL_ElementType data);
void DLL_DestroyNode(DLLNode** dnode);

DLLNode* DLL_FindNode(DLLNode* head, DLLNode* tail, DLL_ElementType data);
void DLL_RemoveNode(DLLNode* rnode);
DLLNode* DLL_GetAt(DLLNode* head, DLLNode* tail, int pos);
void DLL_InsertIndex(DLLNode* head, DLLNode* tail, DLLNode* newnode, int pos);
void DLL_InsertAfter(DLLNode* temp, DLLNode* newnode);
void DLL_InsertBefore(DLLNode* next, DLLNode* newnode);