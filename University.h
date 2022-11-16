#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
#include "UniversityManager.h"
class University {
private:
	UniversityManager* admin;
	string name_tours;
	string lastname_tours;
public:
	University(UniversityManager* admin = nullptr) :admin(admin) {}

	string getFullName() {
		return this->name_tours + " " + this->lastname_tours;
	}
};