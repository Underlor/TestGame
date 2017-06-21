#pragma once
#include <fstream>
#include "../../AString.h"
#include "Actor.h"
#define MapSizeW 1024
class Map
{
public:
	Map(AStr::Str);
	~Map();
	size_t lines;
	Actor *MapBlocks;
	AStr::Str operator[](int);
private:
	AStr::Str *MapObj;
};
