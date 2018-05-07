#pragma once
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

class Pokemon: public Event{

protected:

	int poke_type;
	string species;

public:

	int get_poke_type() const;
	void set_poke_type(int); //need this?
	string get_species() const;
	void set_species(string);


/////////////////////////////////////////////////////////////////////////////////////////


	virtual int get_chance() const;
	int get_stones() const;
	int get_pokeballs() const;


};