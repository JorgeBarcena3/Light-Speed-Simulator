
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Star.hpp"
#include "../headers/Helper.hpp"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <SFML/Window.hpp>

#define SIZE  700

using namespace sf;
using namespace LightSpeed;


int main()
{
    RenderWindow window(VideoMode(SIZE, SIZE), "LightSpeed - Jorge Barcena", sf::Style::Default, ContextSettings(32));
    
    Star::window = &window;
    Star::window_size = toolkit::Vector2f({ SIZE, SIZE });

    window.setVerticalSyncEnabled(true);

    bool running = true;

    /* initialize random seed: */
    srand(time(NULL));

    std::vector< Star * > agents(SIZE);

    for (size_t i = 0; i < agents.size(); i++)
    {
        agents[i] = new Star
            (
                Helper::generateRandom(1, 3),
                toolkit::Vector3f({ Helper::generateRandom(-SIZE, SIZE), Helper::generateRandom(-SIZE, SIZE), Helper::generateRandom(0, SIZE) }),
                sf::Color(255, 255, 196)
            );   

    }

    do
    {
        // Process window events:

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
            
        }

        Star::Update(0);

        // Render:
         window.clear();

        Star::Render(window);
       
        window.display();

    } while (running);


    return EXIT_SUCCESS;
}
