#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
#include "Cities.h"
class TradeUnionCatalogue {
private:
	Cities cities;
public:
	TradeUnionCatalogue(Cities cts) {
		this->cities = cts;
	}
	void ShowCities() {
		CitiesStruct* ts = cities.getCities();
		cout << "Choose city: \n";
		for (int i = 0; i < cities.getSizeOfStruct(); i++)
		{
			ts[i].select_city();
		};
	};
};

