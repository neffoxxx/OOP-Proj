#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
class Error : public exception {
	string err;
public:
	Error(string error_text) :
		err(error_text) {};
	string geterror()
	{
		return err;
	}
};
class Order {
private:
	string fullname;
	string passport_id;
	Cities city_order;
	Student* stud_order;
	vector<OrderStruct> order;
public:
	Order() {};
	Order(string fullname, string pass_id) {
		this->fullname = fullname;
		this->passport_id = pass_id;
	};
	string getNameOrd() { return this->fullname; };

	void setOrder(OrderStruct ordr_struct) {
		this->order.push_back(ordr_struct);
	};
	void changeOrder(OrderStruct ord_str, int num) {
		this->order[num] = ord_str;
	};
	vector<OrderStruct> getApplications() { return this->order; };

	void setCities(Cities cities) { this->city_order = cities; };
	Student* getClient() { return this->stud_order; }
	void setClient(Student* client) { this->stud_order = client; }

	void read_file(string fullname, const string filepath) {
		ifstream read(filepath, ios::app);
		try
		{
			if (read.is_open())
			{
				read >> fullname;
			}
			else if (!read.is_open())
			{
				throw Error("cant open file");
			}
		}
		catch (Error e)
		{
			cout << e.geterror() << endl;
		}
		read.close();
	}
	void file_txt(OrderStruct order, const string filepath)
	{
		ofstream file(filepath, ios::app);
		file
			<< "Order ¹: " << order._id << endl
			<< "Your full name: " << order.fullname << endl
			<< "Your passport ID: " << order.pasport_id << endl
			<< "Trip information:" << endl
			<< "City: " << order.city.city_id << endl
			<< "Hotel: " << order.trip.hotel << endl
			<< "Days of stay and departure: " << order.trip.days << " | " << order.trip.departure << endl
			<< "Your price: " << order.city.price + order.trip.price << endl;
		file.close();
	}

	void createOrder(OrderStruct order) {
		file_txt(order, "order.txt");
		setOrder(order);
	};
};