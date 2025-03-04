#pragma once
#include"Spots.h"
class SpotsUI
{
private:
	void show_plate(Spots& game);
	void move_element(Spots& game);
	void get_value(Spots& game);
	void check_correctness(Spots& game);
public:
	void show_menu(Spots& game);
};

