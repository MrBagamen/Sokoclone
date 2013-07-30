#include "map.hpp"

#include <fstream>
#include <iostream>

void Map::Load(const std::string& filename)
{
    wallTexture.loadFromFile("res/wall.png");
    movableTexture.loadFromFile("res/push.png");
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
        if (c == '2')
        {
            movable.emplace_back(movableTexture, x * 32, y * 32);
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
    for (const Movable & m : movable)
    {
        m.Draw();
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

int Map::isMovableAt(int x, int y) const
{
    for(unsigned int i = 0; i < movable.size(); i++)
    {
        const Movable& m = movable[i];
        if (m.x == x && m.y == y)
        {
            return true;
        }
    }

    return 0;
}
