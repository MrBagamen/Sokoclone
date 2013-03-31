#include "player.hpp"

Player::Player(const sf::Texture& texture, int x, int y, Map& map) :
    Entity(texture, x, y),
    map(map)
{
}

void Player::OnKeyPressed(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Left:
        if (!map.isWallAt(x - speed, y))
        {
            x -= speed;
            direction = LEFT;
        }
        if (map.isMovableAt(x - speed, y) != 0)
        {
            for(unsigned int i = 0; i < map.movable.size(); i++)
            {
                Movable& m = map.movable[i];
                m.x -= 32;
            }
        }

        break;

    case sf::Keyboard::Right:
        if (!map.isWallAt(x + speed, y))
        {
            x += speed;
            direction = RIGHT;
        }

        break;

    case sf::Keyboard::Up:
        if (!map.isWallAt(x, y - speed))
        {
            y -= speed;
            direction = UP;
        }

        break;

    case sf::Keyboard::Down:
        if (!map.isWallAt(x, y + speed))
        {
            y += speed;
            direction = DOWN;
        }

        break;

    default:
        ;
    }
}
