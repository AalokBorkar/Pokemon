#pragma once
#include <iostream>
#include <string>

using namespace std;

class Geodude:public Rock{

private:
	static int num_geodude_collected; //don't need accessor for static var - just call using scope 
	static int geodude_achieved; //when stage 2 is acheived
	static int geodude_stage;
	static bool geodude_stage_2; //flag so stage1 function wont turn it back into stage 1;

public:

	Geodude();

	static int get_num_geodude_collected();
	static void set_num_geodude_collected(int);

	static int get_geodude_achieved();
	static void set_geodude_achieved(int);

	static int get_geodude_stage();
	static void set_geodude_stage(int);

	static bool get_geodude_stage_2();	
	static void set_geodude_stage_2(bool);

};