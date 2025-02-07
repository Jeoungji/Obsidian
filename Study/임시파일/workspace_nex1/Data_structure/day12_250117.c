#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#if 0
#include "DLL.h"

int main(void) {
	DLLNode head = {0 };
	DLLNode tail = {0};
	
	DLL_init(&head, &tail);

	DLL_InsertBefore(&tail, DLL_CreateNode('A'));
	DLL_InsertBefore(&tail, DLL_CreateNode('B'));
	DLL_InsertBefore(&tail, DLL_CreateNode('C'));
	DLL_printC(&head, FORWARD, ALL);

	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'A'));
	DLL_printC(&head, FORWARD, ALL);

	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'B'));
	DLL_printC(&head, FORWARD, ALL);

	DLL_RemoveNode(DLL_FindNode(&head, &tail, 'C'));
	DLL_printC(&head, FORWARD, ALL);

	DLL_InsertBefore(&tail, DLL_CreateNode('A'));
	DLL_InsertBefore(&tail, DLL_CreateNode('B'));
	DLL_InsertBefore(&tail, DLL_CreateNode('C'));
	DLL_printC(&head, FORWARD, ALL);

	for (int i = 0; i < 4; ++i) {
		DLLNode* ret = DLL_GetAt(&head, &tail, i);
		if (ret != NULL) printf( "%c\n", ret->data);
	}

	DLL_InsertIndex(&head, &tail, DLL_CreateNode('0'), 0);
	DLL_printC(&head, FORWARD, ALL);
	DLL_InsertIndex(&head, &tail, DLL_CreateNode('0'), 4);
	DLL_printC(&head, FORWARD, ALL);

	DLL_InsertAfter(DLL_GetAt(&head, &tail, 0), DLL_CreateNode('9'));
	DLL_printC(&head, FORWARD, ALL);

	return 0;
}

#endif

#if 0
int N; // 2 - 10
int nums[10];

void toBinary(int num_) {
	int local_n = num_;
	for (int i = N - 1; i >= 0; --i) {
		printf("%d ", (local_n >> i) & 0x1);
	}
	printf("\n");
}
void make_nums(int L) {
	if (L >= N) {
		for (int i = 0; i < N; ++i) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		return;
	}
	nums[L] = 0;
	make_nums(L + 1);
	nums[L] = 1;
	make_nums(L + 1);
}

int main(void) {
	(void)scanf_s("%d", &N);

	make_nums(0);
	return 0;
}
#endif

// Queue
#if 0

#define SIZE (5)
typedef int ElementType;
ElementType Queue[SIZE];
int front, rear;

void printQueue(int front, int rear);
void enQueue(ElementType data);
ElementType deQueue();

int main(void) {
	front = rear = 0;
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);

	printQueue(front, rear);

	deQueue();
	printQueue(front, rear);

	return 0;
}

void printQueue(int front, int rear) {
	for (int i = front; i < rear; ++i) printf("%d ", Queue[i]);
	printf("\n");
}

void enQueue(ElementType data) {
	if (rear == SIZE) return;
	Queue[rear++] = data;

}

ElementType deQueue() {
	if (front == rear) return;

	return Queue[front++];
}
#endif

// 원형 Queue
#if 0

#define SIZE (5 + 1)
typedef int ElementType;
ElementType Queue[SIZE];
int front, rear;

void printQueue(int front, int rear);
void enQueue(ElementType data);
ElementType deQueue();

int main(void) {
	front = rear = 0;
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(4);
	enQueue(4);
	enQueue(4);

	printQueue(front, rear);

	deQueue();
	printQueue(front, rear);
	deQueue();
	printQueue(front, rear);
	deQueue();
	printQueue(front, rear);

	return 0;
}

void printQueue(int front, int rear) {
	for (int i = front; i < rear; ++i % SIZE) {
		printf("%d ", Queue[i]);
	}
	printf("\n");
}

void enQueue(ElementType data) {
	if ((rear + 1) % SIZE == front) {
		printf("Full Queue\n");
		return;
	}
	Queue[rear] = data;
	rear = (rear + 1) % SIZE;
}

ElementType deQueue() {
	ElementType ret;
	if (front == rear) return;

	ret = Queue[front];
	front = (front++) % SIZE;
	return ret;
}
#endif

#if 0
typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct tagCircularQueue {
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
} CircularQueue;

CircularQueue * CQ_CreateQueue(int capacity);
void EnQueue(CircularQueue* queue, ElementType data);
ElementType DeQueue(CircularQueue* queue);
void PrintQueue(CircularQueue* queue);


int main(void) {
	CircularQueue* Queue;
	Queue = CQ_CreateQueue(10);

	for (int i = 1; i < 13; ++i)
		EnQueue(Queue, 10*i);

	PrintQueue(Queue);
	for (int i = 0; i < 13; ++i) {
		DeQueue(Queue);
		PrintQueue(Queue);
	}

	return 0;
}

CircularQueue * CQ_CreateQueue(int capacity) {
	CircularQueue* temp;
	temp = (CircularQueue*)calloc(1, sizeof(CircularQueue));
	if (temp == NULL) {
		printf("메모리 부족 1.\n");
		return NULL;
	}
	temp->Nodes = (Node*)calloc(capacity + 1, sizeof(Node));
	temp->Capacity = capacity;
	temp->Front = 0;
	temp->Rear = 0;

	return temp;
}

void EnQueue(CircularQueue *queue, ElementType data) {
	if ((queue->Rear + 1) % (queue->Capacity + 1) == queue->Front) {
		printf("Full\n");
		return;
	}
	queue->Nodes[queue->Rear].Data = data;
	queue->Rear = (queue->Rear + 1) % (queue->Capacity+1);
	printf("push %d\n", data);
}

ElementType DeQueue(CircularQueue* queue) {
	ElementType ret;
	if (queue->Front % (queue->Capacity + 1) == queue->Rear) {
		printf("Empty\n");
		return;
	}

	ret = queue->Nodes[queue->Front].Data;
	queue->Front = (queue->Front + 1) % (queue->Capacity + 1);
	return ret;
}

void PrintQueue(CircularQueue* queue) {
	printf("Queue : ");
	for (int i = queue->Front; (i % (queue->Capacity + 1)) != (queue->Rear); ++i) {
		printf("%d ", queue->Nodes[i].Data);
	}
	printf("\n");
}
#endif

#if 0
typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* next;
}Node;

typedef struct tagListQueue {
	Node* Front;
	Node* Rear;
	int count;
} ListQueue;

ListQueue* LQ_CreateQueue();
Node* LQ_CreateNode(ElementType data);
void EnQueue(ListQueue* queue, Node* newnode);
ElementType DeQueue(ListQueue* queue);
void PrintQueue(ListQueue* queue);


int main(void) {
	ListQueue* Queue;
	Queue = LQ_CreateQueue();

	for (int i = 1 ; i <= 10; ++i)
		EnQueue(Queue, LQ_CreateNode(10*i));

	PrintQueue(Queue);

	printf("dequeue : %d\n", DeQueue(Queue));
	printf("dequeue : %d\n", DeQueue(Queue));
	PrintQueue(Queue);

	return 0;
}

ListQueue* LQ_CreateQueue() {
	ListQueue* temp;
	temp = (ListQueue*)calloc(1, sizeof(ListQueue));
	if (temp == NULL) {
		printf("메모리 부족 1.\n");
		return NULL;
	}
	temp->Front = NULL;
	temp->Rear = NULL;
	temp->count = 0;
	return temp;
}

Node* LQ_CreateNode(ElementType data) {
	Node* temp;
	temp = (Node*)calloc(1, sizeof(Node));
	if (temp == NULL) {
		printf("메모리 부족\n");
		return NULL;
	}
	temp->Data = data;
	temp->next = NULL;
	return temp;
}

void EnQueue(ListQueue* queue, Node* newnode) {
	if (newnode == NULL) 
		return;
	
	if (queue->count == 0)
		queue->Front = newnode;
	else
		queue->Rear->next = newnode;

	queue->Rear = newnode;
	++(queue->count);
}

ElementType DeQueue(ListQueue* queue) {
	if (queue->count == 0) {
		printf("Queue Empty\n");
		return NULL;
	}

	if (queue->count == 1) {
		queue->Rear = NULL;
	}
	ElementType ret = queue->Front->Data;
	queue->Front = queue->Front->next;
	queue->count -= 1;
	
	return ret;
}

void PrintQueue(ListQueue* queue) {
	printf("Queue : ");
	Node* curr = queue->Front;
	for (; curr != NULL; curr = curr->next) {
		printf("%d ", curr->Data);
	}
	printf("\n");
}
#endif