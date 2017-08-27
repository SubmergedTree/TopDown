#pragma once

struct Coord
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
};

enum Direction
{
	North,NorthEast,East,SouthEast,
	South,SouthWest,West,NorthWest
};
