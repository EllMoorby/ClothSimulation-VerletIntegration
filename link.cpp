#include "link.h"
//PointMass& a, PointMass& b, float restingDistance, float tearDistance, float stiffness
Link::Link(PointMass& a, PointMass& b, float restingDistance, float tearDistance, float stiffness) : p1(a), p2(b) {
	this->restingDistance = restingDistance;
	this->tearDistance = tearDistance;
	this->stiffness = stiffness;
	this->p1 = a;
	this->p2 = b;
}

void Link::solve() {
	// calculate the distance
	difference = p1.position - p2.position;

	float distance = sqrt(difference.x * difference.x + difference.y * difference.y);

	// difference scalar

	float differenceScalar = (restingDistance - distance) / distance;

	// translation for each PointMass. They'll be pushed 1/2 the required distance to match their resting distances.

	float translateX = difference.x * 0.5 * differenceScalar;
	float translateY = difference.y * 0.5 * differenceScalar;

	p1.position.x += translateX;
	p1.position.y += translateY;

	p2.position.x -= translateX;
	p2.position.y -= translateY;

}