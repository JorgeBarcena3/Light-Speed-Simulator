
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Star.hpp"
#include "../headers/Helper.hpp"

#define PI   3.1415
#define PI2  2 * PI
#define RAD  PI / 180

using namespace LightSpeed;
using namespace sf;

//Inicializacion de la lista de balls
std::vector<Star*> Star::instances = {};

sf::RenderWindow* Star::window = nullptr;

toolkit::Vector2f Star::window_size = toolkit::Vector2f({ 0,0 });

/*
* Divide la esfera en vertices de igual distancia
*/
LightSpeed::Star::Star(
    float               _speed,
    Vector3f            _startPosition,
    sf::Color           _color
)
{

    set_position(_startPosition[0], _startPosition[1], _startPosition[2]);  // Posicionamos la pelota en esa posicion
    speed = _speed;
    set_color(_color);

    Star::instances.push_back(this);                                        //Añadimos el objeto a la lista de entidades


}

/*
* Busca la siguiente posicion de la pelota
*/
void LightSpeed::Star::update(float delta)
{

    position[2] -= speed;

    if (position[2] < 1)
    {
        set_position(
            Helper::generateRandom(-window_size[0], window_size[0]),
            Helper::generateRandom(-window_size[0], window_size[0]),
            window_size[0]);

    }

};

void LightSpeed::Star::render(RenderWindow& window)
{
    sf::CircleShape circle;   

    float sx = Helper::map(position[0] / position[2], 0, 1,  window_size[0] / 2, window_size[0]);
    float sy = Helper::map(position[1] / position[2], 0, 1,  window_size[1] / 2, window_size[1]);
    float sz = position[2];

    auto mouse = sf::Mouse::getPosition(window);
    speed = Helper::map(mouse.x < 0 ? 0 : (float)mouse.x, 0, window_size[0], 0, 20);

    //Radio en funcion de la Z
    float r = Helper::map(position[2], 0, window_size[0], 16, 0);
    circle.setRadius(r);
    circle.setOrigin(r, r);
    circle.setFillColor(polygonColor);

    circle.setPosition(sx, sy);

    window.draw(circle);
}



