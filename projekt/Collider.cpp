#include "Collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& cialo) :
    cialo(cialo)
{

}

bool Collider::sprawdzKolizje(Collider inny, sf::Vector2f& kierunek, float przesun)
{
    sf::Vector2f pozycjaInnego = inny.GetPosition();
    sf::Vector2f polowaRozmiaruInnego = inny.GetPolowaRozmiaru();
    sf::Vector2f pozycjaTego = GetPosition();
    sf::Vector2f polowaRozmiaruTego = GetPolowaRozmiaru();

    float deltaX = pozycjaInnego.x - pozycjaTego.x;
    float deltaY = pozycjaInnego.y - pozycjaTego.y;

    float przeciecieX = abs(deltaX) - (polowaRozmiaruInnego.x + polowaRozmiaruTego.x);
    float przeciecieY = abs(deltaY) - (polowaRozmiaruInnego.y + polowaRozmiaruTego.y);

    if (przeciecieX < 0 && przeciecieY < 0) 
    {
        
        przesun = std::min(std::max(przesun, 0.0f), 1.0f);

        if (przeciecieX > przeciecieY) 
        {
            if (deltaX > 0) 
            {
                ruch(przeciecieX * (1 - przesun), 0);
                inny.ruch(-przeciecieX * przesun, 0);

                kierunek.x = 1.0f;
                kierunek.y = 0.0f;
            }
            else
            {
                ruch(-przeciecieX * (1 - przesun), 0);
                inny.ruch(przeciecieX * przesun, 0);

                kierunek.x = -1.0f;
                kierunek.y = 0.0f;

            }

        }
        else
        {
            if (deltaY > 0)
            {
                ruch(0,przeciecieY * (1 - przesun));
                inny.ruch(0,-przeciecieY * przesun);

                kierunek.x = 0.0f;
                kierunek.y = 1.0f;
            }
            else
            {
                ruch(0,-przeciecieY * (1 - przesun));
                inny.ruch(0,przeciecieY * przesun);

                kierunek.x = 0.0f;
                kierunek.y = -1.0f;

            }
        }
        

        return true;
    }

    return false;
}

sf::Vector2f Collider::GetPosition()
{
    return cialo.getPosition();
}

sf::Vector2f Collider::GetPolowaRozmiaru()
{
    return cialo.getSize()/2.0f;
}

void Collider::ruch(float dx, float dy)
{
    cialo.move(dx, dy);
}
