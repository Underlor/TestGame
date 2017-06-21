#pragma once
// Класс для хранения координат
class Coordinate
{
public:
	float x;
	float y;
	Coordinate()
	{}
	Coordinate(float ix, float iy)
	{
		x = ix;
		y = iy;
	}
};
// типы коллизий
enum CollType { BlockALL, BlockActors, BlockPawn, BlockGamePawn, DoNotBlock };