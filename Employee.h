#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
class Employee : public Person {
protected:
	string employeeName;
	double salary = 8000;
public:

	/* Getters and Setters */

	void setRectorName(string name)
	{
		this->employeeName = name;
	}

	string getRectorName()
	{
		return string(this->employeeName);
	}

	double getSalary()
	{
		return this->salary;
	}
	/* End Getters and Setters */

};