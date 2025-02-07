// static  array

#include <iostream>
#include <string>

using namespace std;

#if 0
static int num_of_student = 1;

class Student {

    typedef enum  Subject {
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

    int Get_Number() { return number; }
    int Get_totalScore(void) { return total; }

    void Print_totalScore(void) {
        cout << name << " : " << total << endl;
    }
    void Print_Info_All(void) {
        cout << "number : " << number << endl;
        cout << "name : " << name << endl;
        cout << "telephone : " << tel_number << endl;
        cout << "score : " << score[Korean] << " " << score[English] << " " << score[Math] << endl;
        cout << "total score : " << total << endl;
    }
};



class AddressBook {

    Student* students[10] = { nullptr };

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
        students[space]->Set_Score(0, 0, 0);
        students[space]->Set_telNumber(tel);
    }
    void Search(int num) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        cout << "Inforamtion" << endl;
        students[num - 1]->Print_Info_All();
        cout << endl;
    }
    void ChangeTelephone(int num, string telephone) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        students[num - 1]->Set_telNumber(telephone);
    }
    void Delete(int num) {
        if (!IsitNum(num)) {
            cout << "not found" << endl;
            return;
        }
        delete students[num - 1];
        students[num - 1] = nullptr;
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

    while (!(command < '1' || command > '5')) {
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
#endif

#if 0
class Member {
    static int cnt;
    int num;
    string name;
    string tel;
public:
    Member() {}
    Member(string name, string tel) {
        num = ++cnt;
        this->name = name;
        this->tel = tel;
    }
    int getNum() {
        return num;
    }
    string getName() {
        return name;
    }
    string getTel() {
        return tel;
    }
    void setTel(string tel) {
        this->tel = tel;
    }
};

int Member::cnt = 0;

class AddrProcess {
    Member* datas[10];
    int cnt;
public:
    AddrProcess() :cnt(0) {}
    ~AddrProcess() {
        for (int i = 0; i < cnt; ++i)
            delete datas[i];
    }

    bool addMember(Member* m) {
        bool flag = true;
        if (cnt >= 9) {
            flag = false;
        }
        else {
            datas[cnt++] = m;
        }
        return flag;
    }

    int getByNum(int num) {
        for (int i = 0; i < cnt; ++i) {
            if (datas[i]->getNum() == num) {
                return i;
            }
        }
        return -1;
    }

    Member* getByIdx(int idx) {
        if (idx < 0) {
            return NULL;
        }
        return datas[idx];
    }

    int getCnt() {
        return cnt;
    }

    bool delMember(int idx) {
        if (idx < 0) return false;
          
        for (int i = idx; i < cnt - 1; ++i) {
            datas[i] = datas[i + 1];
        }
        --cnt;
        return true;
    }
};

class AddrService {
    AddrProcess pr;
public:
    // 추가
    void add() {
        string name, tel;
        cout << "멤버추가" << endl;
        cout << "name : ";
        cin >> name;
        cout << "tel : ";
        cin >> tel;
        bool flag = pr.addMember(new Member(name, tel));
        if (flag) {
            cout << "저장되었습니다." << endl;
        }
        else {
            cout << "공간이 부족합니다" << endl;
        }
    }
    // 검색
    void SearchMember() {
        int num;
        cout << "번호로 검색" << endl;
        cout << "num : ";
        cin >> num;
        Member* res = pr.getByIdx(pr.getByNum(num));
        if (res == NULL) {
            cout << "not found" << endl;
        }
        else {
            cout << "num : " << res->getNum() << endl;
            cout << "name : " << res->getName() << endl;
            cout << "telephone : " << res->getTel() << endl;
        }
    }
    // 수정
    void editMember() {
        cout << "수정" << endl;
        cout << "edit num :";
        int num;
        string tel;
        cin >> num;
        Member* res = pr.getByIdx(pr.getByNum(num));
        if (res == NULL) {
            cout << "not found" << endl;
        }
        else {
            cout << "new tel : ";
            cin >> tel;
            res->setTel(tel);
        }
    }
    // 삭제
    void delMember() {
        cout << "삭제" << endl;
        cout << "del num : ";
        int num;
        cin >> num;
        bool flag = pr.delMember(pr.getByNum(num));
        if (flag) {
            cout << "삭제 되었습니다" << endl;
        }
        else {
            cout << "삭제 실패" << endl;
        }
    }
    // 전체 출력
    void printMember() {
        for (int i = 0; i < pr.getCnt(); ++i) {
            Member* res = pr.getByIdx(i);
            cout << "num : " << res->getNum() << endl;
            cout << "name : " << res->getName() << endl;
            cout << "telephone : " << res->getTel() << endl << endl;;
        }
    }
};

class AddrMenu {
    AddrService service;
public:
    void run() {
        string str = "1.추가 2.검색 3.수정 4.삭제 5.전체출력 6.종료";
        bool flag = true;
        int m;
        while (flag) {
            cout << str << endl;
            cin >> m;
            switch (m) {
            case 1:
                service.add();
                break;
            case 2:cc
                service.SearchMember();
                break;
            case 3:
                service.editMember();
                break;
            case 4:
                service.delMember();
                break;
            case 5:
                service.printMember();
                break;
            case 6:
                flag = false;
                break;
            }
        }

    }
};

int main(void) {
    AddrMenu m;
    m.run();
    return 0;
}

#endif