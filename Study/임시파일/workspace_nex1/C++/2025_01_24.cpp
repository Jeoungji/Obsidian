#include <iostream>
#include <string>

using namespace std;


// 상속
#if 0
class Person {
protected:
	string name;
	string telephone;
	string address;
public:
	Person() {}
	Person(string name, string telephone, string address)
		: name(name), telephone(telephone), address(address) { }
	void PrintInfo() {
		cout << "name : " << name << endl;
		cout << "telephone : " << telephone << endl;
		cout << "address : " << address << endl;
	}
};

class Student : public Person {
	const int max_subject;
	int subject_num;
	string *subject;
	
public:
	Student() : max_subject(40), subject_num(0) {
		subject = new string[max_subject];
	}
	Student(string name, string telephone, string address)
		: Person(name, telephone, address), max_subject(40), subject_num(0) {
		subject = new string[max_subject];
	}
	~Student() {
		delete[] subject;
	}

	void InsertSubject(string subject) {
		if (subject_num > max_subject - 1) {
			cout << "초과 과목" << endl;
			return;
		}
		this->subject[subject_num++] = subject;
		return;
	}
	void PrintSubjects() {
		cout << "수강 신청 목록" << endl;
		for (int i = 0; i < subject_num; ++i) {
			cout << i+1 << " : " << subject[i] << endl;
		}
		cout << endl;
	}
};

class Professor : public Person {
	const int max_subject;
	int subject_num;
	string* subject;

public:
	Professor() : max_subject(10), subject_num(0) {
		subject = new string[max_subject];
	}
	Professor(string name, string telephone, string address)
		: Person(name, telephone, address), max_subject(10), subject_num(0) {
		subject = new string[max_subject];
	}
	~Professor() {
		delete[] subject;
	}

	void InsertSubject(string subject) {
		if (subject_num > max_subject - 1) {
			cout << "초과 과목" << endl;
			return;
		}
		this->subject[subject_num++] = subject;
		return;
	}
	void PrintSubjects() {
		cout << "강의 목록" << endl;
		for (int i = 0; i < subject_num; ++i) {
			cout << i + 1 << " : " << subject[i] << endl;
		}
		cout << endl;
	}
};

class TeachingStaff : public Person {
	string job;
public:
	TeachingStaff() {}
	TeachingStaff(string name, string telephone, string address, string jpb="")
		: Person(name, telephone, address), job(job) { }
	void SetJob(string job) {
		this->job = job;
	}
	void PrintJob() {
		cout << "job : " << job << endl;
	}
};

int main() {
	Student s("hong", "0x0-xxxx-9492", "소초");
	s.InsertSubject("C");
	s.InsertSubject("C++");
	s.PrintInfo();
	s.PrintSubjects();

	Professor p("hand", "000-xxxx-4291", "초소");
	p.InsertSubject("고전역학");
	p.InsertSubject("동역학");
	p.InsertSubject("제어이론");
	p.PrintInfo();
	p.PrintSubjects();

	TeachingStaff t("janf", "x", "전방");
	t.SetJob("공유대학사업");
	t.PrintInfo();
	t.PrintJob();

	return 0;
}
#endif


#if 0
using namespace std;

class Point {
protected:
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	void printPoint() {
		cout << " x: " << x << " y: " << y << endl;
	}
	int getX() {
		return x;
	}
};
class Point3D :public Point {
	int z;
public:
	Point3D() :z(0) {}
	Point3D(int x, int y, int z) :Point(x, y), z(z) { }

	void printPoint() { // 함수 재정의
		Point::printPoint();
		cout << " z: " << z << endl;
	}
	int getZ() {
		return z;
	}
};

int main() {
	// 객체로 재정의한 함수 호출시 선언된 타입을 따라감
	// 정적 호출
	Point p2(4, 5);
	p2.printPoint(); // Point::printPoint()

	Point3D p(1, 2, 3);
	p.printPoint(); // Point3D::printPoint()
	cout << "pp.x: " << p.getX() << endl;
	cout << "pp.z: " << p.getZ() << endl;

	// 업캐스팅 : 포인터 타입을 따라감 상속 관계에서만 가능
	// 부모 클래스에 정의된 멤버만 사용 가능
	Point* pp = &p;
	pp->printPoint(); // Point::printPoint()
	cout << "pp.x: " << pp->getX() << endl;
	//cout << "pp.z: " << pp->getZ() << endl; // Point class에는 없는 메소드


	Point3D* ppp = &p; // 다운 캐스팅 : 포인터 타입을 따라감 상속 관계에서만 가능
	ppp->printPoint(); // Point3D::printPoint()
	cout << "pp.x: " << ppp->getX() << endl;
	cout << "pp.z: " << ppp->getZ() << endl;


	return 0;
}

#endif


#if 0
class Product {
public:
	string name;
	int price;
	int point;
	Product() {}
	Product(string name, int price, int point) : name(name), price(price), point(point) {}
};
class Computer : public Product {

public:
	Computer() {
		name = "Computer";
		price = 100;
		point = 10;
	}
};

class Tv : public Product {

public:
	Tv() {
		name = "TV";
		price = 200;
		point = 30;
	}
};

class Audio : public Product {

public:
	Audio() {
		name = "Audio";
		price = 1000;
		point = 100;
	}
};

class Buyer {
	int money;
	int point;
public:
	Buyer() : money(10000), point(0) {}
	void buy(Product* p) {

		if (money >= p->price) {
			cout << p->name << " 구매" << endl;
			money -= p->price;
			point += p->point;
		}
		else {
			cout << p->name << " : 잔액 부족" << endl;
		}
	}
};

int main() {
	Buyer b;
	Product* arr[] = { new Tv(), new Computer(), new Audio(),
		new Tv(), new Computer(), new Audio() };

	for (int i = 0; i < 6; ++i) {
		b.buy(arr[i]);
	}
}

#endif

#if 0

class Car {
public:
	void horn() {
		cout << "빵빵" << endl;
	}
};
class Ambulance : public Car {
	void horn() {
		cout << "엠뷸런스 위급함" << endl;
	}
};
class FireCar : public Car {
	void horn() {
		cout << "소방차 화재" << endl;
	}
};
class PoliceCar : public Car {
	void horn() {
		cout << "너 나와" << endl;
	}
};

int main() {
	Car* arr[] = { new Car(), new Ambulance(), new FireCar(), new PoliceCar() };
	for (int i = 0; i < 4; ++i) {
		arr[i]->horn();
	}
	return 0;
}

#endif

#if 0


class Monster {
protected:
	string name;
	int hp;
	int exp;
	int level;
	int updateLevel;
public:
	Monster() : hp(100), exp(0), level(1) { }
	Monster(string name, int hp, int updateLevel)
		: name(name), hp(hp), exp(0), level(1) {}

	virtual void Eat() {
		cout << name << " eatting" << endl;
		// hp++
	}
	virtual void Sleep() {
		cout << name << " sleep" << endl;
		// hp++
	}
	virtual bool Play() {
		cout << name << " play" << endl;
		// hp--
		// exp++
		return true;
	}
	virtual bool Excercise() {
		cout << name << " exercise" << endl;
		// hp -- --
		// exp ++ ++
		return true;
	}
	virtual void LevelCheck() {
		cout << name << " level " << level << endl;
		if (exp > level * updateLevel) {
			exp = 0;
			level++;
			cout << "level 증가 " << level << endl;
		}
	}
	void printState() {
		cout << name << " status" << endl;
		cout << "hp : " << hp << endl;
		cout << "hp : " << exp << endl;
		cout << "hp : " << level << endl;
	}
};

class Pikacue : Monster{
	
public:
	Pikacue() : Monster("Pikacue", 50, 70) {}
	
	void Eat() {
		hp += 10;
		Monster::Eat();
	}
	void Sleep() {
		hp += 50;
		Monster::Sleep();
	}
	bool Play() {
		hp -= 10;
		exp += 10;
		Monster::Play();
		return hp > 0;
	}
	bool Excercise() {
		hp -= 50;
		exp += 100;
		Monster::Excercise();
		return hp > 0;
	}
	void LevelCheck() {
		Monster::LevelCheck();
	}
};

class Kobugi : Monster {

public:
	Kobugi() : Monster("kobugi", 200, 130) {}

	void Eat() {
		hp += 10;
		Monster::Eat();
	}
	void Sleep() {
		hp += 50;
		Monster::Sleep();
	}
	bool Play() {
		hp -= 10;
		exp += 10;
		Monster::Play();
		return hp >0;
	}
	bool Excercise() {
		hp -= 50;
		exp += 100;
		Monster::Excercise();
		return hp > 0;
	}
	void LevelCheck() {
		Monster::LevelCheck();
	}
};

typedef enum pokemon {
	pikacue,
	kobugi
}pokemon;

typedef enum act {
	eat,
	sleep,
	play,
	excercise,
	done
};

class Console {
public:
	int SelectPokemon() {
		int ret;
		cout << "캐릭터 선택" << endl;
		cout << "0.pica 1.kobugi" << endl;
		cin >> ret;
		return ret;
	}
	int  PrintMenu() {
		int ret;
		cout << "1.Eat 2.Sleep 3.Play 4.Excercise" << endl;
		cin >> ret;
		return (ret+1);
	}
};

class Simulator {
	Console console;
	Monster* myMonster;
public:
	Simulator() {	}
	bool SetMonster() {
		if (myMonster != NULL) return false;
		switch ((pokemon)console.SelectPokemon()) {
		case pikacue:
			break;
			myMonster = (Monster*)new Pikacue;
		case kobugi:
			myMonster = (Monster*)new Kobugi;
			break;
		}
		return true;
	}
	bool Choose(act a) {
		bool ret = true;
		switch (a) {
		case eat:
			myMonster->Eat();
			break;
		case sleep:
			myMonster->Sleep();
			break;
		case play:
			ret = myMonster->Play();
			break;
		case excercise:
			ret = myMonster->Excercise();
			break;
		}
		return ret;
	}
	void Run() {
		SetMonster();
		while (1) {
			int a = console.PrintMenu();
			if (a < 0 || a > 4) a = 5;
			if (! Choose((act)a)) break;
		}
	}
	~Simulator() {
		delete myMonster;
	}
};

int main() {
	Simulator s;
	s.Run();
}
#endif