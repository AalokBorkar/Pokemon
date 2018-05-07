#pragma once
#include <iostream>
#include <unistd.h>
#include <string>

/***************************************************************************************
** Decription: inits the board
** Parameters: (Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void init_board(Location &grid, Position &current, Position &start, int rows, int cols);

/***************************************************************************************
** Decription: checks if rows and cols are valid
** Parameters: (int &rows, int &cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void valid_rows_int(int &rows, int &cols);

/***************************************************************************************
** Decription: checks if rows and cols are valid
** Parameters: none
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: int
****************************************************************************************/
int f_play_again();

/***************************************************************************************
** Decription: inits the position of the player
** Parameters: (Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void init_position(Position &current, Position &start, int rows, int cols);

/***************************************************************************************
** Decription: checks if rows and cols are valid
** Parameters: none
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: int
****************************************************************************************/
int get_dubugging();

/***************************************************************************************
** Decription: gets user decision for playing using AI or not
** Parameters: (Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
int get_ai();

/***************************************************************************************
** Decription: prints the positions on the board
** Parameters: (Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void print_position_d(Location &grid, Position &current, Position &start, int rows, int cols);

/***************************************************************************************
** Decription: prints the positions on the board
** Parameters: (Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void print_position(Location &grid, Position &current, Position &start, int rows, int cols);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void print_current_position(int debugging, Location &grid, Position &current, Position &start, int rows, int cols);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void print_inventory(Trainer &ash);

/***************************************************************************************
** Decription: prompts user for move choice
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
int prompt_choice(int);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void f_move(Position &current, int rows, int cols, int ai);

/***************************************************************************************
** Decription: throw function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void f_throw(Location &grid, Position &current, Trainer &ash, int rows, int cols, int ai);

/***************************************************************************************
** Decription: percept function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void warning_1(Location &grid, Position &current);
/***************************************************************************************
** Decription: percept function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void warning_2(Location &grid, Position &current);
/***************************************************************************************
** Decription: percept function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void warning_3(Location &grid, Position &current);
/***************************************************************************************
** Decription: percept function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void warning_4(Location &grid, Position &current);

/***************************************************************************************
** Decription: percept function
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void warning(Location &grid, Position &current, int rows, int cols);

/***************************************************************************************
** Decription: checks if position is cave or pokestop
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
int check_poke_or_cave(Location &grid, Position &current);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void add_pokeballs(Location &grid, Position &current, Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void add_stones(Location &grid, Position &current, Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void stage_one_evolve();

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_geodudes(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_onix(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_charizard(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_rayquaza(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of plgingayer on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_mewtwo(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_espeon(Trainer &ash);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void stage_two_evolve(Trainer &ash, int ai);

/***************************************************************************************
** Decription: prints the position of player on board
** Parameters: (int debugging, Location &grid, Position &current, Position &start, int rows, int cols)
** Preconditions: board must be created first
** Postconditions: board is fully inited
** Returns: none
****************************************************************************************/
void evolve_choice(Trainer &ash, int ai);