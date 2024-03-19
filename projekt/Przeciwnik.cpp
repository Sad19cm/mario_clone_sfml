#include "Przeciwnik.h"

Przeciwnik::Przeciwnik(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia,sf::Vector2f pozycja, float szybkosc):
	animacja(tekstura,licznikObrazkow,czasPrzelaczenia), animacjasmierc(tekstura, licznikObrazkow, czasPrzelaczenia)
{
	rzad = 0;
	wPrawo = true;
	jestZywy = true;
	cialo.setSize(sf::Vector2f(50, 50));
	cialo.setPosition(pozycja);
	this->pozycja = pozycja;
	this->szybkosc = szybkosc;
	cialo.setOrigin(cialo.getSize() / 2.0f);
	cialo.setTexture(tekstura);
	
}

void Przeciwnik::aktualnie(float dczas)
{
	
	
	if (jestZywy) 
	{
		predkosc.x = 0.0f;

		if (wPrawo == true) {
			predkosc.x += szybkosc;
		}
		else {
			predkosc.x -= szybkosc;
		}
		if (cialo.getPosition().x > pozycja.x + 50) {
			wPrawo = false;
		}
		else if (cialo.getPosition().x <= pozycja.x - 100) {

			wPrawo = true;
		}
		animacja.update(rzad, dczas, wPrawo);
		cialo.setTextureRect(animacja.xyRect);
		cialo.move(predkosc * dczas);
	}
	if(!jestZywy)
	{
		
		 {
			rzad = 1;
			animacjasmierc.smiercKripera(rzad, dczas, wPrawo, true);
			cialo.setTextureRect(animacjasmierc.xyRect);

		}
		


	}
}

void Przeciwnik::draw(sf::RenderWindow& window)
{
	window.draw(cialo);
}

Collider Przeciwnik::SprawdzZderzenie()
{
	return Collider(cialo);
}

void Przeciwnik::zabij()
{
	jestZywy = false;
	
}
