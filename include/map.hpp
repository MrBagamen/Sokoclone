#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <vector>
#include <string>

#include "wall.hpp"

class Map
{
public:
    void Load(const std::string& filename);
    void Draw();

    std::vector<Wall> walls;
};

#endif
