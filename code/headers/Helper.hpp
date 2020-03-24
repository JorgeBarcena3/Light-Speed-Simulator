/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on March of 2020                                  *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MATHHELPER_HEADER
#define MATHHELPER_HEADER

#include "Vector.hpp"
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>

namespace LightSpeed
{

    class Helper
    {

    public:

        static float map(float n, float start1, float stop1, float start2, float stop2 )
        {
            return (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
            
        }

        static float magnitude(toolkit::Vector2f* vec)
        {
            return Helper::sqrt(powf((*vec)[0], 2) + powf((*vec)[1], 2));
        }

        static void normalize(toolkit::Vector2f* vec)
        {
            float l = 1 / magnitude(vec);

            (*vec)[0] *= l;
            (*vec)[1] *= l;
        }

        static sf::Color getColorInScreenRange(int r, int g, int b, int width, int height)
        {

            float maxValue = 1 / (float)(width > height ? width : height);

            return sf::Color(
                clamp(r * 255 * maxValue, 0 , 255),
                clamp(g * 255 * maxValue, 0, 255),
                clamp(b * 255 * maxValue, 0, 255)
            );
        }

        static sf::Color hsv(int hue, float sat, float val)
        {
            hue %= 360;
            while (hue < 0) hue += 360;

            if (sat < 0.f) sat = 0.f;
            if (sat > 1.f) sat = 1.f;

            if (val < 0.f) val = 0.f;
            if (val > 1.f) val = 1.f;

            int h = hue / 60;
            float f = float(hue) / 60 - h;
            float p = val * (1.f - sat);
            float q = val * (1.f - sat * f);
            float t = val * (1.f - sat * (1 - f));

            switch (h)
            {
            default:
            case 0:
            case 6: return sf::Color((int)(val * 255), (int)(t * 255), (int)(p * 255));
            case 1: return sf::Color((int)(q * 255), (int)(val * 255), (int)(p * 255));
            case 2: return sf::Color((int)(p * 255), (int)(val * 255), (int)(t * 255));
            case 3: return sf::Color((int)(p * 255), (int)(q * 255), (int)(val * 255));
            case 4: return sf::Color((int)(t * 255), (int)(p * 255), (int)(val * 255));
            case 5: return sf::Color((int)(val * 255), (int)(p * 255  ), (int)(q * 255  ) );
            }
        }

        static int clamp(float v, float min, float max)
        {
            return (int) ( v > max ? max : v < min ? min : v );
        }

        static float sqrt(float x) {
            int i;
            float s;
            s = ((x / 2) + x / (x / 2)) / 2; /*first guess*/
            for (i = 1; i <= 4; i++) { /*average of guesses*/
                s = (s + x / s) / 2;
            }
            return s;
        }

        static float distance(toolkit::Vector2f A, toolkit::Vector2f B)
        {
            toolkit::Vector2f direction(
                {
                    B[0] - A[0],
                    B[1] - A[1],
                
                });


            return magnitude(&direction);
        }

        static toolkit::Vector2f getDirection(toolkit::Vector2f& A, toolkit::Vector2f& B)
        {
            toolkit::Vector2f direction(
                {
                    B[0] - A[0],
                    B[1] - A[1],

                });


            return direction;
        }
        
        static float sqrtMagnitude(toolkit::Vector2f A)
        {
           
            return sqrtf( magnitude(&A) );
        }
        

        static float generateRandom(double M, double N)
        {
            return (float)(M + (rand() / (RAND_MAX / (N - M))));
        }
        
        static void setMag(toolkit::Vector2f& vec, float newMag)
        {
            float mag = magnitude(&vec);

            vec[0] = vec[0] * newMag / mag;
            vec[1] = vec[1] * newMag / mag;
        } 
        
        static void limit(toolkit::Vector2f& vec, float max)
        {
            float mag = magnitude(&vec);

            if (mag > max)
            {
                setMag(vec, max);
            }

        }
        


    };

}

#endif
