
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef START_HEADER
#define START_HEADER

#include "Model2D.hpp"
#include <SFML/Graphics.hpp>

using namespace toolkit;
using namespace sf;

namespace LightSpeed
{
    class Trail;

    struct Simulation2DCoord
    {
        float sx;
        float sy;
        float sz;

    };

    /*
    * Maneja un objeto del tipo star
    */
    class Star : public Model2D
    {
                

    public:

        static std::vector<Star*>    instances;           //Instancias de los star

        static sf::RenderWindow *    window;              // Instancia de la ventana de render

        static toolkit::Vector2f     window_size; // Tamaño de la pantalla


    public:
        
        Trail          *              trail;          // Estela de la estrella

        float                         speed;          // Velocidad

        /*
        * Coordenadas para la simulacion
        */
        Simulation2DCoord simulationCoord;

    public:

        /*
        * Contructor que recibe los parametros de como va a ser la pelota en cuestion
        */
        Star(
            float               _speed,
            Vector3f            _startPosition,
            sf::Color           _color
        );
      
        /*
        * Busca la siguiente posicion de la pelota
        */
        virtual void update(float delta) override;


        /*
        * Renderiz la estrella
        */
        virtual void render(RenderWindow& window) override;

        /*
        * Llama a la funcion update() de todos las pelotas almacenados
        */
        static void Update(float delta)
        {
            for (Star* star : instances)
            {
                star->update(delta);
            }
        };
        
        /*
        * Llama a la funcion update() de todos las pelotas almacenados
        */
        static void Render(RenderWindow& window)
        {
            for (Star* star : instances)
            {
                star->render(window);
            }
        };


    };

}

#endif