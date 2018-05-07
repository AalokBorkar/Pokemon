#include <iostream>
#include <string>
#include "event.h"

using namespace std;

int Event::get_event_type() const{
	return event_type;
}

void Event::set_event_type(int a){
	event_type = a;
}

void Event::set_show(bool a){
	show = a;
}

bool Event::get_show() const{
	return show;
}

Event::~Event(){
	
}