#include <stdio.h>

#if 0
int main(void) {
	int score;
	char n = 'F';
	scanf_s("%d", &score);

	/*
	//// if
	if(score >= 90)
		n = 'A';
	else if(score >= 80)
		n = 'B';
	else if(score >= 70)
		n = 'C';
	else if(score >= 60)
		n = 'D';
	...
	*/
	/*
	//// if
	score /= 10;
	if(score == 10 || score == 9)
		n = 'A';
	else if(score == 8)
		n = 'B';
	else if(score == 7)
		n = 'C';
	else if(score == 6)
		n = 'D';
	...
	*/
	/*
	//// swich case
	switch (score / 10) {
	case 10:
	case 9:
		n = 'A';
		break;
	case 8:
		n = 'B';
		break;
	case 7:
		n = 'C';
		break;
	case 6:
		n = 'D';
		break;
	default:
		n = 'F';
	}
	*/

	/*
	//// �迭 ����
	char grade[12] = "FFFFFFDCBAA";
	printf("%c", grade[score / 10]);
	*/
}
#endif

// ¦�� Ȧ��
#if 0
int main(void) {
	int num;
	scanf_s("%d", &num);
	// num % 2 ? printf("Ȧ��\n") : printf("¦��\n");
	
	// printf("%s��\n", num % 2 ? "Ȧ" : "¦");

	char* A[] = { "¦", "Ȧ" };
	printf("%s��", A[num % 2]);
}
#endif

#if 0
int main(void) {
	int num;
	scanf_s("%d", &num);

	//(num % 2 == 0) ? (num = 2) : (num % 3 == 0) ? (num = 3) : (num % 5 == 0) ? (num = 5) : (num = 0);
	//printf("%d", num);

	//printf("%d", (num % 2 == 0) ? 2 : (num % 3 == 0) ? 3 : (num % 5 == 0) ? 5 : 0);

	printf("%d", !(num%2) ? 2 : !(num%3) ? 3 : !(num%5) ? 5 : 0);
	return 0;
}
#endif

#if 0
int main(void) {
	int num = 0;
	for (int i = 1; i <= 100; i += 2) {
		num += i;
	}
	printf("%d", num);
}
#endif

#if 0
int main(void) {
	int num = 0;
	int i;
	scanf_s("%d", &i);

	i += (i % 2 + 1) & 0x1;
	for (; i <= 100; i += 2) {
		num += i;
	}
	printf("%d", num);
}
#endif

#if 0
void draw(int num, int i) {
	for (int j = num - i; j > 1; --j) {
		printf(" ");
	}
	for (int j = 0; j < 2 * i + 1; ++j) {
		printf("*");
	}
	printf("\n");
}

int main(void) {
	unsigned int num;
	scanf_s("%u", &num);
	
	int i = 0;
	for (; i < num; ++i) {
		draw(num, i);
	}
	for (i-=2; i >= 0; --i) {
		draw(num, i);
	}

	printf("\n\n\n");

	int dir = 1;
	for (int i = 0; i >= 0; i += dir) {
		for (int j = num - i; j > 1; --j) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			printf("*");
		}
		printf("\n");
		if (i == num-1) dir = -1;
	}
	return 0;
}
#endif

// ��ȣ Ȯ��
#if 0
int main(void) {
	int n;
	for (int i = 0; i < 3; ++i) {
		scanf_s("%d", &n);
		if (n == 1357) {
			printf("�α��� ����\n");
			return 0;
		}
	}
	printf("�����ڿ��� �����ϼ���.\n");
}
#endif

// ���� ������
#if 0
int main(void) {
	char str[10] = { 0, };
	char ret[10] = { 0, };

	int i = 0;
	for (; i < sizeof(str) - 1; ++i) {
		scanf_s("%c", &str[i]);
		if (str[i] == '\n' || str[i] == NULL) break;
	}
	for (int j = 0; j <= i; ++j) {
		ret[j] = str[i - j];
	}
	printf("%s", ret);
}
#endif

// 1���� �迭
#if 0
int main(void) {
	int arr[5] = { 0 };
	printf("arr�� ���� : %d\n", sizeof(arr) / sizeof(int));
	printf("&arr[0] : %p\n", &arr[0]);
	printf("&arr    : %p\n", &arr);
	printf("arr + 1     : %p\n", arr+1);
	printf("&arr + 1    : %p\n", &arr+1);
	printf("sizeof(arr) : %d\n", sizeof(arr));
	printf("sizeof(&arr) : %d\n", sizeof(&arr));
}
#endif

//  1���� �迭
#if 0
int main(void) {
	int i = 0;
	int ary[5] = { 1,2,3,4,5 };

	for (i = 0; i < 5; ++i) {
		printf("%d ", ary[i]);
	}
	printf("\n");

	for (i = 0; i < 5; ++i) {
		printf("%d ", *(ary + i));  //  ary[i] == *(ary+i)
	}
	printf("\n");

	printf("%p %p\n", ary, &ary);  // ary => �迭�� �̸� (������ ���)
	printf("%p %p\n", ary + 1, &ary + 1);

	printf("%d %p\n", i, &i);  // i => int ����
	// &ary : ary�� ����Ű�� �������� type�� �迭 ��ü�� ����
	// &i : ���� ������ �ּ� ��ȯ

	printf("%d %d\n", sizeof(ary), sizeof(&ary));  // sizeof(�迭��), sizeof(&�迭��)

	printf("%d", *ary);  // ary = &ary[0]

	return 0;
}

#endif

#if 0
int main(void) {
	int score[5];
	int i;
	int total = 0;

	for (i = 0; i < sizeof(score)/sizeof(int); ++i) {
		(void)scanf_s("%d", score+i);
	}
	for (i = 0; i < 5; ++i) {
		printf("%d ", score[i]);
		total += score[i];
	}
	printf("\navg : %f\n", (float)total / 5);
}
#endif

#if 0
#include<string.h>

void inputAry(int* ary, int size) {
	for (int i = 0; i < size; ++i) {
		scanf("%d", ary + i);
	}
	return;
}

void printAry(int* ary, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", *(ary + i));
	}
	printf("\n");
	return;
}

int main(void) {
	int ary[5] = { 0, };
	int size = sizeof(ary) / sizeof(ary[0]);

	inputAry(ary, size);
	printAry(ary, size);

	return 0;
}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif

#if 0
int main(void) {

}
#endif