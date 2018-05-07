#pragma once
#include <iostream>
#include <string>

using namespace std;

class Onix: public Rock{


private:
	
	static int num_onix_collected; //don't need accessor for static var - just call using scope 
	static int onix_achieved; //when stage 2 is acheived
	static int onix_stage;
	static bool onix_stage_2; //flag so stage1 function wont turn it back into stage 1;

public:
	Onix();
	static int get_num_onix_collected();
	static void set_num_onix_collected(int);

	static int get_onix_achieved();
	static void set_onix_achieved(int);

	static int get_onix_stage();
	static void set_onix_stage(int);

	static bool get_onix_stage_2();	
	static void set_onix_stage_2(bool);

};