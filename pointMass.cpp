#include "pointMass.h"
PointMass::PointMass() {
	velocity = sf::Vector2f(-.1f, -.1f);
	position = sf::Vector2f(.0f, .0f);
}

void PointMass::createPoint(float x, float y, unsigned int radius) {
	body.setRadius(radius);
	position = sf::Vector2f(x, y);
	updateRender();

}

void PointMass::update(int timesteps) {

	for (int i = 0; i < timesteps; i++) {
		position.x = position.x + velocity.x * 16;
		position.y = position.y + velocity.y * 16;
			// solve constraints, look for collisions, etc.

		if (position.x < 0) {
			position.x = 0;
			if (velocity.x != 0) {
				velocity.x *= -1;
			}
		}
		if (position.y < 0) {
			position.y = 0;
			if (velocity.y != 0) {
				velocity.y *= -1;
			}
		}

		if (position.x > Settings::ScreenWidth) {
			position.x = Settings::ScreenWidth;
			if (velocity.x != 0) {
				velocity.x *= -1;
			}
		}
		if (position.y > Settings::ScreenHeight) {
			position.y = Settings::ScreenHeight;
			if (velocity.y != 0) {
				velocity.y *= -1;
			}
		}

	}


	updateRender();
}

sf::CircleShape  PointMass::getBody() {
	return body;
}

void PointMass::updateRender() {
	body.setPosition(position - sf::Vector2f(body.getRadius(), body.getRadius()));
}