#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#if 0
int sum(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	if (((x > 0 && y > 0) || (x < 0 && y < 0)) && (x * y) < 0) 0x7FFFFFFF;
	else if (((x > 0 && y < 0) || (x < 0 && y > 0)) && (x * y) > 0) 0x80000000;
	return x * y;
}
int divi(int x, int y) {
	if (y == 0) return 0x7FFFFFFF;
	return x / y;
}
int mod(int x, int y) {
	if (y == 0) return x;
	return x % y;
}
int main(void) {
	int a = 10, b = 20;
	int tot = 0;
	scanf_s("%d %d", &a, &b);

	int (*func[5])(int, int) = { sum, sub, mul, divi, mod };
	char funcname[5][4] = { "sum", "sub", "mul", "div", "mod" };

	for (int i = 0; i < 5; ++i) {
		int ret = func[i](a, b);
		printf("%s : %d\n", funcname[i], ret);
		tot += ret;
	}
	printf("tot : %d\n", tot);
	return 0;
}
#endif

#if 0
int sum(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	if (((x > 0 && y > 0) || (x < 0 && y < 0)) && (x * y) < 0) 0x7FFFFFFF;
	else if (((x > 0 && y < 0) || (x < 0 && y > 0)) && (x * y) > 0) 0x80000000;
	return x * y;
}
int divi(int x, int y) {
	if (y == 0) return 0x7FFFFFFF;
	return x / y;
}
int mod(int x, int y) {
	if (y == 0) return x;
	return x % y;
}
int pow(int x, int y) {
	int ret = 1;
	for (int i = 0; i < y; ++i) ret *= x;

	if (y % 2) { // 홀수 승
		if (x < 0 && ret > 0) { // 언더플로우
			ret = 0x80000000;
			printf("underflow");
		}
		else if (x > 0 && ret < 0) { // 오버플로우
			ret = 0x7FFFFFFF;
			printf("overflow");
		}
	}
	else { // 짝수 승
		if (ret < 0) { // 오버플로우
			ret = 0x7FFFFFFF;
			printf("overflow");
		}
	}
	
	return ret;
}

struct my_ops {
	const char* const op_name;
	int(* const op) (int, int);
	int ret;
};

struct my_ops arr[] = {
	{"sum", sum, 0},
	{"sub", sub, 0},
	{"mul", mul, 0},
	{"div", divi, 0},
	{"mod", mod, 0},
	{"pow", pow, 0}
};

int main(void) {
	int a = 10, b = 20;
	int tot = 0;
	scanf_s("%d %d", &a, &b);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		arr[i].ret = arr[i].op(a, b);
		printf("%s : %d\n", arr[i].op_name, arr[i].ret);
		tot += arr[i].ret;
	}
	printf("tot : %d\n", tot);

	return 0;
}
#endif

#if 0
void sort_arr(int* arr, int size, int (*comp)(int, int)) {
	int temp;

	for (int i = 0; i < size - 1; ++i) {
		for (int j =i+1; j < size; ++j) {
			if (comp(arr[i], arr[j])) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		 }
	}
	return;
}

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int Up(int a, int b) {
	if (a < b) return 0;
	return 1;
}

int Down(int a, int b) {
	if (a > b) return 0;
	return 1;
}

#define SIZEARR(x) sizeof(x)/sizeof((x)[0])

int main(void) {
	int arr[] = { 8,5,2,12,7,9,4,6,10,3 };

	print_arr(arr, SIZEARR(arr));

	sort_arr(arr, SIZEARR(arr), Up);
	print_arr(arr, SIZEARR(arr));

	sort_arr(arr, SIZEARR(arr), Down);
	print_arr(arr, SIZEARR(arr));
	
	return 0;
}
#endif

#if 0
#define SIZEARR(x) (sizeof(x)/sizeof(x)[0])

void PrintIntAry(int* arr, int n);
void PrintDoubleAry(double* arr, int n);
void PrintStringAry(char** arr, int n);

int CompIntAsc(const void* a, const void* b);
int CompIntDesc(const void* a, const void* b);
int CompDoubleAsc(const void* a, const void* b);
int CompDoubleDesc(const void* a, const void* b);
int CompStringAsc(const void* a, const void* b);
int CompStringDesc(const void* a, const void* b);

int main(void) {
	int arr[] = { 3, 5, 2, 6, 1, 9, 4 };
	PrintIntAry(arr, SIZEARR(arr));

	qsort(arr, SIZEARR(arr), sizeof(arr[0]), CompIntAsc);
	PrintIntAry(arr, SIZEARR(arr));

	qsort(arr, SIZEARR(arr), sizeof(arr[0]), CompIntDesc);
	PrintIntAry(arr, SIZEARR(arr));

	double arr2[] = { 3.14, 5.89, 3.53, 3.45, 1.89,9.6,9.58 };
	PrintDoubleAry(arr2, SIZEARR(arr2));

	qsort(arr2, SIZEARR(arr2), sizeof(arr2[0]), CompDoubleAsc);
	PrintDoubleAry(arr2, SIZEARR(arr2));

	qsort(arr2, SIZEARR(arr2), sizeof(arr2[0]), CompDoubleDesc);
	PrintDoubleAry(arr2, SIZEARR(arr2));

	char* animal[] = { "dog", "cat", "tiger" };
	PrintStringAry(animal, SIZEARR(animal));

	qsort(animal, SIZEARR(animal), sizeof(animal[0]), CompStringAsc);
	PrintStringAry(animal, SIZEARR(animal));

	qsort(animal, SIZEARR(animal), sizeof(animal[0]), CompStringDesc);
	PrintStringAry(animal, SIZEARR(animal));

	return 0;
}

void PrintIntAry(int* arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void PrintDoubleAry(double* arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%.2lf ", arr[i]);
	}
	printf("\n");
}
void PrintStringAry(char** arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%s ", arr[i]);
	}
	printf("\n");
}
int CompIntAsc(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int CompIntDesc(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}
int CompDoubleAsc(const void* a, const void* b) {
	double ret = *(double*)a - *(double*)b;
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}
int CompDoubleDesc(const void* a, const void* b) {
	double ret = *(double*)a - *(double*)b;
	if (ret > 0) return -1;
	else if (ret < 0) return 1;
	return 0;
}
int CompStringAsc(const void* a, const void* b) {
	//char* ap = (char*)a;
	//char* bp = (char*)b;
	//while (*ap == *bp) {
	//	if (*ap == 0) return 0;
	//	ap++;
	//	bp++;
	//}
	//return( *bp - *ap);

	 return strcmp(*(char**)a, *(char**)b);
}
int CompStringDesc(const void* a, const void* b) {
	char* ap = (char*)a;
	char* bp = (char*)b;
	while (*ap == *bp) {
		if (*ap == 0) return 0;
		ap++;
		bp++;
	}
	return(*ap- *bp);
}
#endif

// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환
#if 0

int* input_data(int N) {
	int* temp = 0;
	int i;
	temp = (int*)malloc(N * sizeof(int));
	if (temp == NULL) {
		return NULL;
	}
	for (i = 0; i < N; i++) {
		(void)scanf("%d", temp + i);
	}
	return temp;
}
void print_data(int* data, int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main(void) {
	int* pi = 0;
	int loopCnt, N;

	(void)freopen("numbers2.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);
	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL;
	}
	return 0;
}
#endif

// (정수 N개를 저장할 공간을 할당 받아 그 공간에 입력 받고), 출력, 메모리 반환
#if 0

int (*input_data(int N))[4] {
	int(* temp)[4] = 0;
	int i;

	temp = (int(*)[4])malloc(N * sizeof(*temp));
	if (temp == NULL) {
		return NULL;
	}
	for (i = 0; i < N; i++) {
		for (int j = 0; j < 4; ++j) {
			(void)scanf("%d", &temp[i][j]);
		}
	}
	return temp;
}
void print_data(int(* data)[4], int N) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < 4; ++j) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(void) {
	int(* pi)[4] = 0;
	int loopCnt, N;

	(void)freopen("numbers3.txt", "r", stdin);
	(void)scanf("%d", &loopCnt);
	for (int i = 0; i < loopCnt; i++) {
		(void)scanf("%d", &N);
		pi = input_data(N);
		if (pi == NULL) {
			printf("메모리 부족");
			exit(1);
		}
		print_data(pi, N);
		free(pi);
		pi = NULL;
	}
	return 0;
}
#endif

#if 0
char** InitData(char*** str_, int* N);
void PrintData(char** str, int N);
void FreeAll(char** str, int N);

int main(void) {
	char** str = NULL;
	int N = 0;

	(void)freopen("data.txt", "r", stdin);
	
	InitData(&str, &N);

	PrintData(str, N);

	FreeAll(str, N);

	N = 0;
	str = NULL;

	return 0;
}

char** InitData(char*** str_, int* N) {
	int i, n;
	char** str;
	char temp[80];

	(void)scanf_s("%d ", &n);

	str = (char**)calloc(n, sizeof(char*));
	if (str == NULL) {
		printf("메모리 부족\n");
		exit(0);
	}
	for (i = 0; i < n; ++i) {
		printf("문자열 입력 : ");
		(void)fgets(temp, sizeof(temp), stdin);
		printf("%s", temp);

		str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
		if (str[i] == NULL) {
			printf("메모리 부족\n");
			for (int j = 0; j < i; ++j) free(str[j]);
			free(str);
			exit(0);
		}
		strcpy(str[i], temp);
	}
	*N = n;
	*str_ = str;
	return str;
}

void PrintData(char** str, int N) {
	for (int i = 0; i < N; ++i) {
		printf("%s", *(str + i));
	}
}

void FreeAll(char** str, int N) {
	for (int i = 0; i < N; ++i) {
		free(str[i]);
	}
	free(str);
}
#endif

#if 0
struct profile {
	int age;
	int height;
	char *name;
};
typedef struct student {
	struct profile pf;
	double grade;
	int num;
} student_t;


int main(void) {
	student_t s1 = { {20, 160, "hong"}, 1, 4.2 };
	s1.pf.name= "hong";
	s1.pf.age = 18;
	s1.pf.height = 187;
	s1.grade = 2.7;
	s1.num = 2;
	student_t* s2 = &s1;
	
	printf("이름 : %s\n", s1.pf.name);
	printf("나이 : %d\n", s1.pf.age);
	printf("키 : %d\n", s1.pf.height);
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.2lf\n\n", s1.grade);

	printf("이름 : %s\n", s2->pf.name);
	printf("나이 : %d\n", s2->pf.age);
	printf("키 : %d\n", s2->pf.height);
	printf("학번 : %d\n", s2->num);
	printf("학점 : %.2lf\n\n", s2->grade);
	

	return 0;
}
#endif

#if 0
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))

struct student {
	int id;
	int scores[3];
	char name[20];
};

void input_data(struct student *stu, int size);
void print_data(struct student *stu, int size);

int main(void) {
	struct student stu[5] = { 0 };
	(void)freopen("student.txt", "r", stdin);

	input_data(stu, size_ary(stu));
	print_data(stu, size_ary(stu));
}

void input_data(struct student *stu, int size) {
	struct student* local;
	for (int i = 0; i < size; ++i) {
		local = stu + i;

		(void)scanf_s("%d", &local->id);
		for (int j = 0; j < size_ary(local->scores); ++j)
			(void)scanf_s("%d", local->scores+j); // (void)scanf_s("%d", &local->scores[j]);
		(void)scanf(" %s", &local->name);
	}
}
void print_data(struct student *stu, int size) {
	int i, j;
	struct student *s;
	for (i = 0; i < size; ++i) {
		s = stu + i;

		printf("id : %d\n", s->id);
		printf("scores : ");
		for (j = 0; j < size_ary(s->scores); ++j)
			printf("%d ", s->scores[j]);
		printf("\nname : %s\n\n", s->name);
	}
}
#endif

#if 0
typedef struct {
	unsigned int blue : 5;
	unsigned int green : 5;
	unsigned int red : 5;
} color1;

typedef struct {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} color2;

int main(void) {
	color1 a = { 0 };
	a.red = 512;
	printf("%d\n", sizeof(color1));
	printf("%d %d %d\n",a.blue, a.green, a.red);
}
#endif