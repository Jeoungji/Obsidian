

#Embedded #넥스원_The_SSEN_Embbed_School 

---
# Standard IO
#### 제어 문자

| 제어 문자 | 의미                                  |
| ----- | ----------------------------------- |
| \n    | 개행                                  |
| \t    | 탭                                   |
| \r    | Carriage returen<br>출력 위치를 줄의 맨 앞으로 |
| \b    | Back Space<br>출력 위치를 한 칸 왼쪽으로       |
| \a    | alert 경보<br>bell 소리                 |

#### printf, scanf

| 데이터                  | printf      |            | scanf       |            | 크기  |
| -------------------- | ----------- | ---------- | ----------- | ---------- | --- |
| (unsigned) char      | %c (%u)     |            | %c          |            | 1   |
| char[]               | %s          | `\0`전까지 출력 | %s          | `\n`전까지 읽기 | 가변  |
| (unsigned) short     | %d (%u)     |            | %hd (%hu)   |            | 2   |
| (unsgined) int       | %d (%u)     |            | %d   (%u)   |            | 4   |
| (unsigned) long      | %ld (%lu)   |            | %ld  (%lu)  |            | 4   |
| (unsigned) long long | %lld (%llu) |            | %lld (%llu) |            | 8   |
| float                | %f          |            | %f          |            | 4   |
| double               | %lf         |            | %lf         |            | 8   |
| long double          | %Lf         |            | %Lf         |            | -   |


# 변수
statement  : `for`, `if`, ...
expression : `+`, `-`, `>>`, ...
### 정수형 변수
- CPU에서 연산 시 int형 보다 작으면 확장 후 계산
	- 확장 시 빈 공간은 부호 비트로 채워 짐

### 실수형 변수
#### Float
- 유효숫자 : 7

#### Double
-  유효 숫자 : 15

### const



# 연산자
#### sizeof()
- 메모리의 크기를 반환(size_t)
- 바이트 단위
- `sizeof(arr)`은 배열 전체 크기를 반환
- 구조체, 공용체는 내부 패딩을 포함해 반환
#### &
- 변수의 메모 주소 반환

volatile
- cache를 쓰지 말고 메모리에 직접 데이터 처리
- 최적화 금지