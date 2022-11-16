#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"

class Cities {
private:
	CitiesStruct* cities;
	long int size_struct;
public:
	Cities() {};
	Cities(CitiesStruct* ts, int str_size) {
		cities = new CitiesStruct[size_struct];
		cities = ts;
		size_struct = str_size;
	}

	void SetCities(CitiesStruct* cities) { this->cities = cities; }
	CitiesStruct* getCities() {
		return this->cities;
	}

	void setSizeOfStruct(int _size) {
		this->size_struct = _size;
	}
	int getSizeOfStruct() {
		return this->size_struct;
	}
};