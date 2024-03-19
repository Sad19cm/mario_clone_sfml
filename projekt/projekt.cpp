#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Platforma.h"
#include "Przeciwnik.h"
#include "Gracz.h"
#include <vector>
#include <iostream>
#include "Mapa.h"


static const float VIEW_SIZE = 400;

int main()
{ 
   sf::RenderWindow window(sf::VideoMode(800, 600), "Minecraftrio");
   sf::View view(sf::Vector2f(200, 800), sf::Vector2f(VIEW_SIZE, VIEW_SIZE));
   sf::RectangleShape gameOver;
   gameOver.setSize(sf::Vector2f(15000, 15000));
   gameOver.setOrigin(gameOver.getSize() / 2.0f);
   gameOver.setFillColor(sf::Color(128, 128, 128, 230));

    sf::Texture teksturaGracz,teksturaSerce, teksturaPusta;
    teksturaGracz.loadFromFile("graczt.png");
    teksturaSerce.loadFromFile("sercat.png");
    teksturaPusta.loadFromFile("pusta.png");

    Mapa mapa;
    Gracz mario(&teksturaGracz, sf::Vector2u(4, 2), 0.2f, 100.0f,110.0f);
    

    float dczas = 0;
    sf::Clock zegar;

    sf::Music muzykaTlo, muzykaKoniec, muzykaVi;
    muzykaTlo.openFromFile("audio/mariotheme.ogg");
    muzykaTlo.setVolume(30);
    muzykaTlo.setLoop(true);
    muzykaTlo.play();

    muzykaVi.openFromFile("audio/victory.ogg");
    muzykaVi.setVolume(90);
    muzykaVi.setLoop(true);

    muzykaKoniec.openFromFile("audio/gameover.ogg");
    muzykaKoniec.setVolume(50);
    bool koniec=false;
 
        while (window.isOpen())
        {
            dczas = zegar.restart().asSeconds();

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            mario.aktualnie(dczas);

            if (mario.getHp() == 0&& koniec==false) {
                muzykaTlo.stop();
                koniec = true;
                muzykaKoniec.play();
               
            }

            //couty 
            //std::cout << mario.getHp() << std::endl;
            std::cout << mario.czasOpoznienia << std::endl;

            sf::Vector2f pozycja = mario.GetPositionWidok();


            for (int i = 0; i < mapa.przeciwnicy.size(); i++) {
                mapa.przeciwnicy[i].aktualnie(dczas);
            }



            sf::Vector2f kierunek;

            //sprawdzanie kolizji z lawa
            for (int i = 0; i < mapa.lawy.size(); i++)
            {
                if (mapa.lawy[i].SprawdzZderzenie().sprawdzKolizje(mario.SprawdzZderzenie(), kierunek, 1.0f))
                {
                    mario.kontaktZLawa(kierunek);
                }
            }

            //sprawdzanie kolizji z platformami
            for (int i = 0; i < mapa.szerokoscSiatki; i++) {
                for (int j = 0; j < mapa.szerokoscSiatki; j++) {
                    if (mapa.platformy[i][j]->kolizyjna) {
                        if (mapa.platformy[i][j]->SprawdzZderzenie().sprawdzKolizje(mario.SprawdzZderzenie(), kierunek, 1.0f)) {
                            mario.naZiemi(kierunek);
                        }
                    }
                }
            }
            //sprawdzanie kolizji z kriperami
            for (int i = 0; i < mapa.przeciwnicy.size(); i++)
            {
                if (mapa.przeciwnicy[i].SprawdzZderzenie().sprawdzKolizje(mario.SprawdzZderzenie(), kierunek, 1.0f))
                {
                    mario.kontaktZPrzeciwnikiem(mapa.przeciwnicy[i], kierunek);
                }
            }
            //odblokowanie kraty
            if (mapa.odblokowany == false) {
                if (mapa.platformy[3][1]->SprawdzZderzenie().sprawdzKolizje(mario.SprawdzZderzenie(), kierunek, 1.0f)) {
                    mapa.platformy[3][1] = new Platforma(50, 150, "przyciskOd.png", 0);
                    mapa.platformy[1][17] = new Platforma(850, 50, "krataOd.png", 0);

                    mapa.odblokowany = true;
                }
            }
            //otworzenie skrzyni
            if (mapa.odblokowany == true&&koniec==false) {
                if (mapa.platformy[1][18]->SprawdzZderzenie().sprawdzKolizje(mario.SprawdzZderzenie(), kierunek, 1.0f)) {
                    mapa.platformy[1][18] = new Platforma(900, 50, "skrzynkaOd.png", 0);
                    muzykaTlo.stop();
                    muzykaVi.play();
                    koniec = true;
                }
            }


            view.setCenter(pozycja);

            window.clear();
            window.setView(view);

            //malowanie mapy
            for (int i = 0; i < mapa.szerokoscSiatki; i++) {
                for (int j = 0; j < mapa.szerokoscSiatki; j++) {
                    window.draw(mapa.platformy[i][j]->sprite);
                }

            }
            //malowanie gracza
            mario.draw(window);
            //malowanie kriperow
            for (int i = 0; i < mapa.przeciwnicy.size(); i++) {
                mapa.przeciwnicy[i].draw(window);
            }

            //malowanie gameovera
            if (!mario.getHp()) {
                window.draw(gameOver);
            }
            //malowanie hp
            mario.rysujHp(&teksturaSerce, pozycja, window);


            window.display();
        }
        
    
    return 0;
}