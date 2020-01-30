#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::RectangleShape rect;

	float speed;

	float x_speed;
	float y_speed;

	float x_rectSpeed;
	float y_rectSpeed;

	Input* input;
};