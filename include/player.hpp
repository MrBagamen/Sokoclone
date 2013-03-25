#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cstdio>
#include <cstring>

class Player
{
public:
	void Init();
	void Cycle(bool *keys);
	void SetPos(int _x, int _y);

private:
	int x, y, w, h;
	int speed = 4;
	sf::Image img;
	GLuint tex;
	GLint rect[8];
	GLfloat texcoord[8] = {	0.0f, 0.0f,
							1.0f, 0.0f,
							1.0f, 1.0f,
							0.0f, 1.0f,};
};

#endif