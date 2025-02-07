// linked list

#if 0

#include <iostream>
#include <string>

using namespace std;



class Student {
	int number;
	string name;
	string tel_number;

public:
	static int counter;

	Student(string name, string telnumber)
		: number(counter++), name(name), tel_number(telnumber) {
	}
	void Set_Student(int num_, string name_) {
		if (num_ < 1) return;
		number = num_;
		name = name_;
	}

	void Set_telNumber(string telnum) {
		tel_number = telnum;
	}

	int Get_Number() { return number; }

	void Print_Info_All(void) {
		cout << "number : " << number << endl;
		cout << "name : " << name << endl;
		cout << "telephone : " << tel_number << endl;
	}
};

int Student::counter = 1;

class Node {
	Student* student;
	Node* next;
public:
	Node(string name, string telnum) {
		student = new Student(name, telnum);
		next = nullptr;
	}
	~Node() {
		delete student;
	}
	Node* get_next() {
		return next;
	}
	void set_next(Node* next) {
		this->next = next;
	}
	Student* get_student() {
		return student;
	}
};

class AddressBook {
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	void Insert(string name, string tel) {
		Node* newstudent = new Node(name, tel);
		if (head == nullptr) {
			head = newstudent;
			tail = head;
		}
		else {
			tail->set_next(newstudent);
			tail = tail->get_next();
		}
		cout << name << " is " << tail->get_student()->Get_Number() << endl;
		return;
	}

	void Search(int num) {
		Node* cur = head;
		while (cur != nullptr) {
			if (cur->get_student()->Get_Number() == num) {
				cur->get_student()->Print_Info_All();
				return;
			}
			cur = cur->get_next();
		}
		cout << "Can't find " << num << endl;
	}
	void ChangeTelephone(int num, string telephone) {
		Node* cur = head;
		while (cur != nullptr) {
			if (cur->get_student()->Get_Number() == num) {
				cur->get_student()->Set_telNumber(telephone);
				cout << num << " change telephone num to " << telephone << endl;
				return;
			}
			cur = cur->get_next();
		}
	}
	void Delete(int num) {
		if (head == nullptr) return;

		Node* cur = head;
		Node* prev = nullptr;

		while (cur != nullptr) {
			if (cur->get_student()->Get_Number() == num) {
				if (prev == nullptr) {  // 가장 첫 데이터를 삭제
					head = cur->get_next();
					if (cur == tail) { // 데이터가 한개
						tail = nullptr;
					}
				}
				else {
					prev->set_next(cur->get_next());
				}
				delete cur;
				cout << "Delete " << num << endl;
				return;
			}
			prev = cur;
			cur = cur->get_next();
		}
		cout << "Can't find " << num << endl;
	}
	void PrintAll() {
		Node* cur = head;
		while (cur != nullptr) {
			cur->get_student()->Print_Info_All();
			cur = cur->get_next();
		}
	}

};

void PrintMenu() {
	cout << "--------------------" << endl;
	cout << "1. Add" << endl;
	cout << "2. Search" << endl;
	cout << "3. ChangeTelephone" << endl;
	cout << "4. Delete" << endl;
	cout << "5. PrintAll" << endl;
	cout << "--------------------" << endl;
}

int main()
{
	AddressBook book;
	char command = '1';
	int num;
	string str, name;

	while (!(command < '1' || command > '5')) {
		PrintMenu();
		cin >> command;

		switch (command) {
		case '1':
			cout << "name : ";
			cin >> name;
			cout << "telephone number : ";
			cin >> str;
			book.Insert(name, str);
			break;
		case '2':
			cout << "Num : ";
			cin >> num;
			book.Search(num);
			break;
		case '3':
			cout << "Num : ";
			cin >> num;
			cout << "telephone number : ";
			cin >> str;
			book.ChangeTelephone(num, str);
			break;
		case '4':
			cout << "Num : ";
			cin >> num;
			book.Delete(num);
			break;
		case '5':
			book.PrintAll();
			break;
		default:
			cout << "Exit" << endl;
			break;
		}
	}

	return 0;
}
#endif