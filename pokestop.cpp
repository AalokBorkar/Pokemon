#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "event.h"
#include "pokestop.h"

using namespace std;

Pokestop::Pokestop(){
	event_type =0;
}

int Pokestop::get_pokeballs() const{
	srand(time(NULL));
	int pokeballs = rand()%13;
	cout<<"You just got "<<pokeballs<<" pokeballs from the pokestop!"<<endl;
	return pokeballs;
}

///////////////////////////////////////////////////////////////////////////

string Pokestop::get_species() const{
}

void Pokestop::set_species(string){

}

int Pokestop::get_poke_type() const{

}

int Pokestop::get_stones() const{

}

//pokemon type for pokemon class and children of <- that class
void Pokestop::set_poke_type(int){

}

int Pokestop::get_chance() const{

}

