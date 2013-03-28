#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cstdio>
#include <cstring>

enum {UP, DOWN, LEFT, RIGHT};

class Player
{
public:
	int x, y, d = 0;

    Player(const sf::Texture& texture);
	void Cycle();
	void SetPos(int _x, int _y);
	void OnKeyPressed(sf::Keyboard::Key key);

private:
	int w, h;
	int speed = 32;
    sf::Texture tex;
	GLint rect[8];
	GLfloat texcoord[8] = {	0.0f, 0.0f,
							1.0f, 0.0f,
							1.0f, 1.0f,
							0.0f, 1.0f,};
};

#endif
