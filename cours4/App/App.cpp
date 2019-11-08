// App.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include "Lib.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <direct.h>

using namespace sf;

float lerp(float a, float b, float r) {
	return a + (b - a) * r;
}

float rd() {
	return 1.0 * rand() / RAND_MAX;
}

void drawCurve(sf::RenderWindow &win, float now) {
	sf::VertexArray va(sf::LineStrip);
	sf::Color red = sf::Color::Red;
	sf::Color blue = sf::Color::Blue;
	int nb = 16;
	float stride = 1280.0 / nb;
	
	int ofsX = 0;
	if (fmodf(now, 2.0) <= 1) {
		red.a = 0;
	}

	for (int i = 0; i < nb+1; ++i) {
		double ratio = 1.0 * i / nb;
		double x = ofsX + stride * i;
		double y = 400;

		//y += (ratio*ratio*1.33)* sin( ratio * now * 8.0) * 256 + rd() * 8;

		//x = 500 + cos(ratio * 2 * 3.141569) * (now * 20);
		//y = 500 + sin(ratio * 2 * 3.141569) * ( now * 20);

		//x = 500 + cos(ratio * 2 * 3.141569) * ( now * now * 20 * (0.5 + rd() * 0.5));
		//y = 500 + sin(ratio * 2 * 3.141569) * (now * now * 20 * (0.5 + rd() * 0.5));

		//y += sin(now) * 200;
		//y += ratio * ratio * sin(ratio * 8.0 + now) * 256;

		y += sin(ratio * 8.0 + now * 3) * 120;

			//y += sin(ratio * 8.0 + now) * (128 * 1.0 + cos(now*16) * 4);

			/*
			int radius = 160;
			x = 500 + radius * cos( ratio * 2 * 3.141569) + sin(now*10 * cos(ratio)) * 8 * (1.0 + rd() * 100);
			y = 500 + radius * sin( ratio * 2 * 3.141569) + cos(now * 10 * sin(ratio)) * 10 * (1.0 + rd() * 100);
			*/
			/*
		sf::Color c = sf::Color(
			lerp(blue.r, red.r,ratio),
			lerp(blue.g, red.g, ratio),
			lerp(blue.b, red.b, ratio)
		);
		*/
		sf::Color c = i % 2 ? red : blue;

		sf::Vertex vertex(Vector2f(x,y), c);
		va.append(vertex);
	}
	win.draw(va);
}

int main()
{
    std::cout << "Hello World!\n"; 

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(false);

	sf::CircleShape shape(100.f, (int) (2 * 3.141569 * 100));
	shape.setPosition(30, 30);
	shape.setFillColor(sf::Color(0xE884D4ff) );
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color(0xFF8A70ff));

	sf::Clock clock;

	sf::Time appStart = clock.getElapsedTime();
	sf::Time frameStart = clock.getElapsedTime();
	sf::Time prevFrameStart = clock.getElapsedTime();

	float fps[4] = { 0.f,0.f,0.f,0.f };
	int step = 0;
	sf::Font * font = new sf::Font();
	if (font->loadFromFile("res/DejaVuSans.ttf") == false) {
		printf("no such font\n");
	}

	sf::Text myFpsCounter;
	int every = 0;
	while (window.isOpen())//on passe tout le temps DEBUT DE LA FRAME 
	{
		sf::Event event;//recup les evenement clavier/pad
		frameStart = clock.getElapsedTime();
		while (window.pollEvent(event))	{
			switch (event.type ) {
				case sf::Event::KeyReleased :

					if (event.key.code == sf::Keyboard::I)
						printf("instant fps %f\n", fps[(step-1)%4]);

					if (event.key.code == sf::Keyboard::F)
						printf("fps %f\n", 0.25f*(fps[0] + fps[1] + fps[2] + fps[3]) );
					
					break;


				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}
		
		myFpsCounter.setPosition(8, 8);
		myFpsCounter.setFillColor(sf::Color::Red);
		myFpsCounter.setFont(*font);

		if (every == 0) {
			myFpsCounter.setString(std::string("FPS:") + std::to_string(fps[(step - 1) % 4]));
			every = 30;
		}
		every--;

		window.clear();//nettoie la frame

		drawCurve(window, clock.getElapsedTime().asSeconds() );

		window.draw(shape);//on demande le dessin d' une forme
		window.draw(myFpsCounter);
		window.display();//ca dessine et ca attend la vsync

		fps[step % 4] = 1.0f / (frameStart - prevFrameStart).asSeconds();
		prevFrameStart = frameStart;

		step++;
	}

	return 0;
}
