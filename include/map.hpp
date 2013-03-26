#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <cstdio>
#include <cstdlib>

class Map
{
public:
	char *map;
	void Load(const char* filePath);

	~Map()
	{
		delete[] map;
	}
};

#endif