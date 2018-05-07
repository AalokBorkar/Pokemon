#include <iostream>
#include <string>
#include "trainer.h"

using namespace std;

Trainer::Trainer(){
	num_pokeballs = 5;
	num_stones = 0;

}

void Trainer::set_num_pokeballs(int a){
	num_pokeballs = a;
}

int Trainer::get_num_pokeballs() const{
	return num_pokeballs;
}

void Trainer::set_num_stones(int a){
	num_stones = a;
}

int Trainer::get_num_stones() const{
	return num_stones;
}