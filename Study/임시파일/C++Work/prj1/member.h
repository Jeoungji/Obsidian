#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <string>

using namespace std;

class Member {
public: // 접근 제어자
    int num;
    std::string name;


    void printInfo() {
        cout << "num : " << num << endl;
        cout << "name : " << name << endl;
    }
};

#endif // MEMBER_H_INCLUDED
