// linked list

#if 0

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
	T* data;
	Node<T>* next;
public:
	Node(T data) {
		this->data = new T(data);
		next = nullptr;
	}
	~Node() {
		delete this->data;
	}
	Node* get_next() {
		return next;
	}
	void set_next(Node* next) {
		this->next = next;
	}
	T* get_data() {
		return data;
	}
};

template<typename T>
class MList {
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

public:
	void Insert(T data) {
		Node<T>* newstudent = new Node<T>(data);
		if (head == nullptr) {
			head = newstudent;
			tail = head;
		}
		else {
			tail->set_next(newstudent);
			tail = tail->get_next();
		}
		return;
	}

	T* Search(int num) {
		Node<T>* cur = head;
		while (cur != nullptr) {
			if (cur->get_data()->Get_Number() == num) {
				return cur->get_data();
			}
			cur = cur->get_next();
		}
		return nullptr;
	}

	void Delete(int num) {
		if (head == nullptr) return;

		Node<T>* cur = head;
		Node<T>* prev = nullptr;

		while (cur != nullptr) {
			if (cur->get_data()->Get_Number() != num) {
				prev = cur;
				cur = cur->get_next();
				continue;
			}
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
			return;
		}
	}

};



class Address {
	int number;
	string name;
	string tel_number;

public:
	static int counter;

	Address(string name, string telnumber)
		: number(counter++), name(name), tel_number(telnumber) {
	}

	void Set_Address(int num_, string name_) {
		if (num_ < 1) return;
		number = num_;
		name = name_;
	}

	void Set_telNumber(string telnum) {	tel_number = telnum; }

	int Get_Number() { return number; }

	void Print_Info_All(void) {
		cout << "number : " << number << endl;
		cout << "name : " << name << endl;
		cout << "telephone : " << tel_number << endl;
	}
};

int Address::counter = 1;

class AddressBookSystem {
	MList<Address> book;
	char command = '1';
	int num;
	string str, name;
	Address* ret;

	void PrintMenu() {
		cout << "--------------------" << endl;
		cout << "1. Add" << endl;
		cout << "2. Search" << endl;
		cout << "3. ChangeTelephone" << endl;
		cout << "4. Delete" << endl;
		cout << "5. PrintAll" << endl;
		cout << "--------------------" << endl;
		cin >> command;
	}
	void Insert() {
		cout << "name : ";
		cin >> name;
		cout << "telephone number : ";
		cin >> str;
		book.Insert(Address(name, str));
	}
	void Search() {
		cout << "Num : ";
		cin >> num;
		ret = book.Search(num);
		if (ret) ret->Print_Info_All();
	}
	void ChangeTelephone() {
		cout << "Num : ";
		cin >> num;
		cout << "telephone number : ";
		cin >> str;
		ret = book.Search(num);
		if (ret) ret->Set_telNumber(str);
	}
	void Delete() {
		cout << "Num : ";
		cin >> num;
		book.Delete(num);
	}
	void PrintAll() {
		for (int i = 1; ; ++i) {
			ret = book.Search(i);
			if (!ret) break;
			ret->Print_Info_All();
		}
	}
public:
	void Run() {
		while (!(command < '1' || command > '5')) {
			ret = nullptr;
			PrintMenu();
			
			switch (command) {
			case '1':
				Insert();
				break;
			case '2':
				Search();
				break;
			case '3':
				ChangeTelephone();
				break;
			case '4':
				Delete();
				break;
			case '5':
				PrintAll();
				break;
			default:
				cout << "Exit" << endl;
				break;
			}
		}
	}
};

int main()
{
	AddressBookSystem system;
	system.Run();
	
	return 0;
}
#endif