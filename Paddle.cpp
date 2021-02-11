#include "Paddle.h"

Paddle::Paddle(float _xpad, float _ypad, sf::Color _color, sf::Vector2f _size)
{
	PaddleShape.setPosition(_xpad, _ypad);
	PaddleShape.setFillColor(_color);
	PaddleShape.setSize(_size);
	xpad = _xpad;
	ypad = _ypad;
	Size = _size;
	PaddleShape;
}

Paddle::~Paddle()
{
}

float Paddle::getXpad()
{
	return xpad;
}

float Paddle::getYpad()
{
	return ypad;
}

void Paddle::setXpad(float _x)
{
	xpad = _x;
	PaddleShape.setPosition(xpad, ypad);
}

void Paddle::setYpad(float _y)
{
	ypad = _y;
}

sf::Vector2f Paddle::getSize()
{
	return Size;
}

void Paddle::setSize(sf::Vector2f _size)
{
	Size.x = _size.x;
    Size.y = _size.y;
	PaddleShape.setSize(Size);
}

sf::RectangleShape Paddle::getShapePad()
{
	return PaddleShape;
}

void Paddle::setFillColor(sf::Color _color)
{
	Red = _color;
}
