#include "Map.h"

Map::Map(AStr::Str FileName)
{
	std::ifstream MapReader(FileName.c_str());
	AStr::Str *TempObj = new AStr::Str[100];
	int i = 0;
	while (!MapReader.eof())
	{
		char *buff = new char[MapSizeW];
		MapReader.getline(buff, MapSizeW);
		TempObj[i] = buff;
		delete buff;
		i++;
	}
	lines = i;
	MapObj = new AStr::Str[i];
	for (size_t i = 0; TempObj[i].Lenth() > 1; i++)
	{
		MapObj[i] = TempObj[i];
	}
}

Map::~Map()
{
	delete[] MapObj;
}

AStr::Str Map::operator[](int i)
{
	return (i >= 0 && i < lines) ? MapObj[i] : 0;
}
