#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define size_ary(x) (sizeof(x) / sizeof((x)[0])

#if 0

#define A(a) A##a
int main(void) {
	int A1 = 4 , A2 = 5;
	printf("%d", A(1) + A(2));
	return 0;
}
#endif


#if 0
#define string(x) printf(#x" is %d\n", x)
#define charr(x) printf("%c is %c\n", #@x, x);
#define concat(x, i) printf("c%s is %d\n", #i, x##i)

int main(void) {
	int s = 10, c = 97, ca = 7, cb = 9;
	string(s);
	charr(c);
	concat(c, a);
	concat(c, b);
	return 0;
}
#endif

#if 0
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x ## y)
int main(void) {
	int a1, a2;
	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 - a1);
	return 0;
}
#endif

#if 0
#define NDEBUG
#include <assert.h>

int main(void) {
	int x;
	printf("\nEnter an inteager value: ");
	(void)scanf_s("%d", &x);
	assert(x >= 0);
	printf("Ypu entered %d.", x);
	return 0;
}
#endif

#if 0
#include "point.h"
#include "line.h"
#include "a.h"
#include "b.h"

void print_a(void);
static int x = 10;
int count = 0;

extern int a;

int main(void) {
	printf("main.c x     : %d\n", x);
	printf("main.c count : %d\n", count);
	print_a();
	a++;
	print_a();
	print_b();

	return 0;
}

#endif