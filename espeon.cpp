#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "psychic.h"
#include "espeon.h"

using namespace std;

Espeon::Espeon(){
	event_type = 2;
	poke_type = 5;
	species = "Espeon";
}

int Espeon::num_espeon_collected =0; 
int Espeon::espeon_achieved =0; //when stage 2 is acheived
int Espeon::espeon_stage =0;
bool Espeon::espeon_stage_2 = false; //flag so stage1 function wont turn it back into stage 1;

int Espeon::get_num_espeon_collected(){
	return num_espeon_collected;
}

void Espeon::set_num_espeon_collected(int a){
	num_espeon_collected += a;
}

int Espeon::get_espeon_achieved(){
	return espeon_achieved;
}

void Espeon::set_espeon_achieved(int a){
	espeon_achieved = a;
}

int Espeon::get_espeon_stage(){
	return espeon_stage;
}

void Espeon::set_espeon_stage(int a){
	espeon_stage = a;
}

bool Espeon::get_espeon_stage_2(){
	return espeon_stage_2;
}

void Espeon::set_espeon_stage_2(bool a){
	espeon_stage_2 = a;
}


