#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cave: public Event{

public:
	Cave(); //init type to 1
	int get_stones() const;



	//////////////////////USELESS BELOW////////////////////////////
	int get_poke_type() const; //pokemon type for pokemon class and children of <- that class
	void set_poke_type(int);

	string get_species() const;
	void set_species(string);

	int get_chance() const;

	int get_pokeballs() const;

};

