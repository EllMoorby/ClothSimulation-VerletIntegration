#pragma once
#include <SFML/Graphics.hpp>
#include "pointMass.h"
#include <iostream>

class Application
{
private:
	sf::RenderWindow window;
	sf::Event event;
	PointMass point;
	sf::Clock clock;
	float elapsedTime;
	sf::Time lastTime;
	sf::Time currentTime;
	float leftOverTime;

public:
	Application();
	void start(); //Starts the program
	void createWindow();
	void update(); //Runs every frame
	void destroyWindow();
};

