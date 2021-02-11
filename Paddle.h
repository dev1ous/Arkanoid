#pragma once
#include "tools.h"

class Paddle
{
private:
	float xpad;
	float ypad;
	sf::Color Red;
	sf::RectangleShape PaddleShape;
	sf::Vector2f Size;

public:
	Paddle(float _xpad, float _ypad, sf::Color _color, sf::Vector2f _size);
	~Paddle();
	float getXpad();
	float getYpad();
	void setXpad(float _x);
	void setYpad(float _y);
	sf::Vector2f getSize();
	void setSize(sf::Vector2f _size);
	sf::RectangleShape getShapePad();
	void setFillColor(sf::Color _color);
};

