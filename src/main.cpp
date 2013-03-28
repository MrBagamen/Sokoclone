#include "player.hpp"
#include "wall.hpp"
#include "map.hpp"
#include <vector>

void InitGL();

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 600, 32), "Shitpickle", sf::Style::Close);
	sf::Event event;
	win.setVerticalSyncEnabled(true);
	win.setKeyRepeatEnabled(false);

	InitGL();

	//Count FPS
	int frame = 0;
	sf::Clock frameTimer;
	sf::Clock deltaTimer;

	//Player
	Player p;
	p.SetPos(128, 128);

	//Test map
	Map m;
	m.Load("res/map.txt");

	while(win.isOpen())
	{
		while(win.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					win.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{
						win.close();
					}
					p.OnKeyPressed(event.key.code);
					break;
				default:;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		p.Cycle();

        m.Draw();
		win.display();
		if(frameTimer.getElapsedTime().asSeconds() >= 1.0f)
		{
			printf("FPS: %d\n", frame);
			frame = 0;
			frameTimer.restart();
		}
		frame++;
	}
	return 0;
}

void InitGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 600, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.1f, 0.5f, 0.0f, 1.0f);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND);

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
