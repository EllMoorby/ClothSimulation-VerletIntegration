#pragma once
#include <SFML/Graphics.hpp>
#include "link.h"
#include "pointMass.h"


#include <iostream>

class Application
{
private:
	sf::RenderWindow window;
	sf::Event event;
	std::vector<PointMass> points;
	std::vector<Link> links;
	sf::Clock clock;
	float elapsedTime;
	sf::Time lastTime;
	sf::Time currentTime;
	float leftOverTime;
	int timesteps;
	sf::Vector2i mousePosition;

public:
	Application();
	void start(); //Starts the program
	void createWindow();
	void update(); //Runs every frame
	void destroyWindow();
	void generatePoints(unsigned int numPoints);
	void createPoint(float x, float y, unsigned int radius, bool pinned);
};

