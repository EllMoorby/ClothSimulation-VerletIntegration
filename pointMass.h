#pragma once
#include "settings.h"
#include <SFML/Graphics.hpp>
#include <iostream>

struct Link {
	int p1Index;
	int p2Index;
	float restingDistance;
	float tearDistance;
	float stiffness;
};

class PointMass
{
private:
	sf::CircleShape body;
	sf::Vector2f velocity;
	sf::Vector2f lastPosition;
	sf::Vector2f nextPosition;
	sf::Vector2f acceleration;
	sf::Vector2f pinPosition;
	std::vector<Link> currentLinks;
	std::vector<PointMass> currentPoints;
	bool pinned;

public:
	PointMass();
	sf::Vector2f position;
	void createPoint(float x, float y, unsigned int radius, bool pinned);
	void update(sf::RenderWindow& window, std::vector<Link>& links, std::vector<PointMass>& points);
	void updateRender();
	void solveConstraints(std::vector<Link>& links, std::vector<PointMass>& points);
};

