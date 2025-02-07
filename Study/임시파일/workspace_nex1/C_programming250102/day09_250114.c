#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define size_ary(x) (sizeof(x) / sizeof((x)[0])

#if 0
typedef struct student {
	int num;
	int score_num;
	int* score;
	char name[20];
} student;

void intput_data(student** stu, int people, int score_num) {
	student* local = NULL;
	*stu = (student*)malloc(sizeof(student) * people);
	if (*stu == NULL) exit(0);

	for (int i = 0; i < people; ++i) {
		local = (*stu) + i;
		local->score_num = score_num;
		local->score = (int*)malloc(sizeof(int) * score_num);
		if (local->score == NULL) {
			free(local);
			free(*stu);
			exit(0);
		}

		(void)scanf_s(" %d", &(local->num));
		for (int j = 0; j < score_num; ++j) {
			(void)scanf_s(" %d", local->score + j);
		}
		(void)scanf_s("%s", local->name, 20);
	}
}

void print_data(student* stu, int people) {
	for (int i = 0; i < people; ++i) {
		printf("name  : %s\n", stu[i].name);
		printf("num   : %d\n", stu[i].num);
		printf("score : ");
		for (int j = 0; j < stu[i].score_num; ++j) {
			printf("%d ", stu[i].score[j]);
		}
		printf("\n\n");
	}
}

void free_all(student* stu, int people) {
	for (int i = 0; i < people; ++i) {
		free((stu)[i].score);
	}
	free(stu);
}

int main(void) {
	int people = 0;
	int score_num = 0;
	student* students = NULL;

	(void)freopen("student2.txt", "r", stdin);
	(void)scanf_s("%d %d", &people, &score_num);
	//printf("people_num : %d , score_num : %d", people, score_num);

	intput_data(&students, people, score_num);
	print_data(students, people);
	free_all(students, people);
	students = NULL;
	return 0;
}
#endif

#if 0
struct student {
	int num;
	int* scores;
	char name[20];
};
struct student* input_data3(int arySize, int itemCnt);
void print_data3(struct student* stu, int arySize, int itemCnt);
void free_data(struct student* stu, int itemCnt);

int main(void) {
	struct student* stu = { 0 };
	int arySize, itemCnt;
	(void)freopen("student2.txt", "r", stdin);
	(void)scanf("%d %d", &arySize, &itemCnt);
	stu = input_data3(arySize, itemCnt);
	if (stu != NULL) {
		print_data3(stu, arySize, itemCnt);
		free_data(stu, itemCnt);
		stu = NULL;
	}
	return 0;
}

struct student* input_data3(int arySize, int itemCnt) {
	struct student* stu = { 0 };
	struct student* temp = NULL;

	stu = (struct student*)malloc(sizeof(struct student) * arySize);
	if (stu == NULL) {
		printf("No memory for student\n");
		return NULL;
	}
	for (int i = 0; i < arySize; ++i) {
		stu[i].scores = (int*)malloc(sizeof(int) * itemCnt);
		if (stu[i].scores == NULL) {
			printf("No memory for score\n");
			free_data(stu, i);
			return NULL;
		}
	}
	for (int i = 0; i < arySize; ++i) {
		temp = stu + i;
		(void)scanf_s(" %d", &temp->num);
		for (int j = 0; j < itemCnt; ++j) {
			(void)scanf_s(" %d", &temp->scores[j]);
		}
		(void)scanf_s(" %s", temp->name, sizeof(temp->name));
	}
	return stu;
}

void print_data3(struct student* stu, int arySize, int itemCnt) {
	struct student* temp = NULL;
	for (int i = 0; i < arySize; ++i) {
		temp = stu + i;
		printf("%d\n", temp->num);
		for (int j = 0; j < itemCnt; ++j) {
			printf("%d ", temp->scores[j]);
		}
		printf("\n%s\n", temp->name);
	}
}

void free_data(struct student* stu, int itemCnt) {
	if (stu == NULL) return;
	for (int i = 0; i < itemCnt; ++i) {
		free( stu[i].scores);
	}
	free(stu);
}
#endif

#if 0
typedef struct {
	unsigned int a : 3;
	unsigned int b : 3;
	unsigned int c : 3;
} BitF1;

int main(void) {
	BitF1 a = { 0 };
	a.a = 7;
	a.b = 1;
	a.c = 5;
	printf("%d %d %d\n", a.a, a.b, a.c);
	// 4f cd cc cc cc cc cc cc 00 fb b3 00 03 21 16 00 01 00 00 00 a0 a7 ea 00 c8 c4 ea 00 01 00 00 00 a0 a7 ea 00 c8 c4 ea 00 5c fb b3 00 4a 1f 16 00 a9 6e 36 7c 23 10
	printf("%X\n", *(char*)&a);
	printf("%X\n", *((char*)&a+1));
}

#endif

#if 0

typedef struct _IP {
	uint16_t Version : 4;
	uint16_t IHL : 4;
	uint16_t TOS : 8;
	uint16_t Total_Length;
	uint16_t Identification;
	uint16_t IP_Flag_x : 1;
	uint16_t IP_Flag_D : 1;
	uint16_t IP_Flag_M : 1;
	uint16_t Fragment_Offset : 13;
	uint8_t  TTL;
	uint8_t  Protocol;
	uint16_t Header_Checksum;
	uint32_t Source_Address;
	uint32_t Destination_Address;
	uint32_t IP_Option;
} IP_Header;

int main(void) {
	IP_Header header = { 2, 1, 3, 100, 12, 1, 0, 1, 20, 1, 13, 0, 12, 60, 1 };
	header.Header_Checksum = (header.Version + header.IHL + header.TOS
							+ header.Total_Length + header.Identification
							+ header.IP_Flag_x + header.IP_Flag_D + header.IP_Flag_M
							+ header.Fragment_Offset + header.TTL
							+ header.Protocol + header.Source_Address
							+ header.Destination_Address
							+ header.IP_Option) ^ 0xFFFF;
	printf("%X\n", header.Header_Checksum);
}
#endif

#if 0
typedef struct _node {
	int value;
	struct _node* prev;
	struct _node* next;
}node;

int main(void) {
	node a = { 0 }, b = { 0 }, c = { 0 };
	node* head = &a;
	node* tail = &c;
	a.value = 10;
	b.value = 20;
	c.value = 30;
	a.next = &b;
	b.prev = &a;
	b.next = &c;
	c.prev = &b;

	for (node* curr = head; curr != NULL; curr = curr->next) {
		printf("%d ", curr->value);
	}
	printf("\n");
	for (node* curr = tail; curr != NULL; curr = curr->prev) {
		printf("%d ", curr->value);
	}

	return 0;
}
#endif

#if 0
typedef struct trgb {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
}tRGB;

typedef union pixelcolor {
	tRGB rgb;
	unsigned short color;
}tPColor;

int main(void) {
	tPColor dot1 = { 0 }, dot2 = { 0 };

	dot1.color = 0x1234; // 00110100|00010010 (0x34|0x12) 개념 : 00010 010001 10100 (0x02|0x11|0x14)
	dot2.color = 100;
	printf("%d %d\n", sizeof(tRGB), sizeof(tPColor));
	printf("%#x\n", dot1.color);
	printf("%d %#x\n", dot2.color, dot2.color);
	printf("%2d %2d %2d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	printf("%2d %2d %2d\n", dot2.rgb.red, dot2.rgb.green, dot2.rgb.blue);

	dot1.rgb.red = 13;
	dot1.rgb.green = 20;
	dot1.rgb.blue = 25;
	printf("%2d %2d %2d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	printf("%#x\n", dot1.color);

	return 0;
}

#endif

#if 0
typedef int (*int4ap_t)[4];

int4ap_t func(void) {
	static int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	return arr;
}
void print_data(int (*p)[4], int row) {
	int* arr = (int*)p-1;
	for (int j = 0; j < row; ++j) {
		for (int i = 0; i < sizeof(*p) / sizeof(**p); ++i) {
			printf("%d ", *(++arr));
		}
		printf("\n");
	}
}
int main(void) {
	int4ap_t p = 0;
	p = func();
	print_data(p, 3);
	return 0;
}
#endif

#if 0
typedef int(*calc_t)(int, int);

int sum(int a, int b) {
	return a + b;
}
void print_ary(int* arr, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void) {
	void* parr[] = { sum, print_ary };

	int result = ((calc_t)parr[0]) (10, 20);
	printf("%d\n", result);
	return 0;
}
#endif

#if 0
#include "my_arylib.h"

typedef int (*aryop1_t)(int*, int);
typedef double (*aryop2_t)(int*, int);
typedef double (*aryop3_t)(int*, int, int);

enum {
	PrintAry = 1,
	SortAry,
	FindmaxAry,
	FindminAry,
	SumAry,
	AvgAry,
	VarAry
};

int main(void) {
	int ary[5];
	int size = sizeof(ary) / sizeof(*ary);
	int op = 0;
	void* func = NULL;
	void *ary_funcs[] = { 
		0,
		print_ary, 
		sort_ary, 
		findmax_ary, 
		findmin_ary, 
		sum_ary,
		avg_ary,
		var_ary,
		var_ary };

	scanf_ary(ary);
	while (1) {
		
		print_menu();
		(void)scanf(" %d", &op);
		if (op <= 0 || op > 8) break; // break 뒤 else if는 의미가 없다.
		func = ary_funcs[op];

		switch (op) {
		case PrintAry:
		case SortAry:
		case FindmaxAry:
		case FindminAry:
		case SumAry:
			printf("res: %d\n", ((aryop1_t)func)(ary, size));
			break;
		case AvgAry:
			printf("res: %lf\n", ((aryop2_t)func)(ary, size));
			break;
		case VarAry:
			printf("res: %lf\n", ((aryop3_t)func)(ary, size, op - 7));
			break;
		defualt:
			printf("Error: wrong instruction\n");
		}
	}
	printf("Thank you *^-^*\n");
	return 0;
}

#endif

#if 0

#define TC
#undef TC

#ifdef TC
#include <conio.h>
#define MAX_INT 32767
#else
#define MAX_INT 2147483647
#endif

#define ALPHA 1
#if ALPHA
int main(void) {

}
#else 
#error CODE 10000 : holy moly !
#endif

#endif

#if 0
#define SOUND_DEVICE_TYPE 0

int main(void) {
#if !SOUND_DEVICE_TYPE
	printf("ad");
#else
#error code 10 : unknown divice
#endif
	printf("adf");
}
#endif

#if 0

#define Assert(x) { \
	if ((x) >= 4) printf("Range error : %s, %d, %s\n", __FILE__, __LINE__, __FUNCTION__);\
	}

void test(int i);

int main(void) {
	int a[4] = { 10, 20, 30, 40 };
	int i = 0;
	for (i = 0; i <= 4; ++i) {
#line 100
		//Assert(i);
		test(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void test(int i){
	Assert(i);
}
#endif