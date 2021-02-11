#include "tools.h"

float fDeltaTime;
sf::Time tDeltaTime;

float GetTimeDeltaF()
{
	return fDeltaTime;
}
sf::Time GetTimeDeltaT()
{
	return tDeltaTime;
}
void RestartClock(sf::Clock& _c)
{
	tDeltaTime = _c.restart();
	fDeltaTime = tDeltaTime.asSeconds();
}
bool isCollide( Ball& _shape1, Bricks& _shape2)
{
	return _shape1.getShape().getGlobalBounds().intersects(_shape2.getBricksShape().getGlobalBounds());
}
bool isCollide(Ball& _shape1, Paddle& _shape2)
{
	return _shape1.getShape().getGlobalBounds().intersects(_shape2.getShapePad().getGlobalBounds());
}
bool isCollide(Paddle& _shape1, Bonus& _shape2)
{
	return _shape1.getShapePad().getGlobalBounds().intersects(_shape2.getShapeBonus().getGlobalBounds());
}