#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "flying.h"

using namespace std;

Flying::Flying(){
	chance = 50;
}

int Flying::get_chance(){
	return chance;
}