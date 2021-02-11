#pragma once
#include "tools.h"

class Bonus
{
private:
	float radbonus;
	sf::Color Yellow;
	sf::CircleShape BonusShape;
	sf::Vector2f posBonus;
public:
	Bonus(float _radbonus, sf::Color _color, sf::Vector2f _posbonus);
	~Bonus();
	sf::CircleShape getShapeBonus();
	float getRadius();
	void setRadius(float _radbonus);
	void setFillColor(sf::Color _color);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _posbonus);

};

