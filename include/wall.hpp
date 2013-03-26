#ifndef WALL_HPP_INCLUDED
#define WALL_HPP_INCLUDED

#include "../include/player.hpp"
	
class Wall
{
public:
	int x, y;

    Wall();
	void Cycle(Player &p);
	void SetPos(int _x, int _y);
private:
	int w, h;
    sf::Texture tex;
	GLint rect[8];
	GLfloat texcoord[8] = {	0.0f, 0.0f,
							1.0f, 0.0f,
							1.0f, 1.0f,
							0.0f, 1.0f,};
};

#endif
