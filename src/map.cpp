#include "../include/map.hpp"

void Map::Load(const char* filePath)
{
	FILE *file;

	file = fopen(filePath, "rb");
	if(file == nullptr){printf("Error loading %s\n", filePath);exit(0);}
	fseek(file, 0, SEEK_END);
	map_size = ftell(file);
	rewind(file);

    map = new char[map_size];
	fread(map, 1, map_size, file);
	fclose(file);
}
