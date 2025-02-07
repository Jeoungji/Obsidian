#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#if 0
int main(void) {
	int score[3][4] = { 0 };
	(void)freopen("scores.txt", "r", stdin);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			(void)scanf("%d", score[i]+j);
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", score[i][j]);
		}
		printf("\n");
	}
}
#endif

#if 0
int main(void) {
	int a1 = 10, a2 = 20, a3 = 30, a4 = 40;
	int* a[4] = { &a1, &a2, &a3, &a4 };

	printf("%d %d %d %d\n", *(a + 2), *a[2], **(a + 2), *(*(a + 2)));
}
#endif

#if 0
#define size_ary(x) (sizeof(x)/sizeof((x)[0]))
static void print_ary(char(*ary)[10], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s ", ary[i]);
		printf("%c ", *ary[i]);
	}
	printf("\n");
}

int main(void) {
	char animal[5][10] = { 0 };
	int i;
	(void)freopen("animal.txt", "r", stdin);
	for (i= 0; i < size_ary(animal); ++i) {
		(void)scanf("%s", animal[i]);
	}
	print_ary(animal, size_ary(animal));
}
#endif

#if 0
int main(void) {

}
#endif