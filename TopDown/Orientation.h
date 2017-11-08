#pragma once

struct Coord
{
	float x = 0;
	float y = 0;
	float width = 0;
	float height = 0;
};

enum Direction
{
	North,NorthEast,East,SouthEast,
	South,SouthWest,West,NorthWest
};
