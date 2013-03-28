#ifndef WALL_HPP_INCLUDED
#define WALL_HPP_INCLUDED

#include "entity.hpp"
	
class Wall : public Entity
{
public:
    Wall(const sf::Texture& texture, int x, int y);
};

#endif
