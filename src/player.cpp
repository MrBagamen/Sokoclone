#include "../include/player.hpp"

void Player::Init()
{
	x = y = 0;
	img.loadFromFile("res/player.png");
	w = img.getSize().x;
	h = img.getSize().y;

	rect[0] = -w/2;rect[1] = -h/2;
	rect[2] = w/2;rect[3] = -h/2;
	rect[4] = w/2;rect[5] = h/2;
	rect[6] = -w/2;rect[7] = h/2;

	//Build Texture
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
}

void Player::Cycle()
{
	//Draw Player
	glPushMatrix();
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
			break;
		case sf::Keyboard::Right:
			x += speed;
			break;
		default:;
	}
}
