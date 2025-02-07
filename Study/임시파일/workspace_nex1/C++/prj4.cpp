#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#if 0
#include <iostream>
#include <cstring>

using namespace std;

class MyPrivate {
private:
	int a;
	int b;
public :
	void InputData(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void PrintData() {
		cout << a << " " << b << endl;
	}
	void set_a(int a) {
		this->a = a;
	}
	void set_b(int b) {
		this->b = b;
	}
	int get_a(void) const {
		return a;
	}
	int get_b(void) const {
		return b;
	}
};

class Point {
	int x, y;
public:
	Point() {
		x = 0; y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void PrintPoint() {
		cout << "x : " << x << " y : " << y << endl;
	}
};

class Person {
	char* name;
	int age;

public:
	Person() {}
	Person(const char* name, int age) :age(age){
		int len = (int)strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}
	void PrintInfo() {
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
	~Person() {
		cout << "memory delete : " << name << endl;
		delete[] name;
	}
};

int main(void) {
	Person* person[3];
	person[0] = new Person("dong", 10);
	person[1] = new Person("ho", 12);
	person[2] = new Person("io", 14);

	person[0]->PrintInfo();
	person[1]->PrintInfo();
	person[2]->PrintInfo();

	delete person[0];
	delete person[1];
	delete person[2];
	return 0;
}
#endif


#include <iostream>
#if 0
#include <string>

using namespace std;

class Person {
	string name;
	int age;

public:
	Person() : name(""), age(0) {}
	Person(string name, int age) :name(name), age(age) { }
	~Person() { cout << "delete person " << name << endl; }
	void PrintInfo() {
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
};

class Node {
	Person *person;
	Node* next;
public:
	Node() : next(nullptr) {}
	Node(string name, int age, Node* next = nullptr) {
		person = new Person(name, age);
		this->next = next;
	}
	~Node() {
		delete person;
	}

	void set_next(Node* next) {
		this->next = next;
	}
	Node* get_next() {
		return next;
	}
	Person* get_person() {
		return person;
	}
};

class MyLinkedList {
	Node* header;
	Node* tail;

public:
	MyLinkedList() {
		// make dummy node
		header = new Node;
		tail = header;
	}
	~MyLinkedList() {
		clear();
		delete header;
	}

	void Insert(string name, int age) {
		tail->set_next(new Node(name, age));
		tail = tail->get_next();
	}

	void PrintAll() {
		Node* curr = header->get_next();

		while (curr != nullptr) {
			curr->get_person()->PrintInfo();
			curr = curr->get_next();
		}
		cout << endl;
	}
	void clear() {
		Node* curr = header->get_next();
		Node* next;
		
		while (curr != nullptr) {
			next = curr->get_next();
			delete curr;
			curr = next;
		}
		tail = header;
	}
};

int main() {
	MyLinkedList list;

	list.Insert("dong", 10);
	list.Insert("dang", 11);
	list.Insert("ding", 12);
	list.Insert("dung", 13);

	list.PrintAll();

	list.clear();
	//list.PrintAll();
	return 0;
}
#endif


#if 0
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

	Person(const Person& person)
		: age(person.age)
	{
		int len = strlen(person.name) + 1;
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
	// Default 복사 생성자
	Person p2 = p1; // 얕은 복사 : 멤버 변수 값 복사, 주소값이면 주소값을 복사하므로 데이터를 공용으로 사용
	p1.PrintInfo();
	p2.PrintInfo();
	p1.setName("bbb");
	p1.setAge(345);
	p1.PrintInfo();
	p2.PrintInfo();
	return 0;
}

#endif

#if 0
using namespace std;

class StaticTest {
public:
	static int a; // 생성된 Test class 객체는 a를 공용으로 사용
	static int num;
	int b;
	StaticTest() :b(0) { cout << num++ << "객체 생성" << endl; }
	void add() {
		a++;
		b++;
	}
	void print() {
		cout << "a: " << a << " b: " << b << " num : " << num << endl;
	}
};

int StaticTest::a = 0; // 초기화
int StaticTest::num = 0; // 초기화

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
	StaticTest st3;
	StaticTest st4;
	StaticTest st5;
	StaticTest st6;
	StaticTest st7;
	st7.print();
	return 0;
}
#endif

// singleton
// private 생성자
// 객체를 클래스 안에서 새엉
// 생성한 객체를 반환 멤버 함수 -> static
#if 0
#include <iostream>

using namespace std;

class Singleton {
	Singleton() {}
	int number;
public:
	static Singleton *singleton;
	static Singleton* SingletonInit() {
		if (singleton == nullptr) {
			singleton = new Singleton;
		}
		return singleton;
	}
	void set_number(int num) {
		number = num;
	}
	void print_number() {
		cout << number << endl;
	}
};

Singleton* Singleton::singleton = nullptr;

int main() {
	Singleton* single = Singleton::SingletonInit();
	single->set_number(100);
	single->print_number();
	Singleton* single2 = Singleton::SingletonInit();
	single2->set_number(200);
	single->print_number();
	single2->print_number();
}
#endif

#if 0
#include <iostream>
#include "singletone.h"

using namespace std;

int main()
{
	// Singletone st;  //에러
	Singletone& s = Singletone::getInstance();
	s.setA(10);
	cout << "s.a:" << s.getA() << endl;

	Singletone& s2 = Singletone::getInstance();
	s2.setA(20);
	cout << "s2.a:" << s2.getA() << endl;
	cout << "s.a:" << s.getA() << endl;
	return 0;
}


#endif

