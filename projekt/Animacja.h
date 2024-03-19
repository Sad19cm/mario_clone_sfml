#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Animacja
{
public:
	Animacja(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia);
	sf::IntRect xyRect;
	void update(int rzad, float dczas, bool wPrawo);
	void smiercKripera(int rzad, float dczas, bool wPrawo, bool powrot);


private:
	sf::Vector2u licznikObrazkow;
	sf::Vector2u obecnyObrazek;

	float calkowityCzas;
	float czasPrzelaczenia;


};

