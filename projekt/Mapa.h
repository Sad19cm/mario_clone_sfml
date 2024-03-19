#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Platforma.h"
#include <vector>
#include "Przeciwnik.h"

class Mapa
{
	sf::Vector2i pozycjaGracza;
	sf::Vector2i pozycjaSkarbu;
	std::vector<sf::Vector2i> pozycjePrzeciwnikow;
	

	
	void ustawDomyslnie();
	void ustawPrzeciwnikow();
	void ustawPlatformy();
	void ustawLawe();
	void ustawSkarb();
	void ustawPrzelacznik();

public:
	sf::Texture teksturaPrzeciwnik;
	std::vector<Przeciwnik> przeciwnicy;
	std::vector<Platforma> lawy;
	std::vector<std::vector<Platforma*>> platformy;
	int  szerokoscSiatki;
	Mapa();
	bool odblokowany = false;

};

