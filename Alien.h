/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains the class definition for the Alien class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#ifndef FINALPROJECT_ALIEN_H
#define FINALPROJECT_ALIEN_H
#include "Laser.h"
#include "SFML/Graphics.hpp"
using namespace sf;


class Alien {
    Sprite _sprite;
    Texture _texture;
    const float SPEED = 0.06;
    bool _startSide;
public:
    Alien(const int HEIGHT,const int WIDTH);// parameterized constructor
    Sprite getSprite()const; //sprite getter
    void move();// move the sprite along the screen at the specified speed
    void start(const int HEIGHT, const int WIDTH);// called whenever the alien object reappears
};


#endif //FINALPROJECT_ALIEN_H
