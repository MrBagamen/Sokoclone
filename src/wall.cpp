#include "../include/wall.hpp"

Wall::Wall(int x, int y)
{
    this->x = x;
    this->y = y;
    tex.loadFromFile("res/wall.png");
    w = tex.getSize().x;
    h = tex.getSize().y;

    rect[0] = -w/2;rect[1] = -h/2;
    rect[2] = w/2;rect[3] = -h/2;
    rect[4] = w/2;rect[5] = h/2;
    rect[6] = -w/2;rect[7] = h/2;
}

void Wall::Draw() const
{
    glPushMatrix();
    sf::Texture::bind(&tex);
    glTranslatef(x+(w/2), y+(h/2), 0.0f);
    glVertexPointer(2, GL_INT, 0, rect);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoord);
    glDrawArrays(GL_QUADS, 0, 4);
    glPopMatrix();
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
}

void Wall::SetPos(int _x, int _y)
{
	x = _x;
	y = _y;
}
