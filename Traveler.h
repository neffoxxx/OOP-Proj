#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
#include "Expectant.h"
class Traveler : public Expectant {
private:
	string fullname;
	int passp_id;
public:
	void RoleAbout() {
		cout << "You've been approved like traveler" << endl;
	}
};
