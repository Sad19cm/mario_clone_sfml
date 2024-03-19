#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animacja.h"
#include "Collider.h"




class Przeciwnik
{
public:
	Przeciwnik(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia, sf::Vector2f pozycja, float szybkosc);
	void aktualnie(float dczas);
	void draw(sf::RenderWindow& window);
	Collider SprawdzZderzenie();
	void zabij();
	bool jestZywy;
	

private:
	sf::RectangleShape cialo;
	Animacja animacja;
	Animacja animacjasmierc;
	unsigned int rzad;
	bool wPrawo;
	float szybkosc;
	sf::Vector2f pozycja;
	sf::Vector2f predkosc;
	int k = 0;
	

};

