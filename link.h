#pragma once
#include "SFML/Graphics.hpp"
#include "pointMass.h"

class Link
{
private:
    float restingDistance;
    float tearDistance;
    float stiffness;
    sf::Vector2f difference;
    PointMass& p1;
    PointMass& p2;
    
public:
    
    Link(PointMass& a, PointMass& b, float restingDistance, float tearDistance, float stiffness);
    void solve();
};
