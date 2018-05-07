#include <iostream>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "rock.h"
#include "onix.h"

using namespace std;


Onix::Onix(){
	event_type = 2;
	poke_type = 1;
	species = "Onix";

}

int Onix::num_onix_collected =0; //don't need accessor for static var - just call using scope 
int Onix::onix_achieved =0; //when stage 2 is acheived
int Onix::onix_stage =0;
bool Onix::onix_stage_2 =false; //flag so stage1 function wont turn it back into stage 1;

int Onix::get_num_onix_collected(){
	return num_onix_collected;
}

void Onix::set_num_onix_collected(int a){
	num_onix_collected += a;
}

int Onix::get_onix_achieved(){
	return onix_achieved;
}

void Onix::set_onix_achieved(int a){
	onix_achieved = a;
}

int Onix::get_onix_stage(){
	return onix_stage;
}
void Onix::set_onix_stage(int a){
	onix_stage = a;
}
bool Onix::get_onix_stage_2(){
	return onix_stage_2;
}
void Onix::set_onix_stage_2(bool a){
	onix_stage_2 = a;
}