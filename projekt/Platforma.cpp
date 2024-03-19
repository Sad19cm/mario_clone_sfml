#include "Platforma.h"
#include <iostream>

Collider Platforma::SprawdzZderzenie()
{
	return Collider(sprite);
}

Platforma::Platforma(float posx, float posy, std::string t, bool s)
{
	if (!ustawPlatforme(t)) {
		return;
	}
	pozycja = sf::Vector2f(posx, posy);
	sprite.setPosition(pozycja);
	sprite.setSize(rozmiar);
	sprite.setOrigin(rozmiar / 2.0f);
	kolizyjna = s;
}



bool Platforma::ustawPlatforme(std::string texturaNazwa)
{
	
	
	if (!tekstura.loadFromFile(texturaNazwa)) {	
		return false;
	}
	tekstura.setSmooth(true);
	sprite.setTexture(&tekstura);
	
	return true;

}
