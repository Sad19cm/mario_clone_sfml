#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Collider
{
public:
	Collider(sf::RectangleShape& cialo);
	bool sprawdzKolizje(Collider inny,sf::Vector2f& kierunek , float przesun);
	sf::Vector2f GetPosition();
	sf::Vector2f GetPolowaRozmiaru();
	void ruch(float dx, float dy);


	sf::RectangleShape& cialo;


};

