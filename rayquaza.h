#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rayquaza:public Flying{

private:

	static int num_rayquaza_collected; //don't need accessor for static var - just call using scope 
	static int rayquaza_achieved; //when stage 2 is acheived
	static int rayquaza_stage;
	static bool rayquaza_stage_2; //flag so stage1 function wont turn it back into stage 1;


public: 	
	Rayquaza();

	static int get_num_rayquaza_collected();
	static void set_num_rayquaza_collected(int);

	static int get_rayquaza_achieved();
	static void set_rayquaza_achieved(int);

	static int get_rayquaza_stage();
	static void set_rayquaza_stage(int);

	static bool get_rayquaza_stage_2();	
	static void set_rayquaza_stage_2(bool);
};