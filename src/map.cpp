#include "../include/map.hpp"

void Map::Load(const char* filePath)
{
	FILE *file;
	long fileSize;

	file = fopen(filePath, "rb");
	if(file == nullptr){printf("Error loading %s\n", filePath);exit(0);}
	fseek(file, 0, SEEK_END);
	fileSize = ftell(file);
	rewind(file);

	map = new char(fileSize);
	fread(map, 1, fileSize, file);
	fclose(file);

	//PRINT FILE 
	printf("%s", map);
}