#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "flying.h"
#include "rayquaza.h"

using namespace std;

Rayquaza::Rayquaza(){
	event_type = 2;
	poke_type = 3;
	species = "Rayquaza";

}

int Rayquaza::num_rayquaza_collected =0; 
int Rayquaza::rayquaza_achieved =0; //when stage 2 is acheived
int Rayquaza::rayquaza_stage =0;
bool Rayquaza::rayquaza_stage_2 = false; //flag so stage1 function wont turn it back into stage

int Rayquaza::get_num_rayquaza_collected(){
	return num_rayquaza_collected;
}

void Rayquaza::set_num_rayquaza_collected(int a){
	num_rayquaza_collected += a;
}

int Rayquaza::get_rayquaza_achieved(){
	return rayquaza_achieved;
}

void Rayquaza::set_rayquaza_achieved(int a){
	rayquaza_achieved = a;
}

int Rayquaza::get_rayquaza_stage(){
	return rayquaza_stage;
}

void Rayquaza::set_rayquaza_stage(int a){
	rayquaza_stage = a;
}

bool Rayquaza::get_rayquaza_stage_2(){
	return rayquaza_stage_2;
}

void Rayquaza::set_rayquaza_stage_2(bool a){
	rayquaza_stage_2 = a;
}
