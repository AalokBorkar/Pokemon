#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "rock.h"
#include "geodude.h"

using namespace std;

Geodude::Geodude(){
	event_type = 2;
	poke_type = 0;
	species = "Geodude";
}

int Geodude::num_geodude_collected =0; //don't need accessor for static var - just call using scope 
int Geodude::geodude_achieved =0; //when stage 2 is acheived
int Geodude::geodude_stage =0;
bool Geodude::geodude_stage_2 =false; //flag so stage1 function wont turn it back into stage 1;

int Geodude::get_num_geodude_collected(){
	return num_geodude_collected;
}

void Geodude::set_num_geodude_collected(int a){
	num_geodude_collected += a;
}

int Geodude::get_geodude_achieved(){
	return geodude_achieved;
}

void Geodude::set_geodude_achieved(int a){
	geodude_achieved = a;
}

int Geodude::get_geodude_stage(){
	return geodude_stage;
}

void Geodude::set_geodude_stage(int a){
	geodude_stage = a;
}

bool Geodude::get_geodude_stage_2(){
	return geodude_stage_2;
}

void Geodude::set_geodude_stage_2(bool a){
	geodude_stage_2 = a;
}

