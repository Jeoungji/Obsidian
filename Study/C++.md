LIG2412

# C와의 차이

[[C]] : 구조적 프로그램
- 시간 순서대로
- 구조체
- 변수 선언 위치가 고정
C++ : 객체 지향 프로그램
- 프로그램이 복잡해지면 시간 순서대로 동작하는 개발의 한계성
- 현실 세계의 구성 요소를 소프트웨어로 모델링
- 객체와 객체와의 관계를 명시
- 같은 사물이여도 사용 목적에 따라 모델링 구조가 달라짐
- class
- 변수 선언 위치 자유로움
- 은닉성 (class외부에서 멤버 변수의 접근을 막음)
-
Class
- 함수 추가
- 함수 오버라이딩
- 오버라이딩
- 생성자
- 소멸자
- 생속

[[C]]/[[C++]] 컴파일 -> 실행파일 .exe -> 실행 -> start up code(초기화 코드)
.text : 코드, 상수, RO
.data : 초기화 한 전역변수, static 변수, RW
.bss : 초기화 안한 전역변수, static 변수, 자동으로 0으로 초기화, RW
.heap : 포인터로만 접근
.stack : 함수 사용 메모리, 지역변수 저장

start up code
- 실행 파일을 램에 올림


캡슐화

C++의 call by value : deep copy, 주소값 복사해서 넘기기
call by reference : 참조 변수 

#### call by reference
- C++에서 deep copy, 기존 pointer는 call by value
- call by reference : 참조 변수
- 주로 함수의 parameter로 사용
```cpp fold title:call_by_reference
int main() {
	int a = 10;
	int &b = a; // b는 a의 별칭
				// 컴파일러도 a와 b를 구분하지 않음.
	cout << a << endl; // << : pipeline으로 데이터를 보냄
	cout << b << endl;
}
```

#### namespace
- 이름 충돌을 막기 위함
- `using namespace <>` : 이름 영역 안에서 `<>::`(범위 지정 연산자)를 하지 않아도 됨
- 다른 이름 공간의 같은 이름 함수면 범위 지정자를 써야 함

#### main
- main의 반환 정상 종료 확인

#### class
public : 접근 제어자, 함수(일반적으로)
private(default) : class 밖에서 안보임
`.`   : 멤버 직접 접근 연산자
`->` : 멤버 간접 접근 연산자

#### 함수 오버로딩
- 이름이 동일한 함수 여러 개 정의 가능
	C에서는 변수와 함수의 이름이 같으면 Error
```cpp folder title:function_overloading
// 이름이 같으면 매게변수로 구분
// parameter의 개수 or type
int add(int, int);
int add(int, int, int);
char * add(char*, char*);
float add(float, float);
```

#### 함수 Default Value
- 함수 parameter의 default value는 오른쪽부터 채워져 있어야 함.
```cpp folder title:default_value
int add (int a, int b) {...}
int add (int a, int b, int c = 3) {...} // 위의 add와 같이 int형 변수 두개만 넣으면 되므로 모호 해짐
```


#### 객체 의미
1. 설계 : 모델링에서 도출되는 샘플
   1. 요구 분석
   2. 기능 정리
   3. 발생 가능한 상황 분석 및 대처 방안 분석
   ex) ATM
	   카드를 꼽는다
	   패스워드 입력
	   출금 금액 입력
	   잔액 확인
	   연결된 총장 돈 인출
	   돈 출력
	모델링에서 샘플 도출
	- 카트 : 카드사, 번호, 비밀번호, 계좌
	- 계좌 : 은행명, 계좌번호, 비밀번호
	객체화
	```
	class Card {
		// 멤버 변수 : 객체의 정보를 저장, 값은 언제나 변경 가능
		// 멤버 함수(메서드) : 이 객체의 기능 제공
	}
	```
2. 프로그램 개발시 : 클래스 타입의 변수

[[객체 지향 프로그램]]
1. 객체를 정의 : 모델링에서 도출되는 샘플을 클래스로 정의
2. 객체 사이의 관계를 명시 : 상속, 포함

[[캡슐화]] 객체는 객체 한 개를 담을 수 있게 설계
```
class Member {
	string name;
	string tel;
	string addr;
public:
	void inputData(string n, string t, string a);
	void printData(void);
}
```


