#ifndef MOVABLE_HPP_INCLUDED
#define MOVABLE_HPP_INCLUDED

#include "entity.hpp"

class Movable : public Entity
{
public:
    Movable(const sf::Texture& texture, int x, int y);
};

#endif
