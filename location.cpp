#include <iostream>
#include <iostream>
#include <string>
#include "event.h"
#include "pokestop.h"
#include "cave.h"
#include "pokemon.h"
#include "location.h"

using namespace std;

Location::Location(int prows, int pcols){
	rows = prows;
	cols = pcols;
	map = new Event**[rows];
	for(int i =0; i < rows; i++){   //creating the board
		map[i] = new Event*[cols];
		for(int a =0; a < cols; a++){
			map[i][a] = NULL;  //Init every position to NULL;
		}
	}
}
	
Location::Location(const Location &l){//copy constructor
	rows = l.rows;
	cols = l.cols;
	map = new Event**[rows];
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			map[i] = new Event*[cols];
		}
	}
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			if(l.map[i][a]->get_event_type() == 0){
				map[i][a] = new Pokestop;
							}
			else if(l.map[i][a]->get_event_type() == 1){
				map[i][a] = new Cave;
			}
			else if(l.map[i][a]->get_event_type() == 2){
				map[i][a] = new Pokemon;
			}
		}
	}
}


void Location::operator=(const Location &l){//copy constructor
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){ //deletes all the events on the map
			delete map[i][a]; //delete each individual event on map
		}
	}
	for(int i =0; i < rows; i++){
		delete [] map[i];
	}
	delete [] map;
	rows = l.rows;
	cols = l.cols;
	map = new Event**[rows];
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			map[i] = new Event*[cols];
		}
	}
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			if(l.map[i][a]->get_event_type() == 0){
				map[i][a] = new Pokestop;
							}
			else if(l.map[i][a]->get_event_type() == 1){
				map[i][a] = new Cave;
			}
			else if(l.map[i][a]->get_event_type() == 2){
				map[i][a] = new Pokemon;
			}
		}
	}
}

Event*** Location::get_map() const{
	return map;
}

Location::~Location(){
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){ //deletes all the events on the map
			delete map[i][a]; //delete each individual event on map
		}
	}

	for(int i =0; i < rows; i++){
		delete [] map[i];
	}

	delete [] map;
}
