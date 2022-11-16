#pragma once
#include <iostream>
#include <time.h>
#include "ClassProcessing.h"
using namespace std;

enum StartingMenu
{
	SHOW_CITIES_CATALOGUE = 1,
	MY_BALANCE = 2,
	CHOOSE_CITY = 3,
	SHOW_CHOICES_CITIES = 4,
	SHOW_ORDER_CLIENT = 5,
	CREATE_ORDER = 6,
	RE_ENTER_PASS = 7,
	ADMIN_PANEL = 8,
	SALARY_REDACT = 9,
	ADD_WAGE = 10,
	REDUCE_WAGE = 11,
	EXIT = 12
};
enum AdminMenu
{
	SHOW_ORDER_ADMIN = 10,
	CHANGE_STATUS_APPLICATION = 11,
	EXIT_ADMIN = 12
};

struct CitiesStruct {
	int city_id;
	string city;
	long price;
	void select_city() {
		cout << endl << "Your selected city: " << city_id << endl
			<< "Your price: " << price << endl;
	}
};

struct TripStruct {
	long int price;
	string hotel;
	int days;
	string departure;

	void trip_struct() {
		cout << endl << "Price: " << price << endl
			<< "Hotel name: " << hotel << endl
			<< "Days of stay: " << days << endl
			<< "Departure: " << departure << endl;
	}
};


struct OrderStruct {
	unsigned long long _id;
	CitiesStruct city;
	string fullname;
	TripStruct trip;
	string pasport_id;
	string status;
	long price = city.price + trip.price;
	void print_information() {
		cout
			<< "Order ¹: " << _id << endl
			<< "Your full name: " << fullname << endl
			<< "Your passport ID: " << pasport_id << endl
			<< "Trip information:" << endl
			<< "City: " << city.city << endl
			<< "Hotel: " << trip.hotel << endl
			<< "Days of stay and departure: " << trip.days << " | " << trip.departure << endl
			<< "Your price: " << price << endl;
	}
};
