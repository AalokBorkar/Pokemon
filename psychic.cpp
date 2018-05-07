#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "psychic.h"

using namespace std;

Psychic::Psychic(){
	chance = 25;
}

int Psychic::get_chance(){
	return chance;
}