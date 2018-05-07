#pragma once
#include <iostream>
#include <string>

using namespace std;

class Flying: public Pokemon{

protected:
	int chance;

public:
	Flying();
	int get_chance();

};