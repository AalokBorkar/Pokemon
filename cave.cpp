#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "event.h"
#include "cave.h"

using namespace std;

Cave::Cave(){
	event_type = 1;
}

int Cave::get_stones() const{
	srand(time(NULL));
	int stones = rand()%6;
	cout<<"You just got "<<stones<<" mega stones from the cave!"<<endl;
	return stones;
}




///////////////////////////////BELOW IS USELESS//////////////
int Cave::get_poke_type() const{

} //pokemon type for pokemon class and children of <- that class
void Cave::set_poke_type(int){

}
string Cave::get_species() const{

}
void Cave::set_species(string){
	
}
int Cave::get_chance() const{
	
}
int Cave::get_pokeballs() const{
}