#pragma once
// ����� ��� �������� ���������
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
// ���� ��������
enum CollType { BlockALL, BlockActors, BlockPawn, BlockGamePawn, DoNotBlock };