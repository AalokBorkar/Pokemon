#pragma once
#include <iostream>
#include <string>

using namespace std;

class Espeon:public Psychic{

private:
	static int num_espeon_collected; //don't need accessor for static var - just call using scope 
	static int espeon_achieved; //when stage 2 is acheived
	static int espeon_stage;
	static bool espeon_stage_2; //flag so stage1 function wont turn it back into stage 1;

public:

	Espeon();
	static int get_num_espeon_collected();
	static void set_num_espeon_collected(int);

	static int get_espeon_achieved();
	static void set_espeon_achieved(int);

	static int get_espeon_stage();
	static void set_espeon_stage(int);

	static bool get_espeon_stage_2();	
	static void set_espeon_stage_2(bool);

};