#pragma once
#include <iostream>
#include <string>

using namespace std;

class Trainer{

private:
	int num_pokeballs;
	int num_stones;

public:
	Trainer();
	void set_num_pokeballs(int);
	int get_num_pokeballs() const;
	void set_num_stones(int);
	int get_num_stones() const;

};