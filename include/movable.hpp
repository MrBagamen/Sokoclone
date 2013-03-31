#ifndef MOVABLE_HPP_INCLUDED
#define MOVABLE_HPP_INCLUDED

#include "entity.hpp"
#include "map.hpp"

class Movable : public Entity
{
public:
	Wall(const sf::Texture& texture, int x, int y);
};

#endif