/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains definition of the Asteroid class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#ifndef FINALPROJECT_ASTEROID_H
#define FINALPROJECT_ASTEROID_H
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;
using namespace sf;


class Asteroid {
    ConvexShape _shape;
    int _size;
    static const float SPEED;
    float _direction;
    void updateSize(); // private helper to re-scale the _shape
public:
    Asteroid(int maxX, int maxY); // constructor for new asteroids
    Asteroid(float x, float y, int size,float dir); // constructor for fractured asteroids
    void setXPos(float x); // x position setter
    void setYPos(float y);// y position setter
    int getSize() const; //size getter
    ConvexShape getShape() const; // drawable _shape getter
    float getXPos() const; // x position getter
    float getYPos() const; // y position getter
    void move(); // updates position based on speed and direction
    void fixOrigin(); // centers origin. Used publicly due to memory reassignment issues with vectors.
    Asteroid fracture(); // decreases size and creates a new asteroid of the new size
};


#endif //FINALPROJECT_ASTEROID_H
