#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
#include "Order.h"
class UniversityManager : public Person, private Employee {
private:
	Employee employee;
public:
	/* Constructors */
	UniversityManager() {};
	UniversityManager(string name, string surname, string password) : Person(name, surname, password) {};
	/* End Constructors */

	void setEmployee(Employee empl)
	{
		this->employee = empl;
	}
	Employee getEmployee()
	{
		return Employee(this->employee);
	}
	void HumanStatus() override
	{
		cout << "Call this human if you have any trouble" << endl;
	}
	void showOrder(Order* ord)
	{
		for (int i = 0; i < ord->getApplications().size(); i++)
		{
			ord->getApplications()[i].print_information();
		}
	};
	void changeStatus(int number_app, string status_ordr, Student* cl, Order* ord)
	{
		vector<OrderStruct> orders = ord->getApplications();
		if (status_ordr == "Approve") {
			for (int i = 0; i < orders.size(); i++)
			{
				if (orders[i]._id == number_app)
				{
					orders[i].status = status_ordr;
					ord->changeOrder(orders[i], i);
					cl->setMoney(cl->getMoney() - orders[i].price);
					return;
				}
			}
		}
		else if (status_ordr == "Reject")
		{
			for (int i = 0; i < orders.size(); i++)
			{
				if (orders[i]._id == number_app)
				{
					orders[i].status = status_ordr;
					ord->changeOrder(orders[i], i);
					return;
				}
			}
		}
	};
	UniversityManager operator--() {
		this->salary = salary - 5000;
		return (*this);
		cout << this->employeeName << " money was reduced" << endl;
	}
	UniversityManager operator++() {
		this->salary += 1000;
		return (*this);
		cout << "WOW! You raised wage" << endl;
	}
};