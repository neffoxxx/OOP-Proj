#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
class Student : public Person {
private:
	string fullname;
	string passport_id;
	CitiesStruct choice_city;
	Cities city_client;
	Order zamovl;
public:
	Student() {};
	Student(string name, string surname, string password, Cities ctes) : Person(name, surname, password) {
		this->city_client = ctes;
	};

	/* Setters and Getters */
	string GetName() { return this->fullname; };
	string getPassportId() { return this->passport_id; };

	void SetName(string fullname) { this->fullname = fullname; };
	void SetPassport(string passport_id) { this->passport_id = passport_id; };
	void setApplicat(Order apl) { this->zamovl = apl; }
	Order getApplicat() { return this->zamovl; }

	CitiesStruct getChoiceClientCity() { return this->choice_city; };
	void setChoiceClientCity(CitiesStruct choice_city) { this->choice_city = choice_city; };
	/* End Setters and Getters */

	void HumanStatus() override
	{
		cout << "Human is definitely student-customer who wants to travel" << endl;
	}
	CitiesStruct getCitiesByNumber(int number) {
		CitiesStruct* c = city_client.getCities();
		for (int i = 0; i < city_client.getSizeOfStruct(); i++) {
			if (c[i].city_id == number) {
				return c[i];
			};
		};
	};
	void showCities() {
		CitiesStruct* c = city_client.getCities();
		for (int i = 0; i < city_client.getSizeOfStruct(); i++) {
			c[i].select_city();
		};
	};
	void showOrder() {
		for (int i = 0; i < this->zamovl.getApplications().size(); i++)
		{
			this->zamovl.getApplications()[i].print_information();
		}
	}

};
