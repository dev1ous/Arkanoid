#include "Ball.h"

Ball::~Ball()
{
}
Ball::Ball(float _radius, sf::Color _color, float _xb, float _yb)
{
	ShapeBall.setRadius(_radius);
	ShapeBall.setFillColor(_color);
	ShapeBall.setPosition(_xb, _yb);
	x = _xb;
	y = _yb;
	ShapeBall;
}
float Ball::getRadius()
{
	return radius;
}
void Ball::setRadius(float _radius)
{
	radius = _radius;
}
float Ball::getX()
{
	return x;
}
float Ball::getY()
{
	return y;
}
sf::CircleShape Ball::getShape()
{
	return ShapeBall;
}
void Ball::setX(float _x)
{
	x = _x;
	ShapeBall.setPosition(x, y);
}
void Ball::setY(float _y)
{
	y = _y;
	ShapeBall.setPosition(x, y);
}
void Ball::setFillColor(sf::Color _color)
{
	Green = _color;
}
