#include "Animacja.h"

Animacja::Animacja(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia)
{
	this->licznikObrazkow = licznikObrazkow;
	this->czasPrzelaczenia = czasPrzelaczenia;
	calkowityCzas = 0;
	obecnyObrazek.x = 0;

	xyRect.width = tekstura->getSize().x / float(licznikObrazkow.x);
	xyRect.height = tekstura->getSize().y / float(licznikObrazkow.y);
}

void Animacja::update(int rzad, float dczas, bool wPrawo)
{
	obecnyObrazek.y = rzad;
	calkowityCzas += dczas;
	if (calkowityCzas >= czasPrzelaczenia) {
		calkowityCzas -= czasPrzelaczenia;
		obecnyObrazek.x++;
		if (obecnyObrazek.x >= licznikObrazkow.x) {
			obecnyObrazek.x = 0;
		}
	}
	
	xyRect.top = obecnyObrazek.y * xyRect.height;
	if (wPrawo) {
		xyRect.left = obecnyObrazek.x * xyRect.width;
		xyRect.width = abs(xyRect.width);

	}
	else {
		xyRect.left=(obecnyObrazek.x + 1)*abs(xyRect.width);
		xyRect.width = -abs(xyRect.width);
	}
}
void Animacja::smiercKripera(int rzad, float dczas, bool wPrawo, bool powrot)
{
	obecnyObrazek.y = rzad;
	calkowityCzas += dczas;
	if (calkowityCzas >= czasPrzelaczenia) {
		calkowityCzas -= czasPrzelaczenia;
		obecnyObrazek.x++;
		if (obecnyObrazek.x >= licznikObrazkow.x) {
			obecnyObrazek.x = 3;
		}
	}
	

	xyRect.top = obecnyObrazek.y * xyRect.height;
	if (wPrawo) {
		xyRect.left = obecnyObrazek.x * xyRect.width;
		xyRect.width = abs(xyRect.width);

	}
	else {
		xyRect.left = (obecnyObrazek.x + 1) * abs(xyRect.width);
		xyRect.width = -abs(xyRect.width);
	}
}

