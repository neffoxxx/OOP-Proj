#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
class Expectant : public Person, public Student {
private:
	string fullname;
	int orderId;
public:
	Expectant() {};
	Expectant(string fullname, int orderId) {
		this->fullname = fullname;
		this->orderId = orderId;
	};
	string GetFullname() { return this->fullname; };
	int getId() { return this->orderId; };

	string SetFullname(string fullname) { this->fullname = fullname; };
	int setId(int orderId) { this->orderId = orderId; };
	virtual void RoleAbout() {
		cout << "You've been approved like expectant" << endl;
	}
};

class Informed : public Expectant {
private:
	string fullname;
public:
	void RoleAbout() {
		cout << "You've been informed" << endl;
	}
};