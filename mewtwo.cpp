#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "psychic.h"
#include "mewtwo.h"

using namespace std;

Mewtwo::Mewtwo(){
	event_type = 2;
	poke_type = 4;
	species = "Mewtwo";

}

int Mewtwo::num_mewtwo_collected =0; //don't need accessor for static var - just call using scope 
int Mewtwo::mewtwo_achieved =0; //when stage 2 is acheived
int Mewtwo::mewtwo_stage =0;
bool Mewtwo::mewtwo_stage_2 =false;

int Mewtwo::get_num_mewtwo_collected(){
	return num_mewtwo_collected;
}

void Mewtwo::set_num_mewtwo_collected(int a){
	num_mewtwo_collected += a;
}

int Mewtwo::get_mewtwo_achieved(){
	return mewtwo_achieved;
}

void Mewtwo::set_mewtwo_achieved(int a){
	mewtwo_achieved = a;
}

int Mewtwo::get_mewtwo_stage(){
	return mewtwo_stage;
}

void Mewtwo::set_mewtwo_stage(int a){
	mewtwo_stage = a;
}

bool Mewtwo::get_mewtwo_stage_2(){
	return mewtwo_stage_2;
}

void Mewtwo::set_mewtwo_stage_2(bool a){
	mewtwo_stage_2 = a;
}