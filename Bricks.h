#pragma once
#include "tools.h"

class Bricks
{
private:
	sf::Vector2f posbricks;
	sf::RectangleShape BricksShape;
	sf::Color Blue;
	sf::Vector2f SizeBricks;
	sf::Color Black;
	float thickness;

public:
	Bricks(sf::Vector2f _posbricks, sf::Color _color, sf::Vector2f _sizebricks, sf::Color _coloroutline, float _thickness);
	~Bricks();
	void setPosition(sf::Vector2f _posbricks);
	void setSize(sf::Vector2f _sizebricks);
	void setOutlineThickness(float _thickness);
	void setOutlineColor(sf::Color _coloroutline);
	sf::RectangleShape getBricksShape();
	void setFillColor(sf::Color _color);

};

