#include <iostream>

#include "member.h"

using namespace std;

int main()
{
    Member m;
    m.num = 10;
    m.name = "ameicano";
    m.printInfo();


    Member m2;
    m2.num = 20;
    m2.name = "latte";
    m2.printInfo();

    Member *mp = new Member();
    mp->num = 30;
    mp->name = "coke";
    mp->printInfo();

    delete mp;

    return 0;
}
