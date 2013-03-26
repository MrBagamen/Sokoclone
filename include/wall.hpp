#ifndef WALL_HPP_INCLUDED
#define WALL_HPP_INCLUDED

#include "../include/player.hpp"
	
class Wall
{
public:
	void Init();
	void Cycle(Player &p);
	void SetPos(int _x, int _y);
private:
	int x, y, w, h;
	sf::Image img;
	GLuint tex;
	GLint rect[8];
	GLfloat texcoord[8] = {	0.0f, 0.0f,
							1.0f, 0.0f,
							1.0f, 1.0f,
							0.0f, 1.0f,};
};

#endif