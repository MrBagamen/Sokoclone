#include "../include/wall.hpp"

void Wall::Init()
{
	x = y = 0;
	img.loadFromFile("res/wall.png");
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

void Wall::Cycle(Player &p)
{
	if(p.x == x && p.y == y)
	{
		switch(p.d)
		{
			case LEFT:
				p.x += 32;
			break;
			case RIGHT:
				p.x -= 32;
			break;
			case UP:
				p.y += 32;
			break;
			case DOWN:
				p.y -= 32;
			break;
			default:;
		}
	}

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tex);
	glTranslatef(x+(w/2), y+(h/2), 0.0f);
	glVertexPointer(2, GL_INT, 0, rect);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoord);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();
}

void Wall::SetPos(int _x, int _y)
{
	x = _x;
	y = _y;
}