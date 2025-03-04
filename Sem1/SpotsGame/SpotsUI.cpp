#include "SpotsUI.h"

void SpotsUI::show_plate(Spots& game)
{
	std::cout << game;
}

void SpotsUI::get_value(Spots& game)
{
	int row = -1;
	int column = -1;
	std::cout << "Введите строку, в которой находится элемент\n";
	std::cin >> row;
	std::cout << "Введите столбец, в которой находится элемент\n";
	std::cin >> column;
	std::cout<<game.get_element(row, column)<<"\n";
}

void SpotsUI::move_element(Spots& game) 
{
	int value = -1;
	std::string direction;
	std::cout << "Введите элемент для перемещения\n";
	std::cin >> value;
	std::cout << "Введите направление для перемещения(up,down,right,left)\n";
	std::cin.ignore(1000, '\n');
	getline(std::cin, direction);
	game.move(value, direction);
}

void SpotsUI::check_correctness(Spots& game) 
{
	if (game.is_correct()) 
	{
		std::cout << "Поля расположены правильно\n";
	}
	else
	{
		std::cout << "Поля расположены неправильно\n";
	}
}

void SpotsUI::show_menu(Spots& game)
{
	int choice = -1;
	std::cout << "1)Вывести игровое поле в консоль\n2)Передвинуть элементы\n3)Получить значение элемента по его индексу\n4)Проверить на правильность\n";
	std::cin >> choice;
	switch (choice) 
	{
	case 1:
		show_plate(game);
		break;
	case 2:
		move_element(game);
		break;
	case 3:
		get_value(game);
		break;
	case 4:
		check_correctness(game);
		break;
	default:
		break;
	}
}