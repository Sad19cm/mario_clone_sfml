#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animacja.h"
#include "Collider.h"
#include "Przeciwnik.h"
#include <iostream>

class Gracz : public sf::Sprite
{

	sf::Texture tekstura;
	sf::Vector2f pozycja;
	
	
	
public:
	Gracz(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia, float szybkosc, float wysokoscSkoku);
	void aktualnie(float dczas);
	void draw(sf::RenderWindow& window);
	sf::Vector2f GetPositionWidok();
	Collider SprawdzZderzenie();
	void naZiemi(sf::Vector2f kierunek);
	void kontaktZPrzeciwnikiem(Przeciwnik& przeciwnik , sf::Vector2f kierunek);
	void rysujHp(sf::Texture* tekstura, sf::Vector2f &pozycja, sf::RenderWindow& window);
	int getHp();
	float czasOpoznienia;
	void kontaktZLawa( sf::Vector2f kierunek);

private:
	sf::Music smierc;
	sf::Music skok;
	sf::RectangleShape cialo;
	sf::Music hit;
	sf::RectangleShape hitbox;
	//float czasOpoznienia;
	Animacja animacja;
	unsigned int rzad;
	bool wPrawo;
	float szybkosc;
	sf::RectangleShape hpBar;
	sf::Vector2f predkosc;
	bool mozeSkoczyc=true;
	float wysokoscSkoku;
	int hp;
};

