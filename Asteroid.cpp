/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains member function definitions for the Asteroid class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include "Asteroid.h"
#include "Funcs.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace sf;

const float Asteroid::SPEED = 0.05; // static floats cannot be initialized in the class definition, so here it is

void Asteroid::updateSize() {
    _shape.setScale(0.2f * _size, 0.2f * _size);// change the scale of the asteroid _shape based on the value of _size
}
Asteroid::Asteroid(int maxX, int maxY){ // initial asteroid constructor
    _shape.setPointCount(8); // draw the convex _shape to represent the asteroid
    _shape.setPoint(0,Vector2f(0,0));
    _shape.setPoint(1,Vector2f(100,0));
    _shape.setPoint(2,Vector2f(125,35));
    _shape.setPoint(3,Vector2f(150,15));
    _shape.setPoint(4,Vector2f(140,80));
    _shape.setPoint(5,Vector2f(80,120));
    _shape.setPoint(6,Vector2f(40,150));
    _shape.setPoint(7,Vector2f(20,90));
    _shape.setFillColor(Color::Black); // make the asteroid appear similar to the rest of the objects in the game
    _shape.setOutlineColor(Color::White);
    _shape.setOutlineThickness(5);
    _shape.setRotation(rand() % 360); // randomize the rotation
    int xPos = rand() % maxX; // randomize the location
    while (xPos > 400 && xPos < 500){ xPos = rand() % maxX;}
    int yPos = rand() % maxY;
    while (xPos > 400 && yPos < 500){ yPos = rand() % maxY;}
    _shape.setPosition(xPos, yPos);
    _direction = rand() % 360; // randomize the direction to travel
    _size = 3; //set to maximum size
    updateSize();
}
Asteroid::Asteroid(float x, float y, int size, float dir){ // asteroid constructor for fracturing
    _shape.setPointCount(8);// draw the convex _shape to represent the asteroid
    _shape.setPoint(0,Vector2f(0,0));
    _shape.setPoint(1,Vector2f(100,0));
    _shape.setPoint(2,Vector2f(125,35));
    _shape.setPoint(3,Vector2f(150,15));
    _shape.setPoint(4,Vector2f(140,80));
    _shape.setPoint(5,Vector2f(80,120));
    _shape.setPoint(6,Vector2f(40,150));
    _shape.setPoint(7,Vector2f(20,90));
    _shape.setFillColor(Color::Black);// make the asteroid appear similar to the rest of the objects in the game
    _shape.setOutlineColor(Color::White);
    _shape.setOutlineThickness(5);
    _shape.setRotation(rand() % 360);// randomize the rotation
    _shape.setPosition(x, y); // set the location to the one provided
    _size = size;// set size to the one provided
    updateSize();
    _direction = rand()%360;// randomize the direction to travel
}
void Asteroid::setXPos(float x){ _shape.setPosition(x, _shape.getPosition().y);}
void Asteroid::setYPos(float y){ _shape.setPosition(_shape.getPosition().x, y);}
int Asteroid::getSize() const{ return _size;}
ConvexShape Asteroid::getShape() const{return _shape;}
float Asteroid::getXPos() const{return _shape.getPosition().x;}
float Asteroid::getYPos() const{return _shape.getPosition().y;}
void Asteroid::move(){
    float xMove = SPEED * sin(_direction * M_PI / 180); // update position according to the direction and speed of the asteroid
    float yMove = -SPEED * cos(_direction * M_PI / 180);
    _shape.setPosition(_shape.getPosition().x + xMove, _shape.getPosition().y + yMove);
}
void Asteroid::fixOrigin() {
    centerOrigin(_shape); // center the origin of the convex _shape
}
Asteroid Asteroid::fracture(){
    --_size; // shrink the asteroid and make another of the new size, giving the illusion of it splitting in two
    updateSize();
    return Asteroid(_shape.getPosition().x, _shape.getPosition().y, _size, _direction);
}