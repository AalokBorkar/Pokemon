#pragma once
#include <iostream>
#include <string>

using namespace std;

class Mewtwo:public Psychic{

private:
	static int num_mewtwo_collected; //don't need accessor for static var - just call using scope 
	static int mewtwo_achieved; //when stage 2 is acheived
	static int mewtwo_stage;
	static bool mewtwo_stage_2; //flag so stage1 function wont turn it back into stage 1;

public:

	Mewtwo();

	static int get_num_mewtwo_collected();
	static void set_num_mewtwo_collected(int);

	static int get_mewtwo_achieved();
	static void set_mewtwo_achieved(int);

	static int get_mewtwo_stage();
	static void set_mewtwo_stage(int);

	static bool get_mewtwo_stage_2();	
	static void set_mewtwo_stage_2(bool);
};