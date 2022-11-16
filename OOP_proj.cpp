#include <iostream>
#include <Windows.h>
#include "Person.h"
#include "Student.h"
#include "Status.h"
#include "Employee.h"
#include "Expectant.h"
#include "Traveler.h"
#include "Denied.h"
#include "UniversityManager.h"
#include "University.h"
#include "Cities.h"
#include "TraidUnionCatalogue.h"
using namespace std;
template <typename T>
T calcPercent(T number, int percent)
{
	return number * percent / 100;
}

void showPersonStatus(class Person person) {
	person.HumanStatus();
}

int main()
{
	CitiesStruct c[5] = {
	CitiesStruct{1, "Lviv", 700},
	CitiesStruct{2, "Kyiv", 950},
	CitiesStruct{3, "Vinnytsya", 250},
	CitiesStruct{4, "Ternopil", 300},
	CitiesStruct{5, "Chernivtsi", 400}
	};
	Cities cities = Cities(c, size(c));
	TradeUnionCatalogue catalogue(cities);
	int number_menu = 0, number_admin = 0, number_wagem = 0, number_city, number_order;
	string name, surname, password, pasp_id, choice_status, choice;
	Status status[3]{
			Status{"Approve"},
			Status{"Reject"},
			Status{"Inform"},
	};
	Expectant* newRole = new Expectant();

	cout << "Welcome to the Travel network." << endl;
	cout << "Enter your name, surname and password." << endl;

	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Password: ";
	cin >> password;

	Student client(name, surname, password, cities);
	Order ord(client.getFullName(), pasp_id);

	cout << endl << "Succesful login, " << client.getFullName() << endl << endl;
	while (number_menu != EXIT)
	{
		cout << endl << "Please, choose the option:" << endl;
		cout << SHOW_CITIES_CATALOGUE << ". Show catalogue" << endl;
		cout << MY_BALANCE << ". Show my balance" << endl;
		cout << CHOOSE_CITY << ". Choice cities" << endl;
		cout << SHOW_CHOICES_CITIES << ". Selected city" << endl;
		cout << CREATE_ORDER << ". Create order" << endl;
		cout << SHOW_ORDER_CLIENT << ". Show order" << endl;
		if (client.is_admin())
		{
			cout << ADMIN_PANEL << ". Admin panel" << endl;
		}
		cout << RE_ENTER_PASS << ". Re-enter password" << endl;
		cout << EXIT << ". Exit" << endl << endl;

		cout << "Enter choice: ";
		cin >> number_menu;

		if (number_menu == SHOW_CITIES_CATALOGUE)
		{
			catalogue.ShowCities();
		}
		else if (number_menu == MY_BALANCE)
		{
			cout << "Your Balance: " << client.getMoney() << " UAH" << endl;
		}
		else if (number_menu == CHOOSE_CITY)
		{
			cout << "Enter city number: ";
			cin >> number_city;
			CitiesStruct country_client = client.getCitiesByNumber(number_city);
			cout << endl << "You choice: " << endl;

			country_client.select_city();
			client.setChoiceClientCity(country_client);
		}
		else if (number_menu == SHOW_CHOICES_CITIES)
		{
			client.getChoiceClientCity().select_city();
		}
		else if (number_menu == CREATE_ORDER)
		{
			cout << "Do you want confirm order? (Y/n) ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				cout << "Please, enter your Pasport ID: ";
				cin >> pasp_id;
				client.SetPassport(pasp_id);

				cout << "..." << endl << endl;

				ord.setCities(cities);
				Sleep(1000);
				ord.createOrder(
					OrderStruct{
					  ord.getApplications().size() + 1,
					  client.getChoiceClientCity(),
					  client.getFullName(),
					}
				);

				cout << "Thank you for the order! If you have any questions, call 911." << endl << endl;
				cout << "Your check" << endl << endl;
				ord.getApplications()[ord.getApplications().size() - 1].print_information();
				cout
					<< "UAH " << client.getChoiceClientCity().price
					<< " if accepted, it will be removed from your balance."
					<< endl << endl;
				client.setApplicat(ord);
			}
		}
		else if (number_menu == SHOW_ORDER_CLIENT)
		{
			client.showOrder();
		}
		else if (number_menu == ADMIN_PANEL) {
			if (client.is_admin())
			{
				UniversityManager admin(name, surname, password);
				University univer(&admin);
				Employee emple;
				while (number_admin != EXIT_ADMIN)
				{
					cout << "Greetings, " << univer.getFullName() << " Admin" << endl << endl;
					cout << "Please, choose the option:" << endl;
					cout << SHOW_ORDER_ADMIN << ". Show orders" << endl;
					cout << CHANGE_STATUS_APPLICATION << ". Change order status" << endl;
					cout << EXIT_ADMIN << ". Exit admin panel" << endl << endl;

					cout << "Enter choice: ";
					cin >> number_admin;

					if (number_admin == EXIT_ADMIN)
					{
						number_menu = 0;
					}
					else if (number_admin == SHOW_ORDER_ADMIN)
					{
						admin.showOrder(&ord);
					}
					else if (number_admin == CHANGE_STATUS_APPLICATION)
					{
						cout << "Enter number application: ";
						cin >> number_order;
						cout << "Enter status (Approve, Reject, Inform: ";
						cin >> choice_status;
						if (choice_status == "Approve")
						{
							Expectant* traveler = new Traveler();
							newRole = &status[1];
							newRole->RoleAbout;

						}
						else if (choice_status == "Reject")
						{
							showPersonStatus(&newRole);
							showPersonStatus(status[2]);
							Expectant* rejected = new Denied();
							showPersonStatus(*rejected);
						}
						else if (choice_status == "Inform")
						{
							newRole = &status[3];
							newRole->RoleAbout();
							Informed info;
							newRole = (Expectant*)&info;
							newRole->RoleAbout();
							newRole = (Expectant*)&status[2];
							newRole->RoleAbout();
							/*
							newRole = new Inform();
							newRole->RoleAbout();
							delete RoleAbout;
							*/
						}
						admin.changeStatus(number_order, choice_status, &client, &ord);
					}
				}
			}
			else if (number_admin == SALARY_REDACT) {
				UniversityManager adm;
				cout << ADD_WAGE << ". Add wage for yourself" << endl;
				cout << REDUCE_WAGE << ". Reduce wage" << endl;
				if (number_admin == ADD_WAGE) {
					adm++;
					calcPercent(500, 25);
				}
				else if (number_admin == REDUCE_WAGE) {
					adm--;
				}
			}
			else
			{
				cout << "You shouldn't have seen it" << endl;
			}
		}
		else if (number_menu == RE_ENTER_PASS)
		{
			cout << "Enter new Password: ";
			cin >> password;
			client.setPassword(password);
		}
	}
}

