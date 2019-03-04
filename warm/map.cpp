#include "map.h"
#include "gtxy.h"
#include <iostream>
#include <mutex>
const char * blocks[] = {"¢É", " ",  "¡á" ,"¡Û"};

std::mutex g_Mutex;

Map::Map()
{
	for (int i_index = 0; i_index < Height; ++i_index)
	{
		for (int j_index = 0; j_index < Width; ++j_index)
		{
			gtxy::gotoxy(j_index * 2, i_index);
			if (i_index == 0 || i_index == Width - 1 || j_index == 0 || j_index == Height - 1)
			{

				mMap[i_index][j_index] = WALL;
			}
			else
			{
				mMap[i_index][j_index] = BLANK;
			}
		}

	}

	GenerateMap();
}

void Map::GenerateMap()
{

	


	for (int i_index = 0; i_index < Height; ++i_index)
	{
		for (int j_index = 0; j_index < Width; ++j_index)
		{
			if (i_index == 0 || i_index == Width - 1 || j_index == 0 || j_index == Height - 1)
			{
				RedrawPoint(j_index, i_index,WALL);
			}
			else
			{
				RedrawPoint(j_index, i_index, BLANK);
			}
		}
	}

}

void Map::SetPointState(const Point & pos, const State new_state)
{
	mMap[pos.yPos][pos.xPos] = new_state;
	RedrawPoint(pos, new_state);
}

void Map::RedrawPoint(const Point & pos, const State new_state)
{
	g_Mutex.lock();
	gtxy::gotoxy((pos.xPos + 1) * 2, pos.yPos + 1);
	puts(blocks[new_state]);
	g_Mutex.unlock();
}

void Map::RedrawPoint(const int x_pos, const int y_pos, const State new_state)
{
	g_Mutex.lock();
	gtxy::gotoxy((x_pos+1)*2, y_pos+1);
	puts(blocks[new_state]);
	g_Mutex.unlock();
}
