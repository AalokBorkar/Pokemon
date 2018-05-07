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

void init_board(Location &grid, Position &current, Position &start, int rows, int cols){
	srand(time(NULL));
	int f_row;
	int f_col;
	Event **start_poke = new Event*[6];
	start_poke[0] = new Geodude;
	start_poke[1] = new Onix;
	start_poke[2] = new Charizard;
	start_poke[3] = new Rayquaza;
	start_poke[4] = new Mewtwo;
	start_poke[5] = new Espeon;
	for(int i =0; i < 6; i++){ //get one of each pokemon on the board
		while(true){
			f_row = rand()%rows;
			f_col = rand()%cols;
			if(grid.get_map()[f_row][f_col] == NULL && ((f_row != start.row && f_col != start.col)) && ((f_row != current.row && f_col != current.col))){ //if the location is not pointing somewhere [NULL]
				grid.get_map()[f_row][f_col] = start_poke[i]; //point it to a pokemon address
				break;
			}
		}
	}
	while(true){
		f_row = rand()%rows;
		f_col = rand()%cols;
		if(grid.get_map()[f_row][f_col] == NULL && ((f_row != start.row && f_col != start.col)) && ((f_row != current.row && f_col != current.col))){//if the location is not pointing somewhere [NULL]
			grid.get_map()[f_row][f_col] = new Pokestop; //point it to a pokestop address
			break;
		}
	}
	while(true){
		f_row = rand()%rows;
		f_col = rand()%cols;
		if(grid.get_map()[f_row][f_col] == NULL && ((f_row != start.row && f_col != start.col)) && ((f_row != current.row && f_col != current.col))){ //if the location is not pointing somewhere [NULL]
			grid.get_map()[f_row][f_col] = new Cave; //point it to a cave address
			break;
		}
	}
	for(int i =0; i < 6; i++){
		start_poke[i] = NULL; //So it doesnt delete all the pokemon map is pointing too
	}
	for(int i =0; i < 6; i++){
		delete start_poke[i];
	}
	delete [] start_poke;
}

void valid_rows_int(int &rows, int &cols){
	int r_rows;
	int r_cols;
	if(rows < 4){
		cout<<"Please in input the amount of columns: ";
		cin>>r_rows;
		rows = r_rows;
	}

	if(cols < 4){
		cout<<"Please in input the amount of columns: ";
		cin>>r_cols;
		cols = r_cols; 
	}
}

int f_play_again(){
	int play;
	cout<<"Do you want to play again with a new random configuration (1) | same configuration (2) | quit the game (0) : ";
	cin>>play;
	return play;
}

void init_position(Position &current, Position &start, int rows, int cols){
		current.row = rand()%rows;
		current.col = rand()%cols;

		start.row = current.row;
		start.col = current.col;
}

int get_dubugging(){
	int debug;
	cout<<"Do you want to play in Normal mode (0) or Debugging mode (1)? : ";
	cin>>debug;
	return debug;
}

int get_ai(){
	int ai;
	cout<<"Do you want to play using an AI? Yes - 1 | No - 0:  ";
	cin>>ai;
	return ai;
}

void print_position_d(Location &grid, Position &current, Position &start, int rows, int cols){
	cout<<"X - Player's current position "<<"        --    "<<"Geodudes (g) caught: "<<Geodude::get_num_geodude_collected()<<"/2"<<endl;
	cout<<"S - Proffesor's current position"<<"      --    "<<"Onix (o) caught: "<<Onix::get_num_onix_collected()<<"/2"<<endl;
	cout<<"P - Pokestop"<<"                          --    "<<"Charizards (c) caught: "<<Charizard::get_num_charizard_collected()<<"/2"<<endl;
	cout<<"C - Cave"<<"                              --    "<<"Rayquazas (r) caught: "<<Rayquaza::get_num_rayquaza_collected()<<"/2"<<endl;
	cout<<"                             "<<"         --    "<<"Mewtwos (m) caught: "<<Mewtwo::get_num_mewtwo_collected()<<"/2"<<endl;
	cout<<"                             "<<"         --    "<<"Espeons (e) caught: "<<Espeon::get_num_espeon_collected()<<"/2"<<endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			cout<<'|';

			if(grid.get_map()[i][a] == NULL){
				cout<<' '; //if none then just print a space
				if(i == current.row && a == current.col){ //if the current coordinates are equal to players
					cout<<'X';
				}
				if(i == start.row && a == start.col){ //if the current coordinates are equal to players
					cout<<'S';
				}
				else{
					cout<<' ';
				}
			}		
			else if(grid.get_map()[i][a]->get_event_type() == 0){
				cout<<" P";
			}
			else if(grid.get_map()[i][a]->get_event_type() == 1){
				cout<<" C";
			}
			else if(grid.get_map()[i][a]->get_event_type() == 2){
				if(grid.get_map()[i][a]->get_species() == "Geodude"){
					cout<<" g";
				}
				else if(grid.get_map()[i][a]->get_species() == "Onix"){
					cout<<" o";
				}
				else if(grid.get_map()[i][a]->get_species() == "Charizard"){
					cout<<" c";
				}
				else if(grid.get_map()[i][a]->get_species() == "Rayquaza"){
					cout<<" r";
				}
				else if(grid.get_map()[i][a]->get_species() == "Mewtwo"){
					cout<<" m";
				}
				else if(grid.get_map()[i][a]->get_species() == "Espeon"){
					cout<<" e";
				}
			}
		}
		cout<<'|';
		cout<<"\n";
		cout<<"-------------------"<<endl;
	}
}

void print_position(Location &grid, Position &current, Position &start, int rows, int cols){
	cout<<"X - Player's current position"<<endl;
	////////////////////////////////////////////
	for(int i =0; i < rows; i++){
		for(int a =0; a < cols; a++){
			cout<<'|';

			if(i == current.row && a == current.col){ //if the current coordinates are equal to players
				cout<<'X';
			}
			else{
				cout<<' ';
			}
		}
		cout<<"\n";
		cout<<"------------"<<endl;
	}
}

void print_current_position(int debugging, Location &grid, Position &current, Position &start, int rows, int cols){
	cout<<"////////////////////////////////////////////////////////////////"<<endl;
	if(debugging == 1){
		print_position_d(grid, current, start, rows, cols);
	}
	else{
		print_position(grid, current, start, rows, cols);
	}
}


void print_inventory(Trainer &ash){
	cout<<"Your current amount of pokeballs: "<<ash.get_num_pokeballs()<<endl;
	cout<<"Your current amount of stones: "<<ash.get_num_stones()<<endl;
}

int prompt_choice(int ai){
	srand(time(NULL));
	int choice;
	if(ai == 0){
		cout<<"Would you like to move (0) or throw a pokeball (1)?: ";
		cin>>choice;
	}
	else if(ai == 1){
		choice = rand()%2; //0 or 1
	}
	return choice;
}

void f_move(Position &current, int rows, int cols, int ai){
	srand(time(NULL));
	int choice;
	while(true){
		if(ai == 0){
			cout<<"Would you like to move up (0) down (1) left (2) or right (3)?: ";
			cin>>choice;
		}
		else if(ai == 1){
			choice = rand()%4;
		}
//////////////////////////////////////////////////////////////////////////////////////////////
		if(choice == 0){
			if(!(current.row == 0)){ //if current row is not 0
				current.row = current.row - 1;
				break;
			}
			else{
				cout<<"You can't move here: out of bounds!"<<endl;
			}
		}
		else if(choice == 1){
			if(!(current.row == rows-1)){ //if current row is not 0
				current.row = current.row + 1;
				break;
			}
			else{
				cout<<"You can't move here: out of bounds!"<<endl;
			}
		}
		else if(choice == 2){
			if(!(current.col == 0)){ //if current row is not 0
				current.col = current.col - 1;
				break;
			}
			else{
				cout<<"You can't move here: out of bounds!"<<endl;
			}
		}
		else if(choice == 3){
			if(!(current.col == cols-1)){ //if current row is not 0
				current.col = current.col + 1;
				break;
			}
			else{
				cout<<"You can't move here: out of bounds!"<<endl;
			}
		}
	}
}

void f_throw(Location &grid, Position &current, Trainer &ash, int rows, int cols, int ai){ // since throw is a keyword: f_ means 'function'
	srand(time(NULL));
	int num;
	int f_row;
	int f_col;
	if((grid.get_map()[current.row][current.col] == NULL) || (grid.get_map()[current.row][current.col]->get_event_type() == 0) || (grid.get_map()[current.row][current.col]->get_event_type() == 1)){
		cout<<"\n";
		cout<<"There are no pokemon to capture!"<<endl;
		cout<<"\n";
		return;
	}
	else{
		if(ash.get_num_pokeballs() > 0){
			num = rand()%101;
			ash.set_num_pokeballs(ash.get_num_pokeballs()-1);//reduce pokeballs by one
			if(num <= grid.get_map()[current.row][current.col]->get_chance()){ //if less than the chance of that pokemon

				if(grid.get_map()[current.row][current.col]->get_species() == "Geodude"){
					cout<<"You caught the geodude!"<<endl;
					Geodude::set_num_geodude_collected(1); //adds one to the previous num_collected;
				}
				else if(grid.get_map()[current.row][current.col]->get_species() == "Onix"){
					cout<<"You caught the Onix!"<<endl;
					Onix::set_num_onix_collected(1);
				}
				else if(grid.get_map()[current.row][current.col]->get_species() == "Charizard"){
					cout<<"You caught the Charizard!"<<endl;
					Charizard::set_num_charizard_collected(1);
				}
				else if(grid.get_map()[current.row][current.col]->get_species() == "Rayquaza"){
					cout<<"You caught the Rayquaza!"<<endl;
					Rayquaza::set_num_rayquaza_collected(1);
				}
				else if(grid.get_map()[current.row][current.col]->get_species() == "Mewtwo"){
					cout<<"You caught the Mewtwo!"<<endl;
					Mewtwo::set_num_mewtwo_collected(1);
				}
				else if(grid.get_map()[current.row][current.col]->get_species() == "Espeon"){
					cout<<"You caught the Espeon!"<<endl;
					Espeon::set_num_espeon_collected(1);
				}
			} //if you succesfully catch it
			else{
				cout<<"The pokemon escaped!"<<endl;
			}
			while(true){ //free that pokemon to another location if you catch it or not, its going to retreat to new location
				f_row = rand()%rows;
				f_col = rand()%cols;
				if(grid.get_map()[f_row][f_col] == NULL){ //if the location is not pointing somewhere [NULL]
					grid.get_map()[f_row][f_col] = grid.get_map()[current.row][current.col]; 
					grid.get_map()[current.row][current.col] = NULL;         //point it to the pokemon you just caught, and set old position to NULL
					break;
				}
			}
		}

		else{
			cout<<"You do not enough pokeballs!"<<endl;
			return;
		}
	}
}


void warning_1(Location &grid, Position &current){
	if(grid.get_map()[current.row-1][current.col] == NULL){
		NULL;
	}
	else if(grid.get_map()[current.row-1][current.col]->get_event_type() == 0){
		cout<<"There is a pokestop nearby!"<<endl;
	}	
	else if(grid.get_map()[current.row-1][current.col]->get_event_type() == 1){
		cout<<"There is a cave nearby!"<<endl;
	}
	else if(grid.get_map()[current.row-1][current.col]->get_event_type() == 2){
		cout<<"There is a pokemon nearby!"<<endl;
	}
}

void warning_2(Location &grid, Position &current){
	if(grid.get_map()[current.row+1][current.col] == NULL){
		NULL;
	}
	else if(grid.get_map()[current.row+1][current.col]->get_event_type() == 0){
		cout<<"There is a pokestop nearby!"<<endl;
	}	
	else if(grid.get_map()[current.row+1][current.col]->get_event_type() == 1){
		cout<<"There is a cave nearby!"<<endl;
	}
	else if(grid.get_map()[current.row+1][current.col]->get_event_type() == 2){
		cout<<"There is a pokemon nearby!"<<endl;
	}
}

void warning_3(Location &grid, Position &current){
	if(grid.get_map()[current.row][current.col-1] == NULL){
		NULL;
	}
	else if(grid.get_map()[current.row][current.col-1]->get_event_type() == 0){
		cout<<"There is a pokestop nearby!"<<endl;
	}
	else if(grid.get_map()[current.row][current.col-1]->get_event_type() == 1){
		cout<<"There is a cave nearby!"<<endl;
	}
	else if(grid.get_map()[current.row][current.col-1]->get_event_type() == 2){
		cout<<"There is a pokemon nearby!"<<endl;
	}
}

void warning_4(Location &grid, Position &current){
	if(grid.get_map()[current.row][current.col+1] == NULL){
		NULL;
	}
	else if(grid.get_map()[current.row][current.col+1]->get_event_type() == 0){
		cout<<"There is a pokestop nearby!"<<endl;
	}
	else if(grid.get_map()[current.row][current.col+1]->get_event_type() == 1){
		cout<<"There is a cave nearby!"<<endl;
	}
	else if(grid.get_map()[current.row][current.col+1]->get_event_type() == 2){
		cout<<"There is a pokemon nearby!"<<endl;
	}
}

void warning(Location &grid, Position &current, int rows, int cols){
	if(current.row != 0){
		warning_1(grid, current);
	}
	if(current.row != rows-1){
		warning_2(grid, current);
	}
	if(current.col != 0){
		warning_3(grid, current);
	}
	if(current.col != cols-1){
		warning_4(grid, current);
	}
}

int check_poke_or_cave(Location &grid, Position &current){
	if(grid.get_map()[current.row][current.col] == NULL || grid.get_map()[current.row][current.col]->get_event_type() == 2 ){
		return 2; //else...
	}
	if(grid.get_map()[current.row][current.col]->get_event_type() == 0){
		return 0;
	}
	else if(grid.get_map()[current.row][current.col]->get_event_type() == 1){
		return 1;
	}
}

void add_pokeballs(Location &grid, Position &current, Trainer &ash){
	ash.set_num_pokeballs(ash.get_num_pokeballs() + grid.get_map()[current.row][current.col]->get_pokeballs());	
}

void add_stones(Location &grid, Position &current, Trainer &ash){
	ash.set_num_stones(ash.get_num_stones() + grid.get_map()[current.row][current.col]->get_stones());
}

void stage_one_evolve(){
	if(Geodude::get_num_geodude_collected() == 2 && Geodude::get_geodude_stage_2() == false){
		Geodude::set_geodude_stage(1);
	}
	if(Onix::get_num_onix_collected() == 2 && Onix::get_onix_stage_2() == false){
		Onix::set_onix_stage(1);
	}
	if(Charizard::get_num_charizard_collected() == 2 && Charizard::get_charizard_stage_2() == false){
		Charizard::set_charizard_stage(1);
	}
	if(Rayquaza::get_num_rayquaza_collected() == 2 && Rayquaza::get_rayquaza_stage_2() == false){
		Rayquaza::set_rayquaza_stage(1);
	}
	if(Mewtwo::get_num_mewtwo_collected() == 2 && Mewtwo::get_mewtwo_stage_2() == false){
		Mewtwo::set_mewtwo_stage(1);
	}
	if(Espeon::get_num_espeon_collected() == 2 && Espeon::get_espeon_stage_2() == false){
		Espeon::set_espeon_stage(1);
	}
}

void evolve_geodude(Trainer &ash){
	if(Geodude::get_geodude_stage() == 1){
		cout<<"Your Geodudes evolved to stage two!"<<endl;
		Geodude::set_geodude_stage_2(true);
		Geodude::set_geodude_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Geodudes must be stage 1 first!"<<endl;
	}
}

void evolve_onix(Trainer &ash){
	if(Onix::get_onix_stage() == 1){
		cout<<"Your Onix evolved to stage two!"<<endl;
		Onix::set_onix_stage_2(true);
		Onix::set_onix_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Onix must be stage 1 first!"<<endl;
	}
}

void evolve_charizard(Trainer &ash){
	if(Charizard::get_charizard_stage() == 1){
		cout<<"Your Charizards evolved to stage two!"<<endl;
		Charizard::set_charizard_stage_2(true);
		Charizard::set_charizard_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Charizards must be stage 1 first!"<<endl;
	}
}

void evolve_rayquaza(Trainer &ash){
	if(Rayquaza::get_rayquaza_stage() == 1){
		cout<<"Your Rayquazas evolved to stage two!"<<endl;
		Rayquaza::set_rayquaza_stage_2(true);
		Rayquaza::set_rayquaza_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Rayquazas must be stage 1 first!"<<endl;
	}
}

void evolve_mewtwo(Trainer &ash){
	if(Mewtwo::get_mewtwo_stage() == 1){
		cout<<"Your Mewtwos evolved to stage two!"<<endl;
		Mewtwo::set_mewtwo_stage_2(true);
		Mewtwo::set_mewtwo_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Mewtwos must be stage 1 first!"<<endl;
	}
}

void evolve_espeon(Trainer &ash){
	if(Espeon::get_espeon_stage() == 1){
		cout<<"Your Espeons evolved to stage two!"<<endl;
		Espeon::set_espeon_stage_2(true);
		Espeon::set_espeon_stage(2);
		ash.set_num_stones(ash.get_num_stones()-1);
	}
	else{
		cout<<"Your Espeons must be stage 1 first!"<<endl;
	}
}


void stage_two_evolve(Trainer &ash, int ai){
	int choice; 
	if(ash.get_num_stones() > 1){
		if(ai == 0){
			cout<<"Which pokemon species would you like to evolve to stage 2? | Geodude (0) | Onix (1) | Charizard (2) | Rayquaza (3) | Mewtwo (4) | Espeon (5) | : ";
			cin>>choice;
		}
		else if(ai == 1){
			choice = rand()%6; //0 or 1
		}
/////////////////////////////////////////////CHOICE^/////////////////////////////////////////////
		if(choice == 0){
			evolve_geodude(ash);
		}
		else if(choice == 1){
			evolve_onix(ash);
		}
		else if(choice == 2){
			evolve_charizard(ash);
		}
		else if(choice == 3){
			evolve_rayquaza(ash);
		}
		else if(choice == 4){
			evolve_mewtwo(ash);
		}
		else if(choice == 5){
			evolve_espeon(ash);
		}
	}
	else{
		return;
	}
}

void evolve_choice(Trainer &ash, int ai){
	int choice;

	if(ai == 0){
		cout<<"Would you like to evolve a pokemon to stage 2? No (0) | Yes (1): ";
		cin>>choice;
	}
	else if(ai == 1){
		choice = rand()%2; //0 or 1
	}
///////////////////////////////	
	if(choice == 0){
		return;
	}
	else if(choice == 1){
		stage_two_evolve(ash, ai);
	}
}
