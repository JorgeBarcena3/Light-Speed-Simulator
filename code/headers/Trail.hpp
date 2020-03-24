
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef TRAIL_HEADER
#define TRAIL_HEADER

#include "Star.hpp"
#include <SFML/Graphics.hpp>

using namespace toolkit;
using namespace sf;

namespace LightSpeed
{


    /*
    * Maneja un objeto del tipo star
    */
    class Trail : public Model2D
    {
    public:

        /*
        * Estrella a la que pertenece
        */
        LightSpeed::Star * star;

        /*
        * Color de la estela
        */
        sf::Color          color;

        /*
        * Puntos de la estela
        */
        toolkit::Vector2f  points;

       

        /*
        * Punto original de la z
        */
        float pz;
        
        /*
        * Constructor
        */
        Trail(sf::Color _color, toolkit::Vector2f _points, LightSpeed::Star * _star);

        /*
        * Update de la estela
        */
        virtual void update(float delta) override;

        /*
        * Renderizacion de la estela
        */
        virtual void render(sf::RenderWindow& window) override;
    };


}

#endif