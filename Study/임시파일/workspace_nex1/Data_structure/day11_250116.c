#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SLL.h"
#include "SLL2.h"

#define _CRT_SECURE_NO_WARNINGS

// Create_SLL_Node, print_SLL Ȯ�� �ڵ�
#if 0

int main(void) {
	Node* head = NULL;
	Node* a;
	Node* b;
	Node* c;

	a = SLL_CreateNode(100);
	b = SLL_CreateNode(200);
	c = SLL_CreateNode(300);
	head = a;
	a->next = b;
	b->next = c;

	SLL_print(head);
	
	SLL_DestroyNode(&a);
	SLL_DestroyNode(&b);
	SLL_DestroyNode(&c);

	return 0;
}

#endif


#if 0

int main(void) {
	Node* head = NULL;

	SLL_AppendNode(&head, SLL_CreateNode(100));
	SLL_AppendNode(&head, SLL_CreateNode(200));
	SLL_AppendNode(&head, SLL_CreateNode(300));
	
	SLL_print(head);

	SLL_RemoveNode(&head, 100);
	SLL_print(head);
	SLL_RemoveNode(&head, 300);
	SLL_print(head);
	SLL_RemoveNode(&head, 400);
	SLL_print(head);
	SLL_RemoveNode(&head, 200);
	SLL_print(head);

	return 0;
}
#endif

#if 0
int main(void) {
	Node* head = NULL;

	SLL_AppendNode(&head, SLL_CreateNode(100));
	SLL_AppendNode(&head, SLL_CreateNode(200));
	SLL_AppendNode(&head, SLL_CreateNode(300));
	SLL_AppendNode(&head, SLL_CreateNode(400));
	SLL_AppendNode(&head, SLL_CreateNode(500));

	SLL_print(head);

	SLL_Insert(&head, SLL_CreateNode(50), 0);
	SLL_print(head);

	SLL_Insert(&head, SLL_CreateNode(1000), 6);
	SLL_print(head);

	SLL_Insert(&head, SLL_CreateNode(1234), 3);
	SLL_print(head);

	return 0;
}
#endif

#if 0
int main(void) {
	Node head = { 0, NULL };
	SLL2_print(&head);

	SLL2_AppendNode(&head, SLL2_CreateNode(100));
	SLL2_AppendNode(&head, SLL2_CreateNode(200));
	SLL2_AppendNode(&head, SLL2_CreateNode(300));
	SLL2_AppendNode(&head, SLL2_CreateNode(400));
	SLL2_AppendNode(&head, SLL2_CreateNode(500));

	SLL2_print(&head);

	SLL2_Insert(&head, SLL2_CreateNode(50), 0);
	SLL2_print(&head);

	SLL2_Insert(&head, SLL2_CreateNode(1000), 6);
	SLL2_print(&head);

	SLL2_Insert(&head, SLL2_CreateNode(2000), 8);
	SLL2_print(&head);

	SLL2_Insert(&head, SLL2_CreateNode(1234), 3);
	SLL2_print(&head);

	SLL2_RemoveNode(&head, 50);
	SLL2_print(&head);
	SLL2_RemoveNode(&head, 300);
	SLL2_print(&head);

	return 0;
}
#endif













#if 0
#include <windows.h>
#include <stdio.h>

int main() {
    MEMORY_BASIC_INFORMATION mbi;
    void* ptr;

    // 1. �ڵ� ���� Ȯ�� (main �Լ� �ּ�)
    VirtualQuery((void*)main, &mbi, sizeof(mbi));
    printf("Code Section:\n");
    printf("  Base Address: %p\n", mbi.BaseAddress);
    printf("  Allocation Base: %p\n", mbi.AllocationBase);
    printf("  Region Size: %zu bytes\n\n", mbi.RegionSize);

    // 2. ���� ���� Ȯ�� (���� ���� �ּ�)
    int stack_var = 0; // ���ÿ� ��ġ�� ����
    VirtualQuery((void*)&stack_var, &mbi, sizeof(mbi));
    printf("Stack Section:\n");
    printf("  Base Address: %p\n", mbi.BaseAddress);
    printf("  Allocation Base: %p\n", mbi.AllocationBase);
    printf("  Region Size: %zu bytes\n\n", mbi.RegionSize);

    // 3. �� ���� Ȯ�� (malloc���� �Ҵ�� �޸�)
    void* heap_var = malloc(1); // ���� ��ġ�� �޸�
    VirtualQuery(heap_var, &mbi, sizeof(mbi));
    printf("Heap Section:\n");
    printf("  Base Address: %p\n", mbi.BaseAddress);
    printf("  Allocation Base: %p\n", mbi.AllocationBase);
    printf("  Region Size: %zu bytes\n\n", mbi.RegionSize);
    free(heap_var); // �޸� ����

    // 4. rodata ���� Ȯ�� (���ڿ� ���ͷ�)
    const char* rodata_var = "Read-only data"; // .rodata ����
    VirtualQuery((void*)rodata_var, &mbi, sizeof(mbi));
    printf("Read-only Data Section:\n");
    printf("  Base Address: %p\n", mbi.BaseAddress);
    printf("  Allocation Base: %p\n", mbi.AllocationBase);
    printf("  Region Size: %zu bytes\n\n", mbi.RegionSize);

    return 0;
}

#endif