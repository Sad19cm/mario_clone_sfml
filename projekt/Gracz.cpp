#include "Gracz.h"
#include <iostream>

Gracz::Gracz(sf::Texture* tekstura, sf::Vector2u licznikObrazkow, float czasPrzelaczenia, float szybkosc,float wysokoscSkoku):
	animacja(tekstura, licznikObrazkow, czasPrzelaczenia)
{
	this->szybkosc = szybkosc;
    this->wysokoscSkoku = wysokoscSkoku;
    rzad = 0;
    wPrawo = true;
    hp = 3;
    czasOpoznienia = 0;
    ;

    cialo.setSize(sf::Vector2f(40, 40));
    cialo.setOrigin(cialo.getSize() / 2.0f);
    cialo.setPosition(80, 920);
    cialo.setTexture(tekstura);

    hitbox.setSize(sf::Vector2f(20, 30));
    hitbox.setOrigin(hitbox.getSize() / 2.0f);
    hitbox.setPosition(90, 920);
    hitbox.setFillColor(sf::Color(128,128,128,230));

    hit.openFromFile("audio/hit.ogg");
    hit.setVolume(70);
    smierc.openFromFile("audio/smiercKripera.ogg");
    smierc.setVolume(50);
    skok.openFromFile("audio/jump.ogg");
    skok.setVolume(50);
   // skok.setPlayingOffset(sf::seconds(0.0f));

}


void Gracz::aktualnie(float dczas)
{
    predkosc.x = 0.0f;

    if (hp > 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            predkosc.x -= szybkosc;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            predkosc.x += szybkosc;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && mozeSkoczyc) {
            mozeSkoczyc = false;
            predkosc.y = -sqrt(2.0f * 600.0f * wysokoscSkoku);
            skok.play();
            skok.setPlayingOffset(sf::seconds(0.0f));
        }
        predkosc.y += 600.0f * dczas;

        if (predkosc.x == 0) {
            rzad = 0;
        }
        else {
            rzad = 1;
            if (predkosc.x > 0) {
                wPrawo = true;
            }
            else {
                wPrawo = false;
            }
        }
    }
    
    

    animacja.update(rzad, dczas, wPrawo);
    cialo.setTextureRect(animacja.xyRect);

    hitbox.move(predkosc*dczas);
    cialo.setPosition(hitbox.getPosition().x, hitbox.getPosition().y-5 );
    czasOpoznienia += dczas;
}

void Gracz::draw(sf::RenderWindow &window)
{
     window.draw(cialo);
  //  window.draw(hitbox);
}

sf::Vector2f Gracz::GetPositionWidok()
{
    //rogi
    if (cialo.getPosition().x < 175 && cialo.getPosition().y>775) {
        return sf::Vector2f (175, 775);
    }
    if (cialo.getPosition().x > 775 && cialo.getPosition().y> 775) {
        return sf::Vector2f(775, 775);
    }
    if (cialo.getPosition().x < 175 && cialo.getPosition().y< 175) {
        return sf::Vector2f(175, 175);
    }
    if (cialo.getPosition().x > 775 && cialo.getPosition().y< 175) {
        return sf::Vector2f(775, 175);
    }
    //kamera nie spada
    //dol
    if (cialo.getPosition().x > 175 && cialo.getPosition().x < 775 && cialo.getPosition().y>775) {
        return sf::Vector2f(cialo.getPosition().x, 775);
    }//lewo
    if (cialo.getPosition().y > 175 && cialo.getPosition().y < 775 && cialo.getPosition().x < 175) {
        return sf::Vector2f(175, cialo.getPosition().y);
    }//gora
    if (cialo.getPosition().x > 175 && cialo.getPosition().x < 775 && cialo.getPosition().y < 175) {
        return sf::Vector2f(cialo.getPosition().x, 175);
    }//prawo
    if (cialo.getPosition().x > 775 && cialo.getPosition().y < 775 && cialo.getPosition().y>175) {
        return sf::Vector2f(775, cialo.getPosition().y);
    }

    
    else {
        return cialo.getPosition();
    }
}

Collider Gracz::SprawdzZderzenie()
{
    return Collider(hitbox);
}


void Gracz::naZiemi(sf::Vector2f kierunek)
{
    if (kierunek.x < 0.0f) {
        predkosc.x = 0.0f;//lewo
    }
    else if (kierunek.x > 0.0f) {//prawo
        predkosc.x = 0.0f;
    }
    if (kierunek.y < 0.0f) {//dol
        predkosc.y = 0.0f;
        mozeSkoczyc = true;
    }
    else if (kierunek.y < 0.0f) {
        predkosc.y = 0.0f;
    }
}

void Gracz::rysujHp(sf::Texture* tekstura, sf::Vector2f& pozycja, sf::RenderWindow& window)
{
    if (hp == 3) {
        hpBar.setTexture(tekstura);
        hpBar.setPosition(sf::Vector2f(pozycja.x - 200, pozycja.y - 200));
        hpBar.setSize(sf::Vector2f(150, 150));
        hpBar.setTextureRect(sf::IntRect(0, 0, 150, 150));
    }
    if (hp == 2) {
        hpBar.setTexture(tekstura);
        hpBar.setPosition(sf::Vector2f(pozycja.x - 200, pozycja.y - 200));
        hpBar.setSize(sf::Vector2f(100, 100));
        hpBar.setTextureRect(sf::IntRect(0, 0, 100, 100));
    }
    if (hp == 1) {
        hpBar.setTexture(tekstura);
        hpBar.setPosition(sf::Vector2f(pozycja.x - 200, pozycja.y - 200));
        hpBar.setSize(sf::Vector2f(50, 50));
        hpBar.setTextureRect(sf::IntRect(0, 0, 50, 50));
    }
    if (hp <= 0) {

        hpBar.setTexture(tekstura);
        hpBar.setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y + 50));
        hpBar.setOrigin(hpBar.getSize() / 2.0f);
        hpBar.setSize(sf::Vector2f(150, 150));
        hpBar.setTextureRect(sf::IntRect(150, 0, 150, 150));
    }




    window.draw(hpBar);
}

void Gracz::kontaktZPrzeciwnikiem(Przeciwnik& przeciwnik, sf::Vector2f kierunek )
{

    if (kierunek.x < 0.0f&& przeciwnik.jestZywy && czasOpoznienia > 0.5f) {//lewo
        if (hp > 0) {
            hp--;
            hit.play();
            hit.setPlayingOffset(sf::seconds(0.0f));

        }
        czasOpoznienia = 0.0f;
    }
    if (kierunek.x > 0.0f && przeciwnik.jestZywy && czasOpoznienia > 0.5f) {//prawo
        if (hp > 0) {
            hp--;
            hit.play();
            hit.setPlayingOffset(sf::seconds(0.0f));

        }
        czasOpoznienia = 0.0f;
    }

    if (kierunek.y < 0.0f) {//gora
        
        mozeSkoczyc = true;
        if (przeciwnik.jestZywy) {
            smierc.play();
            smierc.setPlayingOffset(sf::seconds(0.0f));
        }
        przeciwnik.zabij();
        

    }

}



int Gracz::getHp()
{
    return hp;
}

void Gracz::kontaktZLawa(sf::Vector2f kierunek)
{
    if (kierunek.y < 0.0f && czasOpoznienia > 0.5f){//gora
        if (hp > 0) {
            hp--;
            hit.play();
            hit.setPlayingOffset(sf::seconds(0.0f));
        }
        czasOpoznienia = 0.0f;
        mozeSkoczyc = true;
    }
    if (kierunek.x < 0.0f  && czasOpoznienia > 0.5f) {//lewo
        if (hp > 0) {
            hp--;
            hit.play();
            hit.setPlayingOffset(sf::seconds(0.0f));
        }
        czasOpoznienia = 0.0f;
    }
    if (kierunek.x > 0.0f  && czasOpoznienia > 0.5f) {//prawo
        if (hp > 0) {
            hp--;
            hit.play();
            hit.setPlayingOffset(sf::seconds(0.0f));
        }
        czasOpoznienia = 0.0f;
    }
}



