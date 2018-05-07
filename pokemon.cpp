#include <iostream>
#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"

using namespace std;

int Pokemon::get_poke_type() const{ ///give access through event rename etc...
	return poke_type;
}

void Pokemon::set_poke_type(int a){
	poke_type = a;
}

string Pokemon::get_species() const{
	return species;
}

void Pokemon::set_species(string a){
	species = a;
}


///////////////////////////////////////////////////////////////////////////////////


int Pokemon::get_chance() const{
	return 65;
}

int Pokemon::get_stones() const{

}

int Pokemon::get_pokeballs() const{

}

