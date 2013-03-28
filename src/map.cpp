#include "map.hpp"

#include <fstream>
#include <iostream>

void Map::Load(const std::string& filename)
{
    wallTexture.loadFromFile("res/wall.png");
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "PHAILED LOADING " << filename;
        std::abort();
    }

    char c;
    int x = 0, y = 0;

    while (file.get(c))
    {
        if (c == '1')
        {
            walls.emplace_back(wallTexture, x * 32, y * 32);
        }

        if (c == '\n')
        {
            x = 0;
            ++y;
            continue;
        }

        ++x;
    }
}

void Map::Draw()
{
    for (const Wall & w : walls)
    {
        w.Draw();
    }
}

bool Map::isWallAt(int x, int y) const
{
    for (const Wall & w : walls)
    {
        if (w.x == x && w.y == y)
        {
            return true;
        }
    }

    return false;
}
