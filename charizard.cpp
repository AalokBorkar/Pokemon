#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "flying.h"
#include "charizard.h"

using namespace std;

Charizard::Charizard(){
	event_type = 2;
	poke_type = 2;
	species = "Charizard";
}

int Charizard::num_charizard_collected =0; 
int Charizard::charizard_achieved =0;
int Charizard::charizard_stage =0;
bool Charizard::charizard_stage_2 =false;

int Charizard::get_num_charizard_collected(){
	return num_charizard_collected;
}
void Charizard::set_num_charizard_collected(int a){
	num_charizard_collected += a;
}

int Charizard::get_charizard_achieved(){
	return charizard_achieved;
}
void Charizard::set_charizard_achieved(int a){
	charizard_achieved = a;
}

int Charizard::get_charizard_stage(){
	return charizard_stage;
}
void Charizard::set_charizard_stage(int a){
	charizard_stage = a;
}

bool Charizard::get_charizard_stage_2(){
	return charizard_stage_2;
}
void Charizard::set_charizard_stage_2(bool a){
	charizard_stage_2 = a;
} //flag so stage1 function wont turn it back into stage 1;