#include "singletone.h"
#include <iostream>

using namespace std;

Singletone Singletone::st;

Singletone& Singletone::getInstance() {
	return st;
}
void Singletone::setA(int num) {
	a = num;
}
int Singletone::getA() {
	return a;
}