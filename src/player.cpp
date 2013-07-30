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
        for(unsigned int i = 0; i < map.movable.size(); i++)
        {
            Movable& m = map.movable[i];
            if(m.x == x && m.y == y)
            {
                m.x -= 32;
            }
            if(map.isWallAt(m.x, m.y))
            {
                m.x += 32;
                x += speed;
            }
        }

        break;

    case sf::Keyboard::Right:
        if (!map.isWallAt(x + speed, y))
        {
            x += speed;
            direction = RIGHT;
        }
        for(unsigned int i = 0; i < map.movable.size(); i++)
        {
            Movable& m = map.movable[i];
            printf("X: %d, Y: %d\n", m.x, m.y);
            if(m.x == x && m.y == y)
            {
                m.x += 32;
            }
            if(map.isWallAt(m.x, m.y))
            {
                m.x -= 32;
                x -= speed;
            }
        }

        break;

    case sf::Keyboard::Up:
        if (!map.isWallAt(x, y - speed))
        {
            y -= speed;
            direction = UP;
        }
        for(unsigned int i = 0; i < map.movable.size(); i++)
        {
            Movable& m = map.movable[i];
            printf("X: %d, Y: %d\n", m.x, m.y);
            if(m.x == x && m.y == y)
            {
                m.y -= 32;
            }
            if(map.isWallAt(m.x, m.y))
            {
                m.y += 32;
                y += speed;
            }
        }

        break;

    case sf::Keyboard::Down:
        if (!map.isWallAt(x, y + speed))
        {
            y += speed;
            direction = DOWN;
        }
        for(unsigned int i = 0; i < map.movable.size(); i++)
        {
            Movable& m = map.movable[i];
            printf("X: %d, Y: %d\n", m.x, m.y);
            if(m.x == x && m.y == y)
            {
                m.y += 32;
            }
            if(map.isWallAt(m.x, m.y))
            {
                m.y -= 32;
                y -= speed;
            }
        }

        break;

    default:
        ;
    }
}
