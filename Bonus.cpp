#include "Bonus.h"

Bonus::Bonus(float _radbonus, sf::Color _color, sf::Vector2f _posbonus)
{
	BonusShape.setFillColor(_color);
	BonusShape.setRadius(_radbonus);
	BonusShape.setPosition(_posbonus);
	posBonus = _posbonus;
	BonusShape;
}

Bonus::~Bonus()
{
}

sf::CircleShape Bonus::getShapeBonus()
{
	return BonusShape;
}

float Bonus::getRadius()
{
	return radbonus;
}

void Bonus::setRadius(float _radbonus)
{
	radbonus = _radbonus;
}

void Bonus::setFillColor(sf::Color _color)
{
	Yellow = _color;
}

sf::Vector2f Bonus::getPosition()
{
	return posBonus;
}

void Bonus::setPosition(sf::Vector2f _posbonus)
{
	posBonus.x = _posbonus.x;
	posBonus.y = _posbonus.y;
	BonusShape.setPosition(posBonus);
}

