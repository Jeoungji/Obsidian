#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#if 0
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int M, N;
int** map;
int Evennum = 0;

typedef struct Data {
	int y, x;
	int day;
} Data;

typedef struct Node {
	Data data;
	struct Node* next;
} Node;

// Queue Data
Node* head = NULL;
Node* tail = NULL;
int empty = 0;
// End Queue Data

// Queue Function
Node* CreateNode(int y, int x, int day);
void Push(Node* newdata);
Data Front();
void Pop();
void ClearQueue();
// End Queue Function

void ReadData();
void ClearData();
void PrintData();
int BFS();


void solution(void) {
	ReadData();
	printf("%d\n", BFS());
	ClearQueue();
	ClearData();
}

// Queue Function
Node* CreateNode(int y, int x, int day) {
	Node* newdata = (Node*)malloc(sizeof(Node));
	newdata->data.y = y;
	newdata->data.x = x;
	newdata->data.day = day;
	newdata->next = NULL;

	return newdata;
}

void Push(Node* newdata) {
	if (head == NULL && tail == NULL) {
		head = newdata;
	}
	else {
		tail->next = newdata;
	}
	tail = newdata;
	empty++;
	return;
}

Data Front() {
	Data ret = { -1,-1, -1 };
	if (head == NULL) return ret;

	ret.x = head->data.x;
	ret.y = head->data.y;
	ret.day = head->data.day;
	return ret;
}

void Pop() {
	if (head == NULL) return;

	Node* del = head;
	head = head->next;
	if (head == NULL) tail = NULL;
	--empty;
	free(del);
}

void ClearQueue() {
	while (empty) Pop();
}
// End Queue Function


void ReadData() {
	(void)scanf("%d %d", &M, &N);
	map = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; ++i) {
		map[i] = (int*)malloc(sizeof(int) * M);
		for (int j = 0; j < M; ++j) {
			(void)scanf("%d", map[i] + j);
			if (map[i][j] == 1) {
				Push(CreateNode(i, j, 0));
			}
			else if (map[i][j] == 0) ++Evennum;
		}
	}
}

//void ReadData2() {
//	(void)scanf("%d %d", &M, &N);
//
//	map = (int**)calloc(N, sizeof(int*));
//	int* temp = (int*)calloc(N * M, sizeof(int));
//
//	for (int i = 0; i < N; ++i) {
//		map[i] = temp + (i * N);
//	}
//}

void ClearData() {
	for (int i = 0; i < N; ++i) {
		free(map[i]);
	}
	free(map);
	map = NULL;
	Evennum = 0;
}

void PrintData() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int BFS() {
	int day = 0;

	while (empty) {
		Data cur = Front(); Pop();
		day = cur.day;
		for (int dir = 0; dir < 4; ++dir) {

			int y = cur.y + dy[dir];
			int x = cur.x + dx[dir];
			if (y < 0 || y >= N || x < 0 || x >= M) continue;
			if (map[y][x] != 0) continue;

			map[y][x] = cur.day + 1;
			Push(CreateNode(y, x, cur.day + 1));
			--Evennum;
		}
	}
	if (Evennum != 0) return -1;
	return day;
}

int main(void) {

#ifdef _MSC_VER
	int testnum = 0;
	(void)freopen("tomato_testcase.txt", "r", stdin);
	(void)scanf("%d", &testnum);
	getchar();
	for (int i = 1; i <= testnum; ++i) {
		printf("Case %d\n", i);
#endif
		solution();
#ifdef _MSC_VER
		printf("\n");
	}
#endif
	return 0;
}

#endif