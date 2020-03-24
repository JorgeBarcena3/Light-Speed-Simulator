
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MODEL2D_HEADER
#define MODEL2D_HEADER

#include <vector>
#include <SFML\Graphics\Color.hpp>
#include <SFML/Graphics.hpp>
#include <Vector.hpp>


using namespace toolkit;
namespace sf { class RenderWindow; }

namespace LightSpeed
{


    class Model2D
    {

       
    public:

        typedef toolkit::Vector3f Vector3f;

        // Atributos de transformación:

        Vector3f	  position;
        float		  angle;
        float		  scale;

        // Atributos de animación:

        sf::Color     polygonColor;



    public:

        virtual void update(float delta) = 0;

        virtual void render(sf::RenderWindow& window) = 0;

        void set_position(float x, float y, float z)
        {
            position = Vector3f({ x, y, z });
        }

        void set_angle(float new_angle)
        {
            angle = new_angle;
        }

        void set_scale(float new_scale)
        {
            scale = new_scale;
        }

        void set_color(sf::Color new_color)
        {
            polygonColor = new_color;
        }  

    };

}

#endif
