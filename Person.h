#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "struct.h"
class Person {
private:
	string name;
	string surname;
	string password;
	long int money = 10000;
	string adminpassword = "adminka123";
public:
	Person() {};
	Person(string name, string surname, string password) {
		this->name = name;
		this->surname = surname;
		this->password = password;
	};
	string getPassword() { return this->password; };
	string getFullName() { return this->name + " " + this->surname; };

	void setName(string name) { this->name = name; };
	void setSurname(string surname) { this->surname = surname; };
	void setPassword(string password) { this->password = password; };

	long int getMoney() {
		return this->money;
	};
	void setMoney(long int money) {
		this->money = money;
	};

	virtual void HumanStatus()
	{
		cout << "Human is definitely tired and sleepy" << endl;
	}
	bool is_admin() { return this->password == this->adminpassword; };
};
