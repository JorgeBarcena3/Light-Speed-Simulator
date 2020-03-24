
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Trail.hpp"
#include "../headers/Star.hpp"
#include "../headers/Helper.hpp"

LightSpeed::Trail::Trail(sf::Color _color, toolkit::Vector2f _points, LightSpeed::Star* _star)
{
    set_color(_color);
    points = _points;
    star = _star;
    pz = star->position[2];
}

void LightSpeed::Trail::update(float delta)
{
}

void LightSpeed::Trail::render(sf::RenderWindow& window)
{

    Helper::map(star->position[0] / pz, 0, 1, 0, Star::window_size[0]);
    Helper::map(star->position[1] / pz, 0, 1, 0, Star::window_size[1]);

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(
            Helper::map(star->position[0] / pz, 0, 1, Star::window_size[0] / 2, Star::window_size[0]),
            Helper::map(star->position[1] / pz, 0, 1, Star::window_size[1] / 2, Star::window_size[1])),
            sf::Color::White
        ),
        sf::Vertex(sf::Vector2f(star->simulationCoord.sx, star->simulationCoord.sy), star->polygonColor)
    };

    pz = star->position[2];

    window.draw(line, 2, sf::Lines);
}
