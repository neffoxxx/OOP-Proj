#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "struct.h"
#include "Expectant.h"
class Denied : public Expectant {
private:
	string fullname;
public:
	void RoleAbout() {
		cout << "You've been denied" << endl;
	}
};