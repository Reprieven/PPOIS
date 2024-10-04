#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include"Spots.h"
TEST(GameSpotsTest, CopyTest) 
{
	Spots game1;
	Spots game2(game1);
	EXPECT_EQ(game1, game2);
}
TEST(GameSpotsTest, CorrectnessTest)
{
	int value = 1;
	int** known_plate = new int* [4];
	for (int i = 0; i < 4; i++) 
	{
		known_plate[i] = new int[4];
		for (int j = 0; j < 4; j++) 
		{
			if (value == 16)
			{
				known_plate[i][j] = 0;
				break;
			}
			known_plate[i][j] = value;
			value++;
		}
	}
	Spots game(known_plate);
	EXPECT_TRUE(game.is_correct());
	for (int i = 0; i < game.get_size(); i++)
	{
		delete[] known_plate[i];
	}
	delete[] known_plate;
}

TEST(GameSpotsTest, UncorrectnessTest)
{
	int value = 1;
	int** known_plate = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		known_plate[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			if (value == 16)
			{
				known_plate[i][j] = 0;
				break;
			}
			known_plate[i][j] = value;
			value++;
		}
	}
	Spots game(known_plate);
	game.move(12, "down");
	EXPECT_FALSE(game.is_correct());
	for (int i = 0; i < game.get_size(); i++)
	{
		delete[] known_plate[i];
	}
	delete[] known_plate;
}

TEST(GameSpotsTest, CompareTestEqual)
{
	Spots game1;
	Spots game2(game1);
	EXPECT_TRUE(game1 == game2);
}

TEST(GameSpotsTest, CompareTestNotEqual)
{
	int value = 1;
	int** known_plate = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		known_plate[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			if (value == 16)
			{
				known_plate[i][j] = 0;
				break;
			}
			known_plate[i][j] = value;
			value++;
		}
	}
	Spots game1(known_plate);
	Spots game2(known_plate);
	game1.move(12, "down");
	EXPECT_TRUE(game1 != game2);
	for (int i = 0; i < game1.get_size(); i++)
	{
		delete[] known_plate[i];
	}
	delete[] known_plate;
}

TEST(GameSpotsTest, MoveTest) 
{
	int value = 1;
	int** known_plate = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		known_plate[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			if (value == 16)
			{
				known_plate[i][j] = 0;
				break;
			}
			known_plate[i][j] = value;
			value++;
		}
	}
	value = 1;
	Spots game1(known_plate);
	const int size = game1.get_size();
	game1.move(12, "down");
	game1.move(11, "right");
	game1.move(7, "down");
	game1.move(8, "left");
	int** expected_result = new int* [size];
	for (int i = 0; i < size; i++) 
	{
		expected_result[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			expected_result[i][j] = value;
			value++;
		}
	}
	expected_result[1][3] = 0;
	expected_result[1][2] = 8;
	expected_result[2][2] = 7;
	expected_result[2][3] = 11;
	expected_result[3][3] = 12;
	Spots game2(expected_result);
	EXPECT_TRUE(game1 == game2);

	for (int i = 0; i < size; i++)
	{
		delete[] known_plate[i];
	}
	delete[] known_plate;

	for (int i = 0; i < size; i++)
	{
		delete[] expected_result[i];
	}
	delete[] expected_result;
}

TEST(GameSpotsTest, GetElementTest)
{
	Spots game;
	int** test_plate = game.get_plate();
	int value = game.get_element(0, 0);
	EXPECT_EQ(value, test_plate[0][0]);
	for (int i = 0; i < game.get_size(); i++)
	{
		delete[] test_plate[i];
	}
	delete[] test_plate;
}

