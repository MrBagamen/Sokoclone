#include "player.hpp"

Player::Player()
{
    x = y = 0;
    tex.loadFromFile("res/player.png");
    w = tex.getSize().x;
    h = tex.getSize().y;

    rect[0] = -w/2;rect[1] = -h/2;
    rect[2] = w/2;rect[3] = -h/2;
    rect[4] = w/2;rect[5] = h/2;
    rect[6] = -w/2;rect[7] = h/2;
}

void Player::Cycle()
{
	//Draw Player
	glPushMatrix();
    sf::Texture::bind(&tex);
	glTranslatef(x+(w/2), y+(h/2), 0.0f);
	glVertexPointer(2, GL_INT, 0, rect);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoord);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();
}

void Player::SetPos(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::OnKeyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Left:
			x -= speed;
			d = LEFT;
		break;
		case sf::Keyboard::Right:
			x += speed;
			d = RIGHT;
		break;
		case sf::Keyboard::Up:
			y -= speed;
			d = UP;
		break;
		case sf::Keyboard::Down:
			y += speed;
			d = DOWN;
		break;
		default:;
	}
}
