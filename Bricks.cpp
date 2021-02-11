#include "Bricks.h"

Bricks::Bricks(sf::Vector2f _posbricks, sf::Color _color, sf::Vector2f _sizebricks, sf::Color _coloroutline, float _thickness)
{
	BricksShape.setPosition(_posbricks);
	BricksShape.setSize(_sizebricks);
	BricksShape.setFillColor(_color);
	BricksShape.setOutlineColor(_coloroutline);
	BricksShape.setOutlineThickness(_thickness);
	BricksShape;
}

Bricks::~Bricks()
{
}

void Bricks::setPosition(sf::Vector2f _posbricks)
{
	posbricks.x = _posbricks.x;
	posbricks.y = _posbricks.y;
}
void Bricks::setSize(sf::Vector2f _sizebricks)
{
	SizeBricks.x = _sizebricks.x;
	SizeBricks.y = _sizebricks.y;
}
void Bricks::setOutlineThickness(float _thickness)
{
	thickness = _thickness;
}
sf::RectangleShape Bricks::getBricksShape()
{
	return BricksShape;
}
void Bricks::setFillColor(sf::Color _color)
{
	Blue = _color;
}
void Bricks::setOutlineColor(sf::Color _coloroutline)
{
	Black = _coloroutline;
}
