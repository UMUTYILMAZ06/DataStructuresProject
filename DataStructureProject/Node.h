#pragma once
#include <string>
#include <iostream>
#include<ostream>

using namespace std;
class Node
{
public:
	string data;
	Node* next;
	Node* Smallnext;

	int counter;

	Node() :next(nullptr), Smallnext(nullptr), counter(0) {}
	Node(const string& na) :next(nullptr), Smallnext(nullptr), data(na), counter(0)
	{
	}

	void print()const {
		cout << this->data << "->";
	}
	friend ostream& operator<< (ostream& out, const Node& obj);
};


ostream& operator<<(ostream& out, const Node& obj)
{
	out << obj.data << string("->");
	return out;
}