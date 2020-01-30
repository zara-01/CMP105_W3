#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(2.f);

	rect.setSize(sf::Vector2f(60, 70));
	rect.setPosition(400, 400);
	rect.setFillColor(sf::Color::White);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(2.f);

	speed = 200.f;

	x_speed = speed;
	y_speed = speed;

	x_rectSpeed = 0;
	y_rectSpeed = 0;

	//float circle_x = circle.getPosition().x;
	//float circle_y = circle.getPosition().y;

	//float move_x = speed;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//move down
	if (input->isKeyDown(sf::Keyboard::Down)) 
	{
		y_rectSpeed = 100;
	}
	else
	{
		y_rectSpeed = 0;
	}

	//move up
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		y_rectSpeed = -100;
	}
	else
	{
		y_rectSpeed = 0;
	}

	//move left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		x_rectSpeed = -100;
	}
	else
	{
		x_rectSpeed = 0;
	}

	//move right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		x_rectSpeed = 100;
	}
	else
	{
		x_rectSpeed = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	// update/move circle and rect

	circle.move(x_speed * dt, y_speed * dt);
	rect.move(x_rectSpeed * dt, y_rectSpeed * dt);

	//check if circle hits any walls
	if (circle.getPosition().x > window->getSize().x)
	{
		x_speed = -x_speed;
	}

	if (circle.getPosition().y > window->getSize().y)
	{
		y_speed = -y_speed;
	}

	if (circle.getPosition().x < 0)
	{
		x_speed = -x_speed;
	}

	if (circle.getPosition().y < 0)
	{
		y_speed = -y_speed;
	}



}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(circle);
	window->draw(rect);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}