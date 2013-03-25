#include "../include/player.hpp"

bool keys[512];
void InitGL();

int main()
{
	memset(keys, 0, 512);

	sf::RenderWindow win(sf::VideoMode(800, 600, 32), "Shitpickle", sf::Style::Close);
	sf::Event event;
	win.setVerticalSyncEnabled(true);

	InitGL();

	//Count FPS
	int frame = 0;
	sf::Clock frameTimer;

	//Test Player
	Player p;
	p.Init();
	p.SetPos(100, 100);

	while(win.isOpen())
	{
		while(win.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					win.close();
				case sf::Event::KeyPressed:
					keys[event.key.code] = true;
				break;
				case sf::Event::KeyReleased:
					keys[event.key.code] = false;
				break;
				default:;
			}
		}
		if(keys[sf::Keyboard::Escape]){win.close();}
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		//Render shit
		p.Cycle(keys);

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

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND);

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}