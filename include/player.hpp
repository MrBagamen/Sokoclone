#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "entity.hpp"

enum {UP, DOWN, LEFT, RIGHT};

class Player : public Entity
{
public:
    Player(const sf::Texture& texture, int x, int y);
	void OnKeyPressed(sf::Keyboard::Key key);

private:
	int speed = 32;
    int direction = UP;
};

#endif
