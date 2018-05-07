#pragma once
#include <iostream>
#include <string>

using namespace std;

class Charizard:public Flying{

private:

	static int num_charizard_collected; //don't need accessor for static var - just call using scope 
	static int charizard_achieved; //when stage 2 is acheived
	static int charizard_stage;
	static bool charizard_stage_2; //flag so stage1 function wont turn it back into stage 1;

public:
	Charizard();

	static int get_num_charizard_collected();
	static void set_num_charizard_collected(int);

	static int get_charizard_achieved();
	static void set_charizard_achieved(int);

	static int get_charizard_stage();
	static void set_charizard_stage(int);


	static bool get_charizard_stage_2();
	static void set_charizard_stage_2(bool);

};