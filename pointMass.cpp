#include "pointMass.h"
PointMass::PointMass() {
	velocity = sf::Vector2f(.0f, .0f);
	position, lastPosition = sf::Vector2f(0.0f, .0f);
	lastPosition = sf::Vector2f(.0f, .0f);
	acceleration = sf::Vector2f(.0f, .2f);
}

void PointMass::createPoint(float x, float y, unsigned int radius, bool pinned) {
	body.setRadius(radius);
	position = sf::Vector2f(x, y);
	lastPosition = position;
	pinPosition = position;
	this->pinned = pinned;
	updateRender();
}

void PointMass::update(sf::RenderWindow& window) {
	velocity = position - lastPosition;
	velocity.x *= 0.99;
	velocity.y *= 0.99;

	nextPosition.x = position.x + velocity.x + acceleration.x * 16;
	nextPosition.y = position.y + velocity.y + acceleration.y * 16;
		
	lastPosition = position;
	
	position = nextPosition;
		// solve constraints, look for collisions, etc.
	solveConstraints();
	
	updateRender();
	window.draw(body);
}

void PointMass::solveConstraints() {

	if (position.x < 1) {
		position.x = 2 * (1) - position.x;
	}
	if (position.y < 1) {
		position.y = 2 * (1) - position.y;
	}
	if (position.x > Settings::ScreenWidth - 1) {
		position.x = 2 * (Settings::ScreenWidth - 1) - position.x;
	}
	if (position.y > Settings::ScreenHeight - 1) {
		position.y = 2 * (Settings::ScreenHeight - 1) - position.y;
	}

	if (pinned) {
		position = pinPosition;
	}
}

void PointMass::setPosition(sf::Vector2f pos) {
	position = pos;
}

void PointMass::updateRender() {
	body.setPosition(position - sf::Vector2f(body.getRadius(), body.getRadius()));
}

void PointMass::test() {
	body.setFillColor(sf::Color::Blue);
}
