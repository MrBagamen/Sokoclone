#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <vector>
#include <string>

#include "wall.hpp"
#include "movable.hpp"

class Map
{
public:
    void Load(const std::string& filename);
    void Draw();
    bool isWallAt(int x, int y) const;
    int isMovableAt(int x, int y) const;

    std::vector<Movable> movable;
private:
    std::vector<Wall> walls;
    sf::Texture wallTexture;
    sf::Texture movableTexture;
};

#endif
