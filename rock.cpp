#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "event.h"
#include "pokemon.h"
#include "rock.h"

using namespace std;

Rock::Rock(){
	chance = 75;
}

int Rock::get_chance(){
	return chance;
}