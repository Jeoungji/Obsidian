#include <stdio.h>
#include <stdint.h>
#include <string.h>

#if 0

char* to_upper(char* str, int size) {
	char* start = str;
	for (; (size - (str - start)) && *str; str++) {
		if (*str > 96 && *str < 123) *str -= 32;
	}
	return start;
}

char* to_upper2(char* str, int size) {
	char* start = str;
	for (; (size - (str - start)) && *str; str++) {
		if (*str > 96 && *str < 123) *str &= ~0x20;
	}
	return start;
} 

char* to_upper3(char* str, int size) {
	char* start = str;
	for (int i = 0; *str && i < size; i++, str++) {
		if (*str > 96 && *str < 123) *str &= ~0x20;
	}
	return start;
}

char* to_upper4(char* str, int size) {
	char* start = str;
	for (; *str && size--; str++) {
		if (*str > 96 && *str < 123) *str &= ~0x20;
	}
	return start;
}

int main(void) {
	char name[40] = "Tom & Jerry!";
	printf("%s\n", to_upper4(name, 2));
}
#endif

#if 0
void u_memcpy(void* dst, const void* src, size_t n) {
	dst = (uint8_t*)dst;
	uint8_t* a = (uint8_t*)dst;
	for (; n--; *(uint8_t*)dst = *(uint8_t*)src, ((uint8_t*)dst)++, ((uint8_t*)src)++);
}

void u_memset(void* dst, uint8_t val, size_t n) {
	for (; n--; *(uint8_t*)dst = val, ((uint8_t*)dst)++);
}

int main(void) {
	int ary[5] = { 10, 20, 30, 40, 50 };
	int bry[5];
	int ubry[5];

	memcpy(bry, ary, sizeof(bry));
	u_memcpy(ubry, ary, sizeof(ubry));
	printf("%d %d %d %d %d\n", bry[0], bry[1], bry[2], bry[3], bry[4]);
	printf("%d %d %d %d %d\n", ubry[0], ubry[1], ubry[2], ubry[3], ubry[4]);

	u_memset(ary, 1, sizeof(ary));
	printf("%d %d %d %d %d\n", ary[0], ary[1], ary[2], ary[3], ary[4]);
}
#endif

#if 0
int main(void) {
	int a = 3.14;
	int res;
	double res2;

	res = a + 10.5;
	res2 = a + 10.5;
	printf("%d %f\n", res, res2);
}
#endif

#if 0
int main(void) {
	char ary[20] = "watermelon";
	char* temp = ary;

	temp = &ary[5];
	printf("%s\n", temp);

	temp[0] = 'k';
	printf("%s\n", temp);

	char* ch = "melon";
	printf("%c\n", ++(*ch));
	printf("%s", ch);
	return 0;
}
#endif

#if 0
#include "func.h"

int num = 0;

int main(void) {
	printf("num : %d\n", GetNum());
	Increment();
	printf("num : %d\n", GetNum());
	Increment();
	printf("num : %d\n", GetNum());
	return 0;
}
#endif

#if 0

int* func(int a, int b) {
	int c = a + b;
	return &c;
}

int main(void) {
	printf("%d\n", *func(10, 20));
}

#endif