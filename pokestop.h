#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pokestop: public Event{

public:
	Pokestop(); //init type to 0
	int get_pokeballs() const;


	/////////////////////////////////////////////////
	int get_poke_type() const;

	//pokemon type for pokemon class and children of <- that class
	void set_poke_type(int);

	int get_stones() const;

	string get_species() const;
	void set_species(string);
	int get_chance() const;

};