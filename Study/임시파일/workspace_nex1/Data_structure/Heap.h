#pragma once

typedef int ElementType;
typedef int (*compFunc)(ElementType, ElementType);

typedef struct _htNode {
	ElementType data;
} htNode;

typedef struct _headTree {
	htNode* node;
	int capacity;
	int usesize;
	compFunc comp;
} heapTree;

heapTree* HT_CreateTree(int capacity, compFunc comp);

void HT_SwapNode(htNode* a, htNode* b);

int comp_min(ElementType a, ElementType b);

int comp_max(ElementType a, ElementType b);

void HT_InsertNode(heapTree* tree, ElementType newdata);

htNode HT_PopRoot(heapTree* tree);

void HT_DestroyTree(heapTree* tree);

void HT_PrintTree(heapTree* tree);