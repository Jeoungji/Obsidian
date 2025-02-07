#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#if 0

void solution();

int main() {
    int testcase;
    (void)freopen("susi_testcase.txt", "r", stdin);

    (void)scanf("%d", &testcase);

    for (int i = 0; i < testcase; ++i)
        solution();

    return 0;
}

void solution() {
    //NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
    int D[3001] = { 0 };
    //N �ʹ�� , d ������, k ���� Ƚ��, c ����
    int N, d, k, c;

    //�ʹ� �Ա� �����ϴ� ��ġ�� ������ index ������
    int start = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 1, max = 0;
    int i = 0;
    //�Է� ��
    (void)scanf("%d %d %d %d", &N, &d, &k, &c);

    int* NUM = (int*)malloc((N + k) * sizeof(int));

    for (; i < N; i++)
        (void)scanf("%d", NUM + i);

    //���� ���� ó���ϱ�
    ++D[c];

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�
    for (i = 0; i < k; i++) {
        NUM[i + N] = NUM[i];
        if (!D[NUM[i]]++)
            ++kind_num;
    }
    max = kind_num;
    for (start = 0; start < N; ++start)
    {
        // if (max == (k+1)) break; // �����Ϳ� ���� �޶����� ����. ���� �߻��� �� ����
        
        //���� �ʹ��� ������ �ϳ����ٸ�
        if (1 == D[NUM[start]]--)
            --kind_num;

        //���� ���� �ʹ��� ������ ���ο� ���̶��
        if (0 == D[NUM[start + k]]++)
            ++kind_num;

        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;
    }
    printf("%d\n", max);
}

#endif

#if 0

int N = 0;

void test1(int L) {
    if (L > N) return;
    printf("L = %d\n", L);
    test1(L + 1);
}

void test2(int L) {
    if (L <= 0) return;
    printf("L = %d\n", L);
    test2(L - 2);
}

void test3(int L) {
    if (L > N) return;
    printf("L = %d\n", L);
    test3(L + 1);
    printf("L = %d\n", L);
}

void test4(int L) {
    printf("L = %d\n", L);
    if (L >= N) return;
    test4(L + 1);
    printf("L = %d\n", L);
}

void test5(int L){
    if (L > N) return;
    printf("L = %d\n", L);
    test5(L + 1);
    printf("L = %d\n", N + 1 - L);
    return;
}

void test6(int L) {
    if (L > N) return;
    for (int i = 1; i <= L; ++i)
        printf("%d ", i);
    printf("\n");
    test6(L + 1);
}

void test7(int L) {
    if (L == 0) return;
    for (int i = 0; i <= N - L; ++i)
        printf("%d ", i + 1);
    printf("\n");
    test7(L - 1);
}

int main(void) {
    N = 5;
    //test1(1);
    //test2((N >> 1) << 1);
    //test3(1);
    //test5(1);
    test6(1);
    test7(5);
    return 0;
}
#endif

#if 0

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int N;
int map[26][26] = { 0 };
int part = 0;
int parts[25 * 25] = { 0, };

int Find(int y, int x) {
    int ret = 1;
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (map[ny][nx] == 0) continue;

        map[ny][nx] = 0;
        ret += Find(ny, nx);
    }
    return ret;
}

void sort(int n) {
    int temp;
    for (int i = n-1; i > 0; ++i) {
        if (parts[i] <= parts[i - 1]) return;

        temp = parts[i];
        parts[i] = parts[i - 1];
        parts[i - 1] = temp;
    }
}

int main(void) {
    (void)scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            (void)scanf("%1d", map[i] + j);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 0) continue;
            parts[part++] = Find(i, j) -1;
            sort(part);
        }
    }
    printf("%d\n", part);
    for (int i = 0; i < part; ++i) {
        printf("%d\n", parts[i]);
    }
}

#endif

#if 0
int map[25 + 2][25 + 2];
int dangi[25 * 25] = { 0 };
int N;
int dangi_cnt = 0;
int cnt;

void input_data(void) {
    int i, j;

    (void)scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            (void)scanf("%1d", map[i] + j);
        }
    }
}

void print_map(void) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void miro(int r, int c) {
    map[r][c] = 0;
    ++cnt;
    miro(r - 1, c);
    miro(r + 1, c);
    miro(r, c - 1);
    miro(r, c + 1);
}

void solve(void) {
    int i, j;
    dangi_cnt = 0;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (map[i][j] == 1) {
                cnt = 0;
                miro(i, j);
                dangi[dangi_cnt++] = cnt;
            }
        }
    }
}

int main(void) {
    input_data();
    print_map();
    solve();
    return 0;
}
#endif