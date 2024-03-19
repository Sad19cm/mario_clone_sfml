#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Collider.h"

class Platforma 
{
public:
	sf::Vector2f pozycja;
	sf::Texture tekstura;
	bool kolizyjna;
	sf::Vector2f rozmiar = sf::Vector2f(50, 50);
	Collider SprawdzZderzenie();
	
	Platforma(float posx, float posy,  std::string t,  bool s );
	bool ustawPlatforme(std::string);
	sf::RectangleShape sprite;

};

