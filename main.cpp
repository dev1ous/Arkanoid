#include "tools.h"

//surcharges de fonctions
bool isCollide(Ball& _shape1, Bricks& _shape2);
bool isCollide(Ball& _shape1, Paddle& _shape2);
bool isCollide(Paddle& _shape1, Bonus& _shape2);

float GetTimeDeltaF();
sf::Time GetTimeDeltaT();
void RestartClock(sf::Clock& _c);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid-like");
	window.setFramerateLimit(60);

	bool x = false;
	bool y = false;
	float TimerBonus{ 0 };
	sf::Clock clock;

	Ball ball(10, sf::Color::Green, 400,500);
	Paddle paddle(350,580,sf::Color::Red,sf::Vector2f(150,20));
	std::vector<Bricks> bricks{ Bricks(sf::Vector2f(0,0), sf::Color::Blue, sf::Vector2f(80,30), sf::Color::Black, 1)};
	std::vector<Bonus> bonus{ Bonus(0,sf::Color::Yellow,sf::Vector2f(400,100)) };

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			bricks.push_back(Bricks(sf::Vector2f(i*80, j*30), sf::Color::Blue, sf::Vector2f(80, 30), sf::Color::Black, 1));
		}
	}
	
	while (window.isOpen())
	{
		RestartClock(clock);
		TimerBonus += GetTimeDeltaF();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Collision briques et balle
		int n = 0;
		for (Bricks& brickActuelle : bricks)
		{
			if (isCollide(ball, brickActuelle))
			{
				bricks.erase(bricks.begin() + n);
				y = !y;
				break;
			}
			n++;
		}

		//Collision balle et paddle
		if (isCollide(ball, paddle))
		{
			y = -!y;
		}

		//Collision bonus et paddle
		int m = 0;
		for (Bonus& bonusActuelle : bonus)
		{
			if (isCollide(paddle, bonusActuelle))
			{
				bonus.erase(bonus.begin() + m);
				paddle.setSize(sf::Vector2f(paddle.getSize().x + 5, paddle.getSize().y));
				break;
			}
			m++;
		}

		//Déplacement du Paddle
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if(paddle.getXpad() <650)
				paddle.setXpad(paddle.getXpad() + 5);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			if(paddle.getXpad()>0)
				paddle.setXpad(paddle.getXpad() - 5);

		//Déplacement de la balle
		if (x)
		{
			ball.setX(ball.getX() + 3);
			ball.setY(ball.getY());
		}
		if (!x)
		{
			ball.setX(ball.getX() - 3);
			ball.setY(ball.getY());
		}

		if (y)
		{
			ball.setY(ball.getY() + 3);
			ball.setX(ball.getX());
		}
		if (!y)
		{
			ball.setY(ball.getY() - 3);
			ball.setX(ball.getX());
		}

		if (ball.getX()> 780)
			x = false;
		if (ball.getX() < 0)
			x = true;
		if (ball.getY() < 0)
			y = true;
		//La balle se TP quand elle touche le sol et revient à sa pos de départ
		if (ball.getY() > 580)
		{
			ball.setX(400);
			ball.setY(520);
		}
		
		//Déplacement Bonus
		for (Bonus& bonusActuelle : bonus)
		{
			if (bonusActuelle.getPosition().y < 600 )
				bonusActuelle.setPosition(sf::Vector2f(bonusActuelle.getPosition().x, bonusActuelle.getPosition().y + 3));
		}
		//Apparition Bonus

		if (TimerBonus > 10)
		{
			bonus.push_back( Bonus(5,sf::Color::Yellow,sf::Vector2f(rand() % (800) + 1,0)));
			TimerBonus = 0;
		}
		//les displays
		window.clear(sf::Color::Color(100,100,100,255));
		window.draw(ball.getShape());
		window.draw(paddle.getShapePad());
		for (Bricks& brickActuelle : bricks)
			window.draw(brickActuelle.getBricksShape());
		for (Bonus& bonusActuelle : bonus)
			window.draw(bonusActuelle.getShapeBonus());
		window.display();
	}
	return 0;
 }