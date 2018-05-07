/******************************************************
** Program: Pokemon Go (c++)
** Author: Aalok Borkar
** Date: 05/27/2017
** Description: A simple turn based pokemon go simulator with AI features
** Input: User inputted choices
** Output: If you win the program or not
******************************************************/
#include <iostream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "location.h"
#include "trainer.h"
#include "event.h"
#include "pokemon.h"
#include "cave.h"
#include "pokestop.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include "geodude.h"
#include "onix.h"
#include "charizard.h"
#include "rayquaza.h"
#include "mewtwo.h"
#include "espeon.h"
#include "structs.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]){
	int play_again = 0;
	int iterator = 0;
	do{
		int choice;
		int ai;
		int rows, cols;
		bool game_over = false;
		srand(time(NULL));
		int debugging;
		debugging = get_dubugging();  //Variable declarations and initialization
		ai = get_ai();
		if(iterator == 0){
			rows = atoi(argv[1]);
			cols = atoi(argv[2]);
		}
		else{
			rows = rand()%5 + 5;
			cols = rand()%5 + 5;
		}
		valid_rows_int(rows, cols);
		Location grid(rows, cols);
		Position current, start;
		init_position(current, start, rows, cols);
		init_board(grid, current, start, rows, cols);
		Trainer ash;
		/////////////////////////////////////////////////////////////////////////////////////////actual implementation
		while(game_over == false){
			print_current_position(debugging, grid, current, start, rows, cols);
			print_inventory(ash);
			warning(grid, current, rows, cols); //alerts player of nearby events
			choice = prompt_choice(ai);
			/////////////////////////////////////////////////BODY/////////////
			if(choice == 0){//move
				f_move(current, rows, cols, ai);
				if(check_poke_or_cave(grid, current) == 2){//null
					NULL;
				}
				else if(check_poke_or_cave(grid, current) == 0){//pokestop
					add_pokeballs(grid, current, ash);
				}
				else if(check_poke_or_cave(grid, current) == 1){//cave
					add_stones(grid, current, ash);
					evolve_choice(ash, ai);
				}
			}
			else if(choice == 1){//throw
				f_throw(grid, current, ash, rows, cols, ai);
			}
			stage_one_evolve();
			////////////////////////////////////////////////EndBODY////////////
			if((Geodude::get_geodude_stage_2() == true && Onix::get_onix_stage_2() == true && Charizard::get_charizard_stage_2() == true && Rayquaza::get_rayquaza_stage_2() == true && Mewtwo::get_mewtwo_stage_2() == true && Espeon::get_espeon_stage_2() == true) & ( (current.row == start.row) & (current.col == start.col))){
				cout<<"Congratulations, you win!"<<endl;
				game_over = true;
			}
			sleep(1);
			system("clear");
		}
		play_again = f_play_again();
		iterator++;
	} while(play_again == 1 || play_again == 2);
}////////////////////end of main