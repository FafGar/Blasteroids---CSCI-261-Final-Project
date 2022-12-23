/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains the member function definitions for the Player class
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include "Player.h"
#include "Laser.h"
#include "Funcs.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace sf;

Player::Player(int wWidth, int wHeight){
    if (!_texture.loadFromFile("playerShip.png")){ cout << "Cannot load _texture";} // load the player _texture and size it appropriately
    _sprite.setTexture(_texture);
    _sprite.setScale(0.08f, 0.1f);
    centerOrigin(_sprite);
    _sprite.setPosition(wWidth / 2, wHeight / 2);
    _xVelocity = 0; // set all other data members to zero
    _yVelocity = 0;
    _lives = 0;
    _score = 0;
}
void Player::gainLives(int lives){
    _lives += lives; // gain the given number of lives
}
void Player::setXPos(float x){ _sprite.setPosition(x, _sprite.getPosition().y);}
void Player::setYPos(float y){ _sprite.setPosition(_sprite.getPosition().x, y);}
void Player::die(int wWidth, int wHeight){
    _sprite.setPosition(wWidth / 2, wHeight / 2); // reset the player to the middle of the screen, stop them, and take away a life
    --_lives;
    _xVelocity = 0;
    _yVelocity = 0;
}
void Player::gainPoints(int points){
    _score += points;// gain the given number of points
}
void Player::resetScore(){ _score = 0;}
float Player::getXV() const{return _xVelocity;}
float Player::getYV() const{return _yVelocity;}
int Player::getLives() const{return _lives;}
float Player::getXPos() const{return _sprite.getPosition().x;}
float Player::getYPos() const{return _sprite.getPosition().y;}
int Player::getScore() const{return _score;}
Sprite Player::getSprite() const{ return _sprite;}
void Player::thrust(){
    _xVelocity += sin(_sprite.getRotation() * M_PI / 180) * 0.0001f; // gain the appropriate amount of velocity in both directions based on the angle of the ship
    _yVelocity -= cos(_sprite.getRotation() * M_PI / 180) * 0.0001f;
}

void Player::slowDown(){
    const float NEGACCEL = 0.00003;
    const float SLOWBOUND = 0.00005;

    if (_xVelocity > SLOWBOUND) { // slowly reduce velocity in both directions to zero
        _xVelocity -= NEGACCEL;
    } else if (_xVelocity < -SLOWBOUND){
        _xVelocity += NEGACCEL;
    } else {
        _xVelocity = 0;
    }
    if (_yVelocity > SLOWBOUND) {
        _yVelocity -= NEGACCEL;
    } else if (_yVelocity < -SLOWBOUND){
        _yVelocity += NEGACCEL;
    } else {
        _yVelocity = 0;
    }
}
void Player::move(){
    // update the player's position based on their current velocities
    _sprite.setPosition(_sprite.getPosition().x + _xVelocity, _sprite.getPosition().y + _yVelocity);
}
void Player::rotateR(){
    _sprite.rotate(.1f); //rotate the sprite to the right
}
void Player::rotateL(){
    _sprite.rotate(-.1f);//rotate the sprite to the left
}
void Player::hyperspace(const int& HEIGHT, const int& WIDTH){
    setXPos(rand()%WIDTH); // randomly place the player on the screen
    setYPos(rand()%HEIGHT);
}
Laser Player::shoot(){
    //create a laser object travelling in the direction the ship is pointing.
    return Laser(_sprite.getPosition().x, _sprite.getPosition().y, _sprite.getRotation());
}