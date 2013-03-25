#include "../include/player.hpp"

void Player::Init()
{
	x = y = 0;
	img.loadFromFile("res/test.png");
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

void Player::Cycle(bool *keys)
{
	if(keys[sf::Keyboard::Up])
	{
		y -= 32;
	}

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