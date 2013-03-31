#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "entity.hpp"

#include "map.hpp"

enum {UP, DOWN, LEFT, RIGHT};

class Player : public Entity
{
public:
    Player(const sf::Texture& texture, int x, int y, Map& map);
    void OnKeyPressed(sf::Keyboard::Key key);

private:
    int speed = 32;
    int direction = UP;
    const Map& map;
};

#endif
