#pragma once
#include <iostream>
#include <string>

using namespace std;

class Psychic: public Pokemon{

protected:
	int chance;

public:
	Psychic();
	int get_chance();

};