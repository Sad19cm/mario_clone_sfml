#include "Mapa.h"


Mapa::Mapa() {
	szerokoscSiatki = 20;
	ustawDomyslnie();
}

void Mapa::ustawDomyslnie() {
	
	ustawPrzeciwnikow();
	ustawPlatformy();
	ustawLawe();
	ustawSkarb();
	ustawPrzelacznik();

}
void Mapa::ustawPrzeciwnikow() {
	teksturaPrzeciwnik.loadFromFile("Przeciwnikt2.png");
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(500, 900), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(650, 900), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(650, 700), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(150, 650), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(500, 450), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(800, 450), 50.0f));
	przeciwnicy.push_back(Przeciwnik(&teksturaPrzeciwnik, sf::Vector2u(4, 2), 0.2f, sf::Vector2f(600, 200), 50.0f));

}
void Mapa::ustawPlatformy() {
	platformy.clear();
	std::vector<Platforma*> Rzad1;
	Rzad1.push_back(new Platforma(0, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(50, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(100, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(150, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(200, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(250, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(300, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(350, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(400, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(450, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(500, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(550, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(600, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(650, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(700, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(750, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(800, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(850, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(900, 0, "cegla.png", 1));
	Rzad1.push_back(new Platforma(950, 0, "cegla.png", 1));
	platformy.push_back(Rzad1);

	std::vector<Platforma*> Rzad2;
	Rzad2.push_back(new Platforma(0, 50, "cegla.png", 1));
	Rzad2.push_back(new Platforma(50, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(100, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(150, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(200, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(250, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(300, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(350, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(400, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(450, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(500, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(550, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(600, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(650, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(700, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(750, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(800, 50, "tlo.png", 0));
	Rzad2.push_back(new Platforma(850, 50, "krata.png", 1));
	Rzad2.push_back(new Platforma(900, 50, "skrzynka.png", 0));
	Rzad2.push_back(new Platforma(950, 50, "cegla.png", 1));
	platformy.push_back(Rzad2);

	std::vector<Platforma*> Rzad3;
	Rzad3.push_back(new Platforma(0, 100, "cegla.png", 1));
	Rzad3.push_back(new Platforma(50, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(100, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(150, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(200, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(250, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(300, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(350, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(400, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(450, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(500, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(550, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(600, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(650, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(700, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(750, 100, "tlo.png", 0));
	Rzad3.push_back(new Platforma(800, 100, "cegla.png", 1));
	Rzad3.push_back(new Platforma(850, 100, "cegla.png", 1));
	Rzad3.push_back(new Platforma(900, 100, "cegla.png", 1));
	Rzad3.push_back(new Platforma(950, 100, "cegla.png", 1));
	platformy.push_back(Rzad3);

	std::vector<Platforma*> Rzad4;
	Rzad4.push_back(new Platforma(0, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(50, 150, "przycisk.png", 0));
	Rzad4.push_back(new Platforma(100, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(150, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(200, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(250, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(300, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(350, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(400, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(450, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(500, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(550, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(600, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(650, 150, "tlo.png", 0));
	Rzad4.push_back(new Platforma(700, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(750, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(800, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(850, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(900, 150, "cegla.png", 1));
	Rzad4.push_back(new Platforma(950, 150, "cegla.png", 1));
	platformy.push_back(Rzad4);

	std::vector<Platforma*> Rzad5;
	Rzad5.push_back(new Platforma(0, 200, "cegla.png", 1));
	Rzad5.push_back(new Platforma(50, 200, "cegla.png", 1));
	Rzad5.push_back(new Platforma(100, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(150, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(200, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(250, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(300, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(350, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(400, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(450, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(500, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(550, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(600, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(650, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(700, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(750, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(800, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(850, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(900, 200, "tlo.png", 0));
	Rzad5.push_back(new Platforma(950, 200, "cegla.png", 1));
	platformy.push_back(Rzad5);

	std::vector<Platforma*> Rzad6;
	Rzad6.push_back(new Platforma(0, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(50, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(100, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(150, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(200, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(250, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(300, 250, "kolce.png", 1));
	Rzad6.push_back(new Platforma(350, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(400, 250, "kolce.png", 1));
	Rzad6.push_back(new Platforma(450, 250, "kolce.png", 1));
	Rzad6.push_back(new Platforma(500, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(550, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(600, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(650, 250, "cegla.png", 1));
	Rzad6.push_back(new Platforma(700, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(750, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(800, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(850, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(900, 250, "tlo.png", 0));
	Rzad6.push_back(new Platforma(950, 250, "cegla.png", 1));
	platformy.push_back(Rzad6);

	std::vector<Platforma*> Rzad7;
	Rzad7.push_back(new Platforma(0, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(50, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(100, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(150, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(200, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(250, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(300, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(350, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(400, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(450, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(500, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(550, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(600, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(650, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(700, 300, "cegla.png", 1));
	Rzad7.push_back(new Platforma(750, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(800, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(850, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(900, 300, "tlo.png", 0));
	Rzad7.push_back(new Platforma(950, 300, "cegla.png", 1));
	platformy.push_back(Rzad7);

	std::vector<Platforma*> Rzad8;
	Rzad8.push_back(new Platforma(0, 350, "cegla.png", 1));
	Rzad8.push_back(new Platforma(50, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(100, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(150, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(200, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(250, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(300, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(350, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(400, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(450, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(500, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(550, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(600, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(650, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(700, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(750, 350, "cegla.png", 1));
	Rzad8.push_back(new Platforma(800, 350, "cegla.png", 1));
	Rzad8.push_back(new Platforma(850, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(900, 350, "tlo.png", 0));
	Rzad8.push_back(new Platforma(950, 350, "cegla.png", 1));
	platformy.push_back(Rzad8);

	std::vector<Platforma*> Rzad9;
	Rzad9.push_back(new Platforma(0, 400, "cegla.png", 1));
	Rzad9.push_back(new Platforma(50, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(100, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(150, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(200, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(250, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(300, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(350, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(400, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(450, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(500, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(550, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(600, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(650, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(700, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(750, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(800, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(850, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(900, 400, "tlo.png", 0));
	Rzad9.push_back(new Platforma(950, 400, "cegla.png", 1));
	platformy.push_back(Rzad9);

	std::vector<Platforma*> Rzad10;
	Rzad10.push_back(new Platforma(0, 450, "cegla.png", 1));
	Rzad10.push_back(new Platforma(50, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(100, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(150, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(200, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(250, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(300, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(350, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(400, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(450, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(500, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(550, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(600, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(650, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(700, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(750, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(800, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(850, 450, "tlo.png", 0));
	Rzad10.push_back(new Platforma(900, 450, "cegla.png", 1));
	Rzad10.push_back(new Platforma(950, 450, "cegla.png", 1));
	platformy.push_back(Rzad10);

	std::vector<Platforma*> Rzad11;
	Rzad11.push_back(new Platforma(0, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(50, 500, "tlo.png", 0));
	Rzad11.push_back(new Platforma(100, 500, "tlo.png", 0));
	Rzad11.push_back(new Platforma(150, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(200, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(250, 500, "kolce.png", 1));
	Rzad11.push_back(new Platforma(300, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(350, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(400, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(450, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(500, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(550, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(600, 500, "kolce.png", 1));
	Rzad11.push_back(new Platforma(650, 500, "kolce.png", 1));
	Rzad11.push_back(new Platforma(700, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(750, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(800, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(850, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(900, 500, "cegla.png", 1));
	Rzad11.push_back(new Platforma(950, 500, "cegla.png", 1));
	platformy.push_back(Rzad11);

	std::vector<Platforma*> Rzad12;
	Rzad12.push_back(new Platforma(0, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(50, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(100, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(150, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(200, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(250, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(300, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(350, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(400, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(450, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(500, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(550, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(600, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(650, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(700, 550, "cegla.png", 1));
	Rzad12.push_back(new Platforma(750, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(800, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(850, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(900, 550, "tlo.png", 0));
	Rzad12.push_back(new Platforma(950, 550, "cegla.png", 1));
	platformy.push_back(Rzad12);

	std::vector<Platforma*> Rzad13;
	Rzad13.push_back(new Platforma(0, 600, "cegla.png", 1));
	Rzad13.push_back(new Platforma(50, 600, "cegla.png", 1));
	Rzad13.push_back(new Platforma(100, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(150, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(200, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(250, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(300, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(350, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(400, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(450, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(500, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(550, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(600, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(650, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(700, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(750, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(800, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(850, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(900, 600, "tlo.png", 0));
	Rzad13.push_back(new Platforma(950, 600, "cegla.png", 1));
	platformy.push_back(Rzad13);

	std::vector<Platforma*> Rzad14;
	Rzad14.push_back(new Platforma(0, 650, "cegla.png", 1));
	Rzad14.push_back(new Platforma(50, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(100, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(150, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(200, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(250, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(300, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(350, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(400, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(450, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(500, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(550, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(600, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(650, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(700, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(750, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(800, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(850, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(900, 650, "tlo.png", 0));
	Rzad14.push_back(new Platforma(950, 650, "cegla.png", 1));
	platformy.push_back(Rzad14);

	std::vector<Platforma*> Rzad15;
	Rzad15.push_back(new Platforma(0, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(50, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(100, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(150, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(200, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(250, 700, "kolce.png", 1));
	Rzad15.push_back(new Platforma(300, 700, "cegla.png", 1));
	Rzad15.push_back(new Platforma(350, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(400, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(450, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(500, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(550, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(600, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(650, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(700, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(750, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(800, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(850, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(900, 700, "tlo.png", 0));
	Rzad15.push_back(new Platforma(950, 700, "cegla.png", 1));
	platformy.push_back(Rzad15);

	std::vector<Platforma*> Rzad16;
	Rzad16.push_back(new Platforma(0, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(50, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(100, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(150, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(200, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(250, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(300, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(350, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(400, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(450, 750, "tlo.png", 0));
	Rzad16.push_back(new Platforma(500, 750, "tlo.png", 0));
	Rzad16.push_back(new Platforma(550, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(600, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(650, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(700, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(750, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(800, 750, "cegla.png", 1));
	Rzad16.push_back(new Platforma(850, 750, "tlo.png", 0));
	Rzad16.push_back(new Platforma(900, 750, "tlo.png", 0));
	Rzad16.push_back(new Platforma(950, 750, "cegla.png", 1));
	platformy.push_back(Rzad16);

	std::vector<Platforma*> Rzad17;
	Rzad17.push_back(new Platforma(0, 800, "cegla.png", 1));
	Rzad17.push_back(new Platforma(50, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(100, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(150, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(200, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(250, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(300, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(350, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(400, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(450, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(500, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(550, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(600, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(650, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(700, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(750, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(800, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(850, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(900, 800, "tlo.png", 0));
	Rzad17.push_back(new Platforma(950, 800, "cegla.png", 1));
	platformy.push_back(Rzad17);

	std::vector<Platforma*> Rzad18;
	Rzad18.push_back(new Platforma(0, 850, "cegla.png", 1));
	Rzad18.push_back(new Platforma(50, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(100, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(150, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(200, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(250, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(300, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(350, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(400, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(450, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(500, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(550, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(600, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(650, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(700, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(750, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(800, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(850, 850, "tlo.png", 0));
	Rzad18.push_back(new Platforma(900, 850, "cegla.png", 1));
	Rzad18.push_back(new Platforma(950, 850, "cegla.png", 1));
	platformy.push_back(Rzad18);

	std::vector<Platforma*> Rzad19;
	Rzad19.push_back(new Platforma(0, 900, "cegla.png", 1));
	Rzad19.push_back(new Platforma(50, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(100, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(150, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(200, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(250, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(300, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(350, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(400, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(450, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(500, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(550, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(600, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(650, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(700, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(750, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(800, 900, "tlo.png", 0));
	Rzad19.push_back(new Platforma(850, 900, "cegla.png", 1));
	Rzad19.push_back(new Platforma(900, 900, "cegla.png", 1));
	Rzad19.push_back(new Platforma(950, 900, "cegla.png", 1));
	platformy.push_back(Rzad19);

	std::vector<Platforma*> Rzad20;
	Rzad20.push_back(new Platforma(0, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(50, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(100, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(150, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(200, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(250, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(300, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(350, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(400, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(450, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(500, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(550, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(600, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(650, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(700, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(750, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(800, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(850, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(900, 950, "cegla.png", 1));
	Rzad20.push_back(new Platforma(950, 950, "cegla.png", 1));
	platformy.push_back(Rzad20);


}

void Mapa::ustawLawe()
{
	lawy.push_back(Platforma(300, 250, "kolce.png", 1));
	lawy.push_back(Platforma(400, 250, "kolce.png", 1));
	lawy.push_back(Platforma(450, 250, "kolce.png", 1));
	lawy.push_back(Platforma(250, 500, "kolce.png", 1));
	lawy.push_back(Platforma(600, 500, "kolce.png", 1));
	lawy.push_back(Platforma(650, 500, "kolce.png", 1));
	lawy.push_back( Platforma(250, 700, "kolce.png", 1));
	
}

void Mapa::ustawSkarb()
{

}

void Mapa::ustawPrzelacznik()
{
	Platforma przelacznik(50, 150, "przycisk.png", 0);
}
	