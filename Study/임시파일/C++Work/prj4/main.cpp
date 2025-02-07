#include <iostream>
#include <string>

using namespace std;

static int num_of_student = 1;

class Student{

    typedef enum  Subject{
        Korean,
        English,
        Math
    } Subject;

    int number;
    string name;
    string tel_number;
    int score[3];
    int total;

public:
    void Set_Student(int num_, string name_) {
        if (num_ < 1) return;
        number = num_;
        name = name_;
    }

    void Set_Score(int korean, int english, int math) {
        if (korean < 0 || english < 0 || math < 0) return;

        score[Korean] = korean;
        score[English] = english;
        score[Math] = math;
        total = score[Korean] + score[English] + score[Math];
     }

     void Set_telNumber(string telnum) {
        tel_number = telnum;
     }

     int Get_Number() {return number;}
     int Get_totalScore(void) {return total;}

     void Print_totalScore(void) {
        cout << name << " : " << total << endl;
     }
     void Print_Info_All(void) {
        cout << "number : " << number << endl;
        cout << "name : " << name << endl;
        cout << "telephone : " << tel_number << endl;
        cout << "score : " << score[Korean] << " " <<  score[English] << " " << score[Math] << endl;
        cout << "total score : " << total << endl;
     }
};



class AddressBook {

    Student *students[10] = {nullptr};

    bool IsitNum(int num) {
        for (int i = 0; i < 10; ++i) {
            if (students[i] == nullptr) continue;
            if (students[i]->Get_Number() == num) return true;
        }
        return false;
    }
    int EmptySpace() {
        for (int i = 0; i < 10; ++i) {
            if (students[i] == nullptr) return i;
        }
        return -1;
    }
public:
    void Add(string name, string tel) {
        int space = EmptySpace();
        if (space == -1) {
            cout << "book is full" << endl;
            return;
        }
        students[space] = new Student;
        students[space]->Set_Student(num_of_student++, name);
        students[space]->Set_Score(0,0,0);
        students[space]->Set_telNumber(tel);
    }
    void Search(int num) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        cout << "Inforamtion" << endl;
        students[num-1]->Print_Info_All();
        cout << endl;
    }
    void ChangeTelephone(int num, string telephone) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        students[num-1]->Set_telNumber(telephone);
    }
    void Delete(int num) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        delete students[num-1];
        students[num-1] = nullptr;
    }
    void PrintAll() {
        cout << "Inforamtion" << endl;
        for (int i = 0; i < 10; ++i) {
            if (students[i] == nullptr) continue;
            students[i]->Print_Info_All();
            cout << endl;
        }
        cout << endl;
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

    while(!(command <'1' || command > '5')) {
        PrintMenu();
        cin >> command;

        switch (command) {
        case '1':
            cout << "name : ";
            cin >> name;
            cout << "telephone number : ";
            cin >> str;
            book.Add(name, str);
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
