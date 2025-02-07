#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#if 0
void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void exchange1(int** ap, int** bp) {
	int temp = **ap;
	**ap = **bp;
	**bp = temp;
}
void exchange2(int*** app, int*** bpp) {
	int temp = ***app;
	***app = ***bpp;
	***bpp = temp;
}
void exchange3(int** ap, int** bp) {
	int *temp = *ap;
	*ap = *bp;
	*bp = temp;
}
void exchange4(int*** app, int*** bpp) {
	int *temp = **app;
	**app = **bpp;
	**bpp = temp;
}
void exchange5(int*** app, int*** bpp) {
	int **temp = *app;
	*app = *bpp;
	*bpp = temp;
}
void print(int a, int b, int* ap, int* bp, int** app, int** bpp) {
	printf("a:%d b:%d, ap:[%d] %p bp:[%d] %p, app:[%d] [%p] %p bpp:[%d] [%p] %p\n", a, b, *ap, ap, *bp, bp, **app, *app, app, **bpp, *bpp, bpp);
	return;
}

int main(void) {
	int a = 10, b = 5;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;

	exchange0(&a, &b);
	print(a, b, ap, bp, app, bpp);
	// a: 5 b:10, ap:[ 5] 00B6F808 bp:[10] 00B6F7FC, app:[ 5] [00B6F808] 00B6F7F0 bpp:[10] [00B6F7FC] 00B6F7E4

	exchange1(&ap, &bp);
	print(a, b, ap, bp, app, bpp);
	// a:10 b: 5, ap:[10] 00B6F808 bp:[ 5] 00B6F7FC, app:[10] [00B6F808] 00B6F7F0 bpp:[ 5] [00B6F7FC] 00B6F7E4

	exchange2(&app, &bpp);
	print(a, b, ap, bp, app, bpp);
	// a: 5 b:10, ap:[ 5] 00B6F808 bp:[10] 00B6F7FC, app:[ 5] [00B6F808] 00B6F7F0 bpp:[10] [00B6F7FC] 00B6F7E4

	exchange3(&ap, &bp);
	print(a, b, ap, bp, app, bpp);
	// a: 5 b:10, ap:[10] 00B6F7FC bp:[ 5] 00B6F808, app:[10] [00B6F7FC] 00B6F7F0 bpp:[ 5] [00B6F808] 00B6F7E4

	exchange4(&app, &bpp);
	print(a, b, ap, bp, app, bpp);
	// a: 5 b:10, ap:[ 5] 00B6F808 bp:[10] 00B6F7FC, app:[ 5] [00B6F808] 00B6F7F0 bpp:[10] [00B6F7FC] 00B6F7E4

	exchange5(&app, &bpp);
	print(a, b, ap, bp, app, bpp);
	// a: 5 b:10, ap:[ 5] 00B6F808 bp:[10] 00B6F7FC, app:[10] [00B6F7FC] 00B6F7E4 bpp:[ 5] [00B6F808] 00B6F7F0

	return 0;
}
#endif

#if 0
void print_ary(char** pary, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s\n", (char*)pary[i]);
	}
}
int main(void) {
	char* pary[5] = { "dog", "elephant", "horse", "tiger", "lion" };

	//pary[0][0] = 'x';

	char data[] = "golo";
	pary[0] = data;
	*(pary[0]) = 'x';

	print_ary(pary, 5);
	return 0;
}
#endif

#if 0

void input_array(int*** arr, int *nsize) {
	(void)scanf("%d", nsize);
	*arr = (int**)malloc(sizeof(int*) * (*nsize));
	for (int i = 0; i < *nsize; ++i) {
		int size;
		(void)scanf("%d", &size);
		(*arr)[i] = (int*)malloc(sizeof(int) * (size + 1));
		if ((*arr)[i] == NULL) {
			return;
		}
		(*arr)[i][0] = size;

		for (int j = 1; j <= size; ++j) {
			(void)scanf("%d", (*arr)[i] + j);
		}
	}
}

void input_array2(int*** arr, int* nsize) {
	int n;
	int** ary;
	(void)scanf("%d", n);
	ary = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		int size;
		(void)scanf("%d", &size);
		ary[i] = (int*)malloc(sizeof(int) * (size + 1));
		if (ary[i] == NULL) {
			return;
		}
		ary[i][0] = size;

		for (int j = 1; j <= size; ++j) {
			(void)scanf("%d", ary[i] + j);
		}
	}
	*arr = ary;
	*nsize = n;
}

void Print(int const *const*const arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j <= arr[i][0]; ++j) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	(void)freopen("myfile.txt", "r", stdin);

	int nsize = 0;
	int** a = 0;

	input_array(&a, &nsize);
	Print(a, nsize);
	
	return 0;
}
#endif