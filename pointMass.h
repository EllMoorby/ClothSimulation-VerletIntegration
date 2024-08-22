#pragma once
#include "settings.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class PointMass
{
private:
	sf::CircleShape body;
	sf::Vector2f velocity;
	sf::Vector2f lastPosition;
	sf::Vector2f nextPosition;
	sf::Vector2f acceleration;
	sf::Vector2f pinPosition;
	bool pinned;

public:
	PointMass();
	sf::Vector2f position;

	void createPoint(float x, float y, unsigned int radius, bool pinned);
	void update(sf::RenderWindow& window);
	void updateRender();
	void solveConstraints();
	void setPosition(sf::Vector2f pos);
	void test();
};

