#소프트웨어 #Embedded #객체지향
# C와의 차이

| [C](C.md)                       | [C++](C++.md)                                              |
| ------------------------------- | ---------------------------------------------------------- |
| 구조적 프로그램                        | [[객체 지향 프로그램]]                                             |
| [구조체](구조체.md)                    | [class](class.md)                                          |
| 변수 선언 위치가 고정                    | 변수 선언 위치가 자유로움                                             |
| 프로그램이 복잡해지면 시간순서대로 동작하는 개발의 한계성 | 현실 세계의 구성 요소를 소프트웨어로 모델링                                   |
|                                 | 객체와 객체와의 관계를 명시                                            |
|                                 | 같은 사물이어도 사용 목적에 따라 모델링 구조가 달라짐                             |
|                                 | [은닉성](은닉성.md), [다형성](다형성.md), [상속성](상속성.md), [캡슐화](캡슐화.md) |

#### namespace
- 이름 충돌을 막기 위함
- `using namespace <>` : 이름 영역 안에서 `<>::`(범위 지정 연산자)를 하지 않아도 됨
- 다른 이름 공간의 같은 이름 함수면 범위 지정자를 써야 함

#### call by reference (참조 변수)
- C++의 call by value : deep copy, 주소값 복사해서 넘기기
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
- 힙에 이름을 지정
```cpp folder title:heap_name
int main() {
	Member *memp = new Member;
	Member &mem = *memp;
	memp->score = 10;
	mem.score = 10;
}
```


# Class
public : 접근 제어자, 함수(일반적으로)
private(default) : class 밖에서 안보임
`.`   : 멤버 직접 접근 연산자
`->` : 멤버 간접 접근 연산자

### 생성자
- 반환 타입 X
- 이름이 class와 동일한 멤버 함수
- 객체, 멤버 변수 초기화
- 오버로딩 가능
- 객체 생성 시 한번 호출
- 멤버 이니셜라이저
```cpp folder title:생성자
class AAA {
	const int a;
	int &b;
public:
	AAA (int a_) : a(a_) { }
	AAA (int &b_) : b(b_) { }
}

class BBB {
	int c, d;
	AAA aaa;
public :
	BBB(int a, int b, int c, int d) 
	 : aaa(a, b)
	{
		this->c = c;
		this->d = d;
	}
}
```
#### 복사 생성자
- `SoSimple sim2 = sim1` == `SoSimple sim2(sim1)`
- 객체의 멤버의 복사를 해 저장
- Default 복사 생성자는 단순히 멤버 변수의 값만 복사 : 얕은 복사
- 복사 생성자 정의해 깊은 복사를 수행
```cpp folder title:copy_creator
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Person {
	char* name;
	int age;

public:
	Person(const char* name, int age) : age(age)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
	}

	~Person()
	{
		cout << "delete person " << name << endl;
		delete[] name;
	}
	/*
	// 얕은 복사 : 멤버 변수 값 복사, 주소값이면 주소값을 복사하므로 데이터를 공용으로 사용 -> Default
	Person(const Person &person) {
		this->name = person.name;
		this->age = person.age;
	}
	*/
	// 깊은 복사 : 주소의 경우 새 공간을 할당 받아 복사, 원본을 공유하지 않음
	Person(const Person &person) 
		: age(person.age)
	{
		int len = strlen(person.name)+1;
		this->name = new char[len];
		strcpy(this->name, person.name);
	}

	void PrintInfo() {
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
	void setName(const char* name) {
		strcpy(this->name, name);
	}
	void setAge(int age) {
		this->age = age;
	}
};

int main() {
	Person p1("aaa", 12);
	// 복사 생성자 실행행
	Person p2 = p1; // Person p2(p1);
	p1.PrintInfo();
	p2.PrintInfo();
	p1.setName("bbb");
	p1.setAge(345);
	p1.PrintInfo();
	p2.PrintInfo();
	return 0;
}
```


### 소멸자
- 반환 타입 X
- 이름이 class에 ~를 앞에 붙임
- 객체 소멸 시 자원 해제

### this
- 현재 객체의 주소를 갖는 포인터 변수
- class를 정의하는 부분에서 사용
- Running Time에는 사용 불가
```cpp folder title:this
class Member {
	int num;
public:
	void test(int num) {
		this->num = num; // parameter와 member변수의 이름이 겹치는 경우
	}	
	Member *RetP(void) {
		return this; // 현재 객체의 주소를 반환
	}
};
```

### static member
|       | 전역 변수               | static               | 지역 변수    | 레지스터     |
| ----- | ------------------- | -------------------- | -------- | -------- |
| 메모리   | data                | data                 | stack    | register |
| 선언 위치 | 함수 밖                | 함수 안/밖               | 함수 안     | 함수 안     |
| 유효 범위 | 선언 후 파일 전체<br>다른 파일 | 선언 위치에 따라<br>다른 파일 X | 함수 안     | 함수 안     |
| 유효 시간 | 프로그램 시작-끝           | 프로그램 시작-끝            | 함수 종료 전  | 함수 종료 전  |
| 초기화   | 자동 초기화              | 자동 초기화               | 자동 초기화 X | 자동 초기화 X |
- static member는 data영역에 저장됨
- 멤버 변수로 생각하면 안됨
- 그 class로 만든 모든 객체가 공용으로 사용
- 프로그램이 시작하자마자 할당
```cpp folder title:static_member
class StaticTest {
public:
	static int a; // 생성된 Test class 객체는 a를 공용으로 사용
	int b;	
	StaticTest() :b(0){}
	void add() {
		a++;
		b++;
	}
	void print() {
		cout << "a: " << a << " b: " << b <<endl;
	}	
	static void test1() { // static 멤버 함수에서는 static변수만
		cout << "a : " << a << endl;
	}
	static void test2() { // static 멤버 함수에서는 static함수만
		test1();
	}
};

int StaicTest::a = 0; // 초기화
int main() {
	cout << "static 멤버 a : " << StaticTest::a << endl;
	StaticTest st1;
	st1.add();
	st1.add();
	st1.print();
	StaticTest st2;
	st2.add();
	st2.add();
	st2.print();
	return 0;
}
```
- static 멤버 함수 : 객체를 생성하지 않아도 사용할 수 있음
- static 멤버 함수에서 일반 멤버 변수 사용/호출 불가(static은 가능)
- static 멤버 함수는 멤버 변수가 없는 순수 기능 제공 class에 활용

### const 멤버 함수
- 함수 내에서 멤버 변수 값 변경을 막음
- const 함수 내에서는 const함수만 사용 가능
```cpp folder title:const_member_funcrion
class MyPrivate {
private:
	int a, b;
public:
	void printData() const {
		cout << a << " " << b << endl;
	}
	int get_a() const {
		return a;
	}
	void print_a() const {
		cout << get_a() << endl;
	}
};
```

#### Setter/Getter
##### Setter
- private 멤버 변수 값 할당
##### Getter
- private 멤버 변수 값을 return


### 객체 지향에서의 관계
```cpp folder title:Point_class
class Point{
protected:
	int x, y;
public:
	Point():x(0), y(0) {}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void printPoint() {
		cout << "x: " << x << ", y: " << y << endl;
	}
};

```
#### 포함 관계
- 다른 class를 멤버 변수로 포함
```cpp folder title:Point_class_포함
class Point3D {
	Point p;
	int x;
public:
	Point3D() : z(0){}
	Point3D(int x) {
		this->z = z;
	}
	void printPoint() {
		p.printPoint();
		cout << "z: " << z << endl;
	}
}
```
- 현재 객체 내에서 포함 관계의 객체를 생성
- Ex) 도형
#### 상속 관계
- 코드 재사용성을 높이고 다형성 구현
```cpp folder title:Point_class_상속
class Point3D: public Point {
protected:
	int z;
public:
	Point3D: z(0) {}
	void printPoint2() {
		printPoint();
		cout << ", z: " << z << endl;
	}
}
```

- 부모의 초기화 생성자의 파라미터는 자식의 생성자에서 초기화
	부모 -> 자식 순으로 생성자 호출 됨
	자식 -> 부모 순으로 소멸자 호출 됨
```cpp folder title:parent_creator
class Parent {
	int age;
	string name;
public:
	Parent() {
		cout << "parent default creator" << endl;
	}
	Parent(int age, string name) {
		this->age = age;
		this->name = name;
		cout << "parent creator" << endl;
	}
	~Parent() {
		cout << "parent distructor" << endl;
	}
};

class Child {
	string hobby;
public:
	Child() {
		cout << "child default creator" << endl;
	}
	Child(int num, string str, string hobby):Parent(num, str), hobby(hobby) {
		cout << "child creator" << endl;
	}
	~Child() {
		cout << "child distructor" << endl;
	}
};
```

- 상속에 대한 접근 제어자
	`class <자식 class 이름> : <접근 제어자> <부모 class 이름> { }`
	public : 부모 클래스에 정의된 멤버 접근 제어자 그대로 상속
	protected : 부모 클래스에 정의된 멤버가 public -> protected로 바뀌어 상속
	private : 부모 클래스에 정의된 멤버가 모두 private으로 상속
- Ex) 학사 관리 (학생, 교수, 교직원) -> 공통점을 parent class로 정의

#### 다중 상속
- 여러 class로부터 상속
- 중복되는 변수, 함수를 조심해야 함.

#### 가상 상속


### 연산자 오버로딩
- 연산자 기능을 사용자 정의 class에 적용
- 연산자 기본 기능을 저해하면 안됨
- class의 멤버 함수로 정의 / 전역 함수로 정의

```cpp folder title:operator_overloading
class Point {
	int x, y;
public:
	Point():x(0), y(0) {}
	Point(int x, int y):x(x), y(y) {}
	// +연산자 오버로딩
	Point operator+(const Point &p) {
		Point res(x+p.x, y+p.y); // type이 같아 private접근 허용
		return res;
	}
	friend Point operator-(const Point &p1, const Point &p2);
};
Point operator-(const Point &p1, const Point &p2) {
	Point res(p1.x-p2.x, p1.y-p2.y);
	return res;
}
int main() {
	Point a(2, 2);
	Point b(3, 3);
	Point c = a + b;
	Point d = a - b;
	c.Print();
	d.Print();
}
```


### 대입 연산자 재정의
```cpp folder title:substitution_operator_overwriting
class Person {
char *name;
int age;
public:
	Person(char *name, int age) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
		this->age = age;
	}
	void printPerson() {
		cout << "mname : " << name << endl;
		cout << "age : " << age << endl;
	}
	// 이름을 대입하기 위해서는 메모리 할당을 다시해야 함.
	Person& operator=(const Person& p) {
		delete []name;
		int len = strlen(p.name) + 1;
		this->name = new char[len];
		strcpy(this->name, p.name);
		this->age = p.age;
		return *this;
	}

	~Person() {
		delete[] name;
	}
};
```


### 함수
##### 함수 Default Value
- 함수 parameter의 default value는 오른쪽부터 채워져 있어야 함.
```cpp folder title:default_value
int add (int a, int b) {...}
int add (int a, int b, int c = 3) {...} // 위의 add와 같이 int형 변수 두개만 넣으면 되므로 모호 해짐
```




# Template
- 코드 일반화에 사용
- Type이 달라도 동작이 동일한 코드를 Type은 가상의 이름으로 작성하고 실행
- [Compile](Compile.md)시간에 타입 별로 함수를 #overloading 해서 제공
- 코드 크기 증가

```cpp folder tilte:template
template<typename, T>
t.add(T a, T b) {
	return a + b;

int main() {
	cout <<"add(1, 2) "a << add(1,2) << endl;
	cout <<"add(1.2, 2.3):" << add(1.2, 2.3) << endl;
	cout <<"add(\"aaa\", \"bbb\"):" << add<string>("aaa", "bbb") << endl;
}
```


#### 특수화
- 일반적으로 의미가 없는 함수를 동일한 명칭으로 사용

```cpp folder title:template
template<typename T>
T Max(T v1, T v2) {
	return (v1 > v2) ? v1 : v2;
}

template<>
char* Max(char* v1, char* v2) {
	cout << "char *비교" << endl;
	return (strlen(v1) > strlen(v2)) ? v1 : v2;
}

template<>
const char* Max(const char* v1, const char* v2) {
	cout << "const char *비교" << endl;
	return (strlen(v1) > strlen(v2)) ? v1 : v2;
}

int main() {
	char buf1[] = {'1', 'b'};
	char buf2[] = {'a', 'b', 'c', 'd'};
	
}
```


#### class Template
- class의 멤버 변수의 자료형

```cpp folder title:class_template
template<typename T>
class MyTempI {
public:
	T a;
	T b;
	MyTempI(T a, T b):a(a), b(b) {}
	T getA() {
		return a;
	}
	void setA(T a) {
		this->a = a;
	}
	void print() {
		cout << "a : " << a << ", b : " << b << endl;
	}
};
```

##### 배열 class template
```cpp folder title:array_class_template
class Point {
public:
	int x, y;
	Point() {}
	Point(int x, int y):x(x), y(y) {}
	void print() {
		cout << "x:" << x << " y:" << y << endl;
	}
};
template<typename T>
class MyArr {
	T *arr;
	int len;
public:
	MyArr() {
		arr = new T[6];
		len = 6;
	}
	MyArr(int len) {
		arr = new T[len];
		this->len = len;
	}
	const T& operator[](int idx) const {
		if (idx < 0 || idx >= len) {
			cout << "out of bounds exception" << endl;
			exit(-1); 
		}
		return arr[idx];
	}
	T& operator[](int idx) const {
		if (idx < 0|| idx >= len) {
			cout << "out of bounds exception" << endl;
			exit(-1);
		}
		return arr[idx];
	}
	int getLan() {
		return len;
	}
	~MyArr() {
		delete[] arr;
	}
};

int main() {
	MyArr<Point> a;
	cout << a.getLen() << endl;
	a[0] = Point(1,2);
	a[0].print();
	return 0;
}
```

##### class template 특수화


### 배열 index
- 기본 배열은 접근에 대한 경계 X
- const함수와 아닌 함수도 다르게 인식

