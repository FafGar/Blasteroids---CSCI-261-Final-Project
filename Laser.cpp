/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains member function definitions for the Laser class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include "Laser.h"
#include "SFML/Graphics.hpp"
#include "Funcs.h"
#include <cmath>


const float Laser::_speed = 0.5; // cannot initialize static floats in the class definition, so it's here instead

Laser::Laser(float xPos, float yPos, float angle){
    _shape.setSize(Vector2f(2, 10)); //create rectangle to represent laser
    _shape.setRotation(angle); // set angle to that provided
    _angle = angle;
    _shape.setPosition(xPos, yPos); // set position to the one provided
}
RectangleShape Laser::getShape() const{ return _shape;}
float Laser::getXPos() const{return _shape.getPosition().x;}
float Laser::getYPos() const{return _shape.getPosition().y;}
void Laser::move(){
    float xMove = _speed * sin(_angle * M_PI / 180); // update position based on direction and speed
    float yMove = -_speed * cos(_angle * M_PI / 180);
    _shape.setPosition(_shape.getPosition().x + xMove, _shape.getPosition().y + yMove);
}
void Laser::fixOrigin(){
    centerOrigin(_shape); // center the origin of the _shape.
}