#pragma once
#include "settings.h"
#include <SFML/Graphics.hpp>

class PointMass
{
private:
	sf::CircleShape body;
	sf::Vector2f position;
	sf::Vector2f velocity;
public:
	PointMass();
	void createPoint(float x, float y, unsigned int radius);
	sf::CircleShape getBody();
	void update(int timesteps);
	void updateRender();
};

