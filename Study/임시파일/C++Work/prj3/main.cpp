#include <iostream>

using namespace std;

void swap1(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
}

void swap2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout << "*a : " << *a << endl;
    cout << "*b : " << *b << endl;
}

void swap3(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
}

int main()
{
    int a = 10. b = 20;
    swap1(a,b);
    cout << "swap1 °á°ú : a:" << a << "b"  << b <<endl;
    return 0;
}
