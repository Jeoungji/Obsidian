#pragma once

class Singletone {
	static Singletone st;
	int a;
	Singletone() {}
public:
	static Singletone& getInstance();
	void setA(int a);
	int getA();
};

