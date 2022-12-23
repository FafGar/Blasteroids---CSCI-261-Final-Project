/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains definition of the Asteroid class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#ifndef FINALPROJECT_LASER_H
#define FINALPROJECT_LASER_H

#include "SFML/Graphics.hpp"
using namespace sf;


class Laser {
    RectangleShape _shape;
    float _angle;
    static const float _speed;
public:
    Laser(float xPos, float yPos, float angle); // parameterized constructor
    RectangleShape getShape() const;// drawable shape getter
    float getXPos() const; // x position getter
    float getYPos() const; // y position getter
    void move(); // updates position based on _angle and _speed
    void fixOrigin(); // centers the origin. Used publicly to counteract memory reference issues caused by vectors
};


#endif //FINALPROJECT_LASER_H
