#pragma once
#include <iostream>
#include <string>

using namespace std;

class Event{

protected:
	int event_type;
	bool show;

public:
	int get_event_type() const;
	void set_event_type(int);

	void set_show(bool); //assessed when printing to see if thing should be printed to map
	bool get_show() const;

	virtual int get_poke_type() const =0; //pokemon type for pokemon class and children of <- that class
	virtual void set_poke_type(int) =0;

	virtual string get_species() const =0;
	virtual void set_species(string) =0;

	virtual int get_chance() const =0;

	virtual int get_pokeballs() const =0;
	virtual int get_stones() const =0;
	virtual ~Event();

};