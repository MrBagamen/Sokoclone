#include "player.hpp"

Player::Player(const sf::Texture &texture, int x, int y) :
    Entity(texture, x, y)
{
}

void Player::OnKeyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Left:
			x -= speed;
            direction = LEFT;
		break;
		case sf::Keyboard::Right:
			x += speed;
            direction = RIGHT;
		break;
		case sf::Keyboard::Up:
			y -= speed;
            direction = UP;
		break;
		case sf::Keyboard::Down:
			y += speed;
            direction = DOWN;
		break;
		default:;
	}
}
