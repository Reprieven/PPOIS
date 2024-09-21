#include "pch.h"
#include"spots.h"
TEST(GameSpotsTest, CopyTest) 
{
	spots game1;
	spots game2(game1);
	EXPECT_EQ(game1, game2);
}
TEST(GameSpotsTest, CorrectnessTest)
{
	spots game;
	EXPECT_FALSE(game.is_correct());
}
TEST(GameSpotsTest, CompareTestEqual)
{
	spots game1;
	spots game2(game1);
	EXPECT_TRUE(game1 == game2);
}
TEST(GameSpotsTest, CompareTestNotEqual)
{
	spots game1;
	Sleep(500);
	spots game2;
	EXPECT_TRUE(game1 != game2);
}

TEST(GameSpotsTest, GetElementTest)
{
	spots game;
	int** test_plate = game.get_plate();
	int value = game.get_element(0, 0);
	EXPECT_EQ(value, test_plate[0][0]);
	for (int i = 0; i < game.get_size(); i++)
	{
		delete[] test_plate[i];
	}
	delete[] test_plate;
}

