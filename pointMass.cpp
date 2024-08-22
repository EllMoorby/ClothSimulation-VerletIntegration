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

void PointMass::update(sf::RenderWindow& window, std::vector<Link>& links, std::vector<PointMass>& points) {
	velocity = position - lastPosition;
	velocity.x *= 0.99;
	velocity.y *= 0.99;

	nextPosition.x = position.x + velocity.x + acceleration.x * 16;
	nextPosition.y = position.y + velocity.y + acceleration.y * 16;
		
	lastPosition = position;
	
	position = nextPosition;
		// solve constraints, look for collisions, etc.
	solveConstraints(links, points);
	
	updateRender();
	window.draw(body);
}

void PointMass::solveConstraints(std::vector<Link>& links, std::vector<PointMass>& points) {

	for (Link& link : links) {
		sf::Vector2f difference = points[link.p1Index].position - points[link.p2Index].position;

		float distance = sqrt(difference.x * difference.x + difference.y * difference.y);

		// difference scalar

		float differenceScalar = (link.restingDistance - distance) / distance;

		// translation for each PointMass. They'll be pushed 1/2 the required distance to match their resting distances.

		float translateX = difference.x * 0.1 * differenceScalar;
		float translateY = difference.y * 0.1 * differenceScalar;

		points[link.p1Index].position.x += translateX;
		points[link.p1Index].position.y += translateY;
		points[link.p2Index].position.x -= translateX;
		points[link.p2Index].position.y -= translateY;
	}
	



	if (position.x < 1) {
		position.x = lastPosition.x;
	}
	if (position.y < 1) {
		position.y = lastPosition.y;
	}
	if (position.x > Settings::ScreenWidth - 1) {
		position.x = lastPosition.x;
	}
	if (position.y > Settings::ScreenHeight - 1) {
		position.y = lastPosition.y;
	}

	if (pinned) {
		position = pinPosition;
	}
}

void PointMass::updateRender() {
	body.setPosition(position - sf::Vector2f(body.getRadius(), body.getRadius()));
}


