#pragma once
#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Location{ //object we create is called grid
protected:
	Event ***map;
	int rows;
	int cols;

public:
	Location(int, int);
	Location(const Location &);
	void operator=(const Location &);
	Event ***get_map() const;
	
	~Location();
};
