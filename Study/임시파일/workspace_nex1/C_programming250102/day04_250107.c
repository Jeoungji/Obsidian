#include <stdio.h>

#if 0
int main(void) {
	int a = 0;
	printf("%d  : %p\n", a, &a);

	int ap;
	scanf("%x", &ap);
	printf("%p\n", ap);
	int* apv;
	apv = ap;
	*apv = 10;
	printf("%d\n", a);
	
	float* ad;
	ad = ap;
	*ad = 0.5;
	printf("%d\n", a);
	return 0;
}
#endif

// SWAP
#if 0
void swap(int* a1, int* a2) {
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
	return;
}

int main(void) {
	int num1;
	int num2;
	scanf_s("%d %d", &num1, &num2);
	printf("orig : num1=%d, num2=%d\n", num1, num2);
	swap(&num1, &num2);
	printf("swap : num1=%d, num2=%d\n", num1, num2);
	return 0;
}
#endif

// 계산기
#if 0
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int divi(int a, int b) {
	if (b == 0) return 0x7FFFFFFF;
	return a / b;
}

int non(int a, int b) {
	return 0;
}

int main(void) {
	int a;
	int b;
	char car;
	int(*calc[6])(int, int) = {mul, add, non, sub, non, divi};

	while (1) {
		a = 0; b = 0; car = 43;
		printf("연산식을 입력하세요.\n");
		scanf("%d %c %d", &a, &car, &b);

		printf("결과 : %d\n", calc[car-42](a, b));

		printf("종료시 0 입력, 진행시 0 입력\n");
		char num;
		scanf(" %c", &num);
		if (num == '0') break;
	}
	return 0;
}
#endif

// 계산기
#if 0
int add(int a, int b) {	return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int divi(int a, int b) {
	if (b == 0) return 0x7FFFFFFF;
	return a / b;
}

int selctCalc(void) {
	printf("+-------------------------+\n");
	printf("| [1] 더하기              |\n");
	printf("| [2] 빼기                |\n");
	printf("| [3] 곱하기              |\n");
	printf("| [4] 나누기              |\n");
	printf("| [5] 종료                |\n");
	printf("+-------------------------+\n");

	int result;
	scanf("%d", &result);
	if (result < 1 || result > 4) result = 5;
	return result;
}

int main(void) {
	int a;
	int b;
	int(*calc[4])(int, int) = { add, sub, mul, divi };

	while (1) {
		int car = selctCalc();
		if (car == 5) break;
		
		printf("num1 : ");
		scanf("%d", &a);
		printf("num2 : ");
		scanf("%d", &b);

		printf("결과 : %d\n", calc[car-1](a, b));
	}
	return 0;
}
#endif

// 2차원 배열을 1차원 배열로 사용
#if 0
int main(void) {
	int a[3][4] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12 };

	int* p = a;
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *(p + i));
	}
	printf("\n");

	int* p1 = (int *)a;
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *(p1 + i));
	}
	printf("\n");

	int* p4 = a[0];
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *(p4 + i));
	}
	printf("\n");

	int* p2 = (int*)a[0];
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *(p2 + i));
	}
	printf("\n");

	int* p3 = &a[0][0];
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *(p3 + i));
	}
	printf("\n");

	int* p5 = a[0];
	for (int i = 0; i < 12; ++i) {
		printf("%d ", p5[i]);
	}
	printf("\n");

	for (int i = 0; i < 12; ++i) {
		printf("%d ", ((int*)a)[i]);
	}
	printf("\n");

	for (int i = 0; i < 12; ++i) {
		printf("%d ", *((int*)a+i));
	}
	printf("\n");

	for (int i = 0; i < 12; ++i) {
		printf("%d ", (*a)[i]);
	}
	printf("\n");

	int* p6 = (int*)a;
	for (int i = 0; i < 12; ++i) {
		printf("%d ", p6++[0]);
	}
	printf("\n");

	int* p7 = (int*)a;
	for (int i = 0; i < 12; ++i) {
		printf("%d ", *p7++);
	}
	printf("\n");

	return 0;
}
#endif

#if 0
#include <string.h>

int my_strlen(char* str) {
	char *start = str;
	while (*(str++));
	return (str - start) - 1;
}

int my_strlen3(char* str) {
	char* start = str;
	while (*(str++));
	return (str - start) - 1;
}

int my_strlen2(char* str) {
	if (!(*str)) return 0;
	return my_strlen2(str+1) + 1;
}

int my_strcpy(char* str, char* dst, int dst_len) {
	for (int i = 0; i < dst_len; ++i) {
		*dst = *str;
		if (!*str) return 1;
		dst++;
		str++;
	}
	return 0;
}

int main(void) {
	//char str[] = "Good Morning!";
	char str[100] = { 0 };
	scanf_s("%s", str, 100);
	printf("%s은 %d글자 입니다.\n", str, my_strlen(str));
	
	char dst[100];
	my_strcpy(str, dst, 100);
	printf("dst : %s\n", dst);
}
#endif

#if 0
int scanf_ary(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		(void)scanf("%d", arr++);
	return 0;
}

int print_ary(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", *arr++);
	printf("\n");
	return 0;
}

int findmax_ary(int* arr, int size) {
	int n = *arr;
	for (int i = 0; i < size; ++i) {
		if (n < *arr) n = *arr;
		arr++;
	}
	return n;
}

int findmin_ary(int* arr, int size) {
	int n = *arr;
	for (int i = 0; i < size; ++i) {
		if (n > *arr) n = *arr;
		arr++;
	}
	return n;
}

int sum_ary(int* arr, int size) {
	int ret = 0;
	for (int i = 0; i < size; ++i)
		ret += *arr++;
	return ret;
}

int avg_ary(int* arr, int size) {
	if (!size) return 0;
	return sum_ary(arr, size) / size;
}

int var_ary(int* arr, int size, int ddof) {
	if (size < 2) return 0;
	int avg = avg_ary(arr, size);
	int ret = 0;
	for (int i = 0; i < size; ++i) {
		ret += (*arr - avg) * (*arr++ - avg);
	}
	return ret / (size - ddof);
}

int var_ddof0_ary(int* arr, int size) {
	return var_ary(arr, size, 0);
}

int var_ddof1_ary(int* arr, int size) {
	return var_ary(arr, size, 1);
}

int sort_ary(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}

int menu(void) {
	printf("Select...\n");
	printf("+---------------------------+\n");
	printf("| [1] Write                 |\n");
	printf("| [2] Print                 |\n");
	printf("| [3] FindMax               |\n");
	printf("| [4] FindMin               |\n");
	printf("| [5] Sum                   |\n");
	printf("| [6] Avg                   |\n");
	printf("| [7] Var doff 0            |\n");
	printf("| [8] Var doff 1            |\n");
	printf("| [0] Exit                  |\n");
	printf("+---------------------------+\n");
	char num;
	(void)scanf(" %c", &num);
	if (num < '1' || num > '8') num = '0';
	return num;
}

int main(void) {
	int a[5] = { -1, -2, -3, -4, -5 };
	int size = sizeof(a) / sizeof(a[0]);
	int (*calc[8])(int*, int) = { scanf_ary, print_ary, findmax_ary, findmin_ary, sum_ary, avg_ary, var_ddof0_ary, var_ddof1_ary };

	for (;;) {
		char men = menu();
		if (men == '0') break;
		printf("%d\n", calc[men - 0x31](a, size));
	}
	return 0;
}
#endif

#if 0
int my_gets(char* str, int size) {
	int i = 0;
	for (; i < size-1; ++i) {
		*str = (char)getchar();
		if (*str++ == '\n') break;
	}
	*str = NULL;
	return i;
}

int main(void) {
	char str[10] = { 0 };
	if (my_gets(str, sizeof(str))) printf("%s", str);

	if (my_gets(str, sizeof(str))) printf("%s", str);
}
#endif

#if 0
int A(int num1, int num2) {
	return num1 + num2;
}

double B(int num1, int num2) {
	return (double)num1 / num2;
}

int main(void) {
	void (*a[2])(int, int) = { A, B};

	int (*ai)(int, int) = a[0];
	double (*ad)(int, int) = a[1];

	int r1 = ai(1, 2);
	double r2 = ad(1, 2);
	printf("%d  %lf\n", r1, r2);
}
#endif

#if 0
int main(void) {
	int a = 5;
	double b = 10.;

	int* ap = &a;		// 0x0053FD7C
	double* bp = &b;	// 0x0053FD6C
						// delta = 0x10(16)

	printf("ap : %p\nbp : %p\nbp - ap : %d\n", ap ,bp, bp - ap); // double 단위
	// bp - ap : -2
	printf("ap : %p\nbp : %p\nap - bp : %d\n", ap, bp, ap - bp); // int 단위
	// ap - bp : 4
	
	// 피 포인터의 자료형을 따라감
}
#endif