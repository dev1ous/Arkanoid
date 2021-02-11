#pragma once
#include "tools.h"

class Ball
{
private:
	float radius;
	sf::Color Green;
	sf::CircleShape ShapeBall;
	float x;
	float y;

public:

	Ball(float _radius, sf::Color _color, float _xb, float _yb);
	~Ball();
	float getRadius();
	void setRadius(float _radius);
	float getX();
	float getY();
	sf::CircleShape getShape();
	void setX(float _x);
	void setY(float _y);
	void setFillColor(sf::Color _color);
};

