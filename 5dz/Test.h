#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	static int nCount;

	Test();
	Test(const Test& other); //copy
	~Test();
};

class Child : public Test {
public:
	Child();
	~Child();
};

class Aggregate {
	Test m_objTest;
public:
	Aggregate();
	~Aggregate();
};

template <typename T>
class AggregateT
{
	T m_obj;

public:
	AggregateT();
	~AggregateT();
};

template <typename T>
AggregateT<T>::AggregateT()
{
	cout << "Construct AggregateT" << endl;
}

template <typename T>
AggregateT<T>::~AggregateT()
{
	cout << "Distructor AggregateT" << endl;
}