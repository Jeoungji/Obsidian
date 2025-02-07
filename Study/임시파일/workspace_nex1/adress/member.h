#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED
//vo
#include <iostream>
#include <cstring>
using namespace std;

class Member{
    int num;  //자동할당
    string name;
    string tel;

public:
    static int cnt;
    Member(){}
    Member(string name, string tel){
        num = ++cnt;
        this->name = name;
        this->tel = tel;
    }
    Member(int num, string name, string tel) {
        this->num = num;
        this->name = name;
        this->tel = tel;
    }
    int getNum(){
        return num;
    }

    string getName(){
        return name;
    }

    string getTel(){
        return tel;
    }

    void setTel(string tel){
        this->tel = tel;
    }

    void setName(string name) {
        this->name = name;
    }

    void setNum(int num) {
        this->num = num;
    }

};
int Member::cnt = 0;
#endif // MEMBER_H_INCLUDED
