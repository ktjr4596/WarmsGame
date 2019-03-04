#pragma once

typedef enum  State { WALL, BLANK, PLAYER, BLOCK } State;

typedef enum { LEFT, RIGHT, UP, DOWN } Direction;

extern Direction EDirection;
struct Point
{
	int xPos;
	int yPos;
};



class UnCopyable
{
public:
	UnCopyable() {};
	~UnCopyable() {};
private:
	UnCopyable(const UnCopyable &);
	UnCopyable & operator=(const UnCopyable &);
};

class Map :private UnCopyable
{
	
public:
	enum { Width = 20, Height = 20 };
	Map();
	void GenerateMap();
	void SetPointState(const Point & pos,const State new_state);
	State GetPointState(int x_pos, int y_pos) { return mMap[y_pos][x_pos]; }
	void RedrawPoint(const Point & pos, const State new_state);
	void RedrawPoint(const int x_pos, const int y_pos, const State new_state);
private:
	State mMap[Height][Width];
};
