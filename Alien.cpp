/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains all member function definitions for the Alien class.
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#include <iostream>
#include "Alien.h"
#include "Funcs.h"
using namespace sf;
using namespace std;


Alien::Alien(const int HEIGHT, const int WIDTH){
    if (!_texture.loadFromFile("alien1.png")){ cout << "Cannot load _texture";} // load alien _texture and size it correctly
    _sprite.setTexture(_texture);
    _sprite.setScale(0.05f, 0.05f);
    centerOrigin(_sprite); // center the origin of the sprite
   _startSide = false; // randomly select a side to start on and start there
    if(rand()%2){_startSide = true;}
    if(_startSide){
        _sprite.setPosition(-10.f, rand()%(HEIGHT-30)+30);
    }else{
        _sprite.setPosition(WIDTH+10.f, rand()%(HEIGHT-30)+30);
    }
}
Sprite Alien::getSprite()const{return _sprite;}

void Alien::move(){ // move the sprite along the screen at the specified speed
    if(_startSide){
        _sprite.setPosition(_sprite.getPosition().x+SPEED, _sprite.getPosition().y);
    }else{
        _sprite.setPosition(_sprite.getPosition().x-SPEED, _sprite.getPosition().y);
    }
}
void Alien::start(const int HEIGHT, const int WIDTH){ // called whenever the alien object reappears
    _startSide = false; // randomly choose a starting side and start there
    if(rand()%2){_startSide = true;}
    if(_startSide){
        _sprite.setPosition(-10.f, rand()%(HEIGHT-30)+30);
    }else{
        _sprite.setPosition(WIDTH+10.f, rand()%(HEIGHT-30)+30);
    }
}