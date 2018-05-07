#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rock: public Pokemon{

protected:
	int chance;

public:
	Rock();
	int get_chance();
	
};