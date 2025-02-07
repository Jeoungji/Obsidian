#include <stdio.h>

#if 0
int func(void) {
	int a = 10;
	return a = 20;
}

int main(void) {
	printf("%d",func());
	return 0;
}
#endif

// 한글 이름 생성
#if 0
int main(void) {
	int 한글 = 10;
	printf("%d", 한글);
	return 0;
}
#endif

// char형 변수 선언 및 변수
#if 0
int main(void) {
	char ch1_ = 'A';
	char ch2_ = 65;

	printf("문자 %c의 아스키 코드 값 : %d\n", ch1_, ch1_);
	printf("아스키 코드 값이 %d인 문자 : %c\n", ch2_, ch2_);

	unsigned char uch1 = -1;
	unsigned char uch2 = 128;
	signed char ch1 = -1;
	signed char ch2 = 128;

	printf("unsigned char (%%u) : %u %u\n", uch1, uch2);	// 0xff -> 0x000000ff -> 0xff(255)	0x80 -> 0x00000080 -> 0x80(128)
	printf("signed char (%%d) : %d %d\n", ch1, ch2);		// 0xff -> 0xfffffffff(-1)			0x80 -> 0xffffff80(-128)
}
#endif

#if 0
int main(void) {
	float num = 123456789.0f;
	printf("num : %.1f\n", num);

	float a = 1.234567890123456789f;
	double b = 1.234567890123456789;

	printf("float형 변수 : %.20f\n", a);
	printf("double형 변수 : %.20f\n", b);
}
#endif

// sizeof
#if 0
int main(void) {
	int num = 10;
	int* p = &num;

	printf("%zu %zu\n", sizeof(num), sizeof(p));
	printf("%p %p\n", p, &num);
	printf("%d %d\n", *p, num);
}
#endif

// const
#if 0
int main(void) {
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	double* tax_p = &tax_rate;
	*tax_p = 10;
	// tax_rate = 0.15;
	income = 456;
	tax = income * tax_rate;
	printf("세금은 : %.lf입니다.\n", tax);
	return 0;
}
#endif

// scanf
#if 0
#define _countof(array) (sizeof(array) / sizeof(array[0]))
int main(void) {
	//int age;
	//double height;
	//float weight;

	//scanf("%d %lf %f", &age, &height, &weight);
	//printf("나이 : %d, 키 : %.1f, 몸무게 : %.1f\n", age, height, weight);

	char grade;
	char name[20];

	(void)scanf("%c", &grade);
	scanf_s("%s", name, (unsigned int)_countof(name));
	printf("%s의 학점은 %c입니다.\n", name, grade);
}
#endif

// fgets
#if 0
int main(void) {
	char grade;
	char name[20];

	(void)scanf("%c", &grade);

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (fgets(name, (int)sizeof(name), stdin) != NULL) {
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
	}
	printf("%s의 학점은 %c입니다.\n", name, grade);
}
#endif

#include <string.h>  // strlen
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#if 0
int main(void)
{
	char grade, grade2;
	char name[20];
	(void)scanf(" %c", &grade);
	(void)scanf(" %c", &grade2);
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (fgets(name, (int)sizeof(name), stdin) != NULL) {
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
	}
	printf("%s의 학점은 %c입니다.\n", name, grade);
	printf("grade2 = %c이다.", grade2);
}
#endif

#if 0

unsigned int setBit(unsigned int num, int bitPositon) {
	num |= (1 << bitPositon);
	return num;
}

unsigned int clearBit(unsigned int num, int bitPositon) {
	num &= ~(1 << bitPositon);
	return num;
}

unsigned int toggleBit(unsigned int num, int bitPositon) {
	num ^= (1 << bitPositon);
	return num;
}

unsigned int binary(unsigned int num, unsigned int size) {
	unsigned int ret = 0;
	unsigned int mult = 1;
	for (int i = 0; i < size*4; i++) {
		ret += mult * ((num >> i) & 0x1);
		mult *= 10;
	}
	return ret;
}

int main(void) {
	unsigned int num = 0b1010;
	printf("Initial value: %X (binary: %d%d%d%d)\n", (char)num, (num>>3)&0x1, (num >> 2) & 0x1, (num >> 1) & 0x1, (num) & 0x1);
	unsigned int a, b, c;
	a = setBit(num, 2);
	b = clearBit(num, 1);
	c = toggleBit(num, 3);
	printf("After setting bit  2: %X (binary: %d%d%d%d)\n", (char)a, (a >> 3) & 0x1, (a >> 2) & 0x1, (a >> 1) & 0x1, (a) & 0x1);
	printf("After clearing bit 1: %X (binary: %d%d%d%d)\n", (char)b, (b >> 3) & 0x1, (b >> 2) & 0x1, (b >> 1) & 0x1, (b) & 0x1);
	printf("After toggling bit 3: %X (binary: %d%d%d%d)\n", (char)c, (c >> 3) & 0x1, (c >> 2) & 0x1, (c >> 1) & 0x1, (c) & 0x1);
	printf("After toggling bit 3: %X (binary: %d)\n", (char)c, binary(c,1));
}
#endif

#if 0
unsigned int binary(unsigned int num, unsigned int size) {
	unsigned int ret = 0;
	unsigned int mult = 1;
	for (int i = 0; i < size * 4; i++, mult *= 10) {
		ret += mult * ((num >> i) & 0x1);
	}
	return ret;
}

unsigned int setBit(unsigned int num, int start, int count) {
	return num | ( ((1 << count)-1) << start);
}

unsigned int clearBit(unsigned int num, int start, int count) {
	return num & ~(((1 << count) - 1) << start);
}

unsigned int toggleBit(unsigned int num, int start, int count) {
	return num ^ (((1 << count) - 1) << start);
}

int main(void) {
	unsigned int num = 0b10101010;
	printf("Initial value: %X (binary: %d)\n", (char)num, binary(num,2));
	unsigned int a, b, c;
	a = setBit(num, 2, 3);
	b = clearBit(num, 4, 2);
	c = toggleBit(num, 1, 5);
	printf("After setting bit  2 3 : %X (binary: %d)\n", (char)a, binary(a, 4));
	printf("After clearing bit 4 2 : %X (binary: %d)\n", (char)b, binary(b, 4));
	printf("After toggling bit 1 5 : %X (binary: %d)\n", (char)c, binary(c, 4));
}
#endif

#if 0
static unsigned int isBitSet(unsigned int num, int bitPosition) {
	return (num >> bitPosition) & 0x1;
}

int main(void) {
	unsigned int num;
	int bitPosition;
	printf("Enter a number: ");
	scanf_s("%u", &num);

	printf("Enter bit position to check (0-31): ");
	scanf_s("%d", &bitPosition);
	
	unsigned int res = isBitSet(num, bitPosition);
	printf("Bit %d of number %u is %u.\n", bitPosition, num, res);
}
#endif

#if 0
int main(void) {
	char x = 127;
	char y = x + 1;
	printf("x = %d, x + 1 = %d, y = %d\n", x, x + 1, y);

	x = -128;
	y = x - 1;
	printf("x = %d, x + 1 = %d, y = %d\n", x, x - 1, y);
}
#endif

#if 0
int main(void) {
	printf("%d\n", 123 && 0);
	printf("%d\n", 0.0 || 0.0);
	printf("%d\n", 0.0 || "");
	printf("%d\n", !10);
	printf("%d\n", ~~(10 < 20));

	return 0;
}
#endif

#if 0
int main(void) {
	int a = 20, b = 5;

	a += 3;				printf("%d %d\n", a, b);
	a -= b;				printf("%d %d\n", a, b);
	a *= b + 2;			printf("%d %d\n", a, b);
	a /= a - b + 1;		printf("%d %d\n", a, b);
	a %= b -= 1;		printf("%d %d\n", a, b);
	return 0;
}
#endif

#if 0
int main(void) {
	unsigned char a = 0xF0;
	char b = 0xF0;
	unsigned char c = 0x0F;
	char d = 0x0F;
	printf("%X %X %X %X\n", a, b, c, d);
	if (a == ~c) printf("a equal ~ c\n");
	if (a == ~d) printf("a equal ~ d\n");
	if (b == ~c) printf("b equal ~ c\n");
	if (b == ~d) printf("b equal ~ d\n");
}
#endif

#if 0
int main(void) {
	unsigned char a = 0xF0;
	char b = 0xF0;
	unsigned char c = 0x0F;
	char d = 0x0F;
	
	if (a > b) printf("A > B \n");
	else if (a < b) printf("A < B \n");
	else printf("A == B \n");

	if (c > d) printf("C > D \n");
	else if (c < d) printf("C < D \n");
	else printf("C == D \n");
}
#endif

#if 0
int main(void) {
	unsigned int a = 1;
	char b = -1;

	printf("%d\n", a < b);
	return 0;
}
#endif

