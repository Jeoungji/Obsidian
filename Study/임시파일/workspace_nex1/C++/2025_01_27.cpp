#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#if 0
class Parent {
public:
	int a;

	Parent() :a(0) {}
	Parent(int a) :a(0) {}
	virtual void printData() {
		cout << "a : " << a << endl;
	}
};

class Child :public Parent {
public:
	int b;
	Child() :b(0) {}
	Child(int a, int b) :Parent(a), b(b) {}
	virtual void printData() {
		Parent::printData();
		cout << "b : " << b << endl;
	}
};

int main() {
	Parent* p = new Parent(3);
	Child* c = new Child(2, 3);
	Parent* pc = c;
	cout << "p: " << typeid(p).name() << endl;
	cout << "c: " << typeid(c).name() << endl;
	cout << "pc: " << typeid(pc).name() << endl;
	cout << "*p: " << typeid(*p).name() << endl;
	cout << "*c: " << typeid(*c).name() << endl;
	cout << "*pc: " << typeid(*pc).name() << endl;

	// pc는 Parent이기 때문에 b에 접근을 하지 못함 -> 다운 캐스팅
	// *pc에 Child* c가 저장되어 있으므로 typeid(*pc) == typeid(Child)
	// 확인 후 다운 캐스팅하여 데이터 저장
	if (typeid(*pc) == typeid(Child)) {
		((Child*)pc)->b = 13;
	}
	pc->printData(); //virtual void printData() 이므로 Child의 printData()가 실행

	return 0;
}
#endif

#if 0
class Point {
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
	// +연산자 오버로딩
	Point operator+(const Point& p) {
		Point res(x + p.x, y + p.y); // type이 같아 private접근 허용
		return res;
	}
	friend Point operator-(const Point& p1, const Point& p2);
	
	void Print() {
		cout << x << " " << y << endl;
	}
};
Point operator-(const Point& p1, const Point& p2) {
	Point res(p1.x - p2.x, p1.y - p2.y);
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
#endif

#if 0
#include <vector>


class ustring {
	char* str;
	int size;
public:
	ustring() {
		size = 1;
		str = new char[size];
		str[0] = NULL;
		cout << "기본 생성자" << endl;
	}
	ustring(char* str) {
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy(this->str, str);
		cout << "char* 생성자" << endl;
	}
	ustring(const char* str) {
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy(this->str, str);
		cout << "const char* 생성자" << endl;
	}
	ustring(const ustring &str) {
		size = str.size;
		this->str = new char[size];
		strcpy(this->str, str.str);
		cout << "ustring 생성자" << endl;
	}
	ustring(const string& s) {
		size = s.size();
		cout << s.size() << " " << s.length() << endl;
		this->str = new char[size + 1];
		strcpy(this->str, s.c_str());
		cout << "string 생성자" << endl;
	}

	int len() {
		return size - 1;
	}

	ustring& operator=(const ustring& str) {
		if (this->str != NULL)
			delete[] this->str;
		size = str.size;
		this->str = new char[size];
		strcpy(this->str, str.str);
		return *this;
	}

	bool operator==(const ustring& str) {
		return !strcmp(this->str, str.str);
	}

	bool compare(const ustring& str) {
		return !strcmp(this->str, str.str);
	}

	friend ostream& operator<<(ostream& os, const ustring& str);

	~ustring() {
		cout << "delete" << endl;
		delete[] str;
	}
};

ostream& operator<<(ostream& os, const ustring& str) {
	os << str.str;
	return os;
}

int main() {
	//char a[] = {'a', 'b', '\0'};

	//ustring str(a);
	//ustring str2("abcd");
	//ustring str3(str);
	//ustring str4 = str2;
	string ab = "as";
	ustring str5(ab);

	//cout << str.compare(str2) << endl;
	//cout << str.compare(str3) << endl;
	//cout << str4.compare(str2) << endl;
	//cout << (str4 == str2) << endl;

	//cout << str << endl;
	//cout << str2 << endl;
	//cout << str3 << endl;
	//cout << str4 << endl;
}
#endif