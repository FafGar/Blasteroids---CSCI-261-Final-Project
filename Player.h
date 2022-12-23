/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains player class definition
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Laser.h"

using namespace sf;


class Player {
    Sprite _sprite;
    float _xVelocity;
    float _yVelocity;
    int _lives;
    int _score;
    Texture _texture;
public:
    Player(int wWidth, int wHeight); // parameterized constructor
    void gainLives(int lives); // increases _lives
    void setXPos(float x); // x position setter
    void setYPos(float y); // y position setter
    void die(int wWidth, int wHeight); // decreased _lives and resets player position
    void gainPoints(int points); // increases _score
    void resetScore(); //resets score
    float getXV() const; // x velocity getter
    float getYV() const;// y velocity getter
    int getLives() const; // lives getter
    float getXPos() const; // x position getter
    float getYPos() const; // y position getter
    int getScore() const; // score/points getter
    Sprite getSprite() const; // sprite getter
    void thrust(); // increases both velocities depending on direction
    void slowDown(); // decreases both velocities
    void move(); // updates position according to velocities
    void rotateR(); // rotates right
    void rotateL();// rotates left
    void hyperspace(const int& HEIGHT, const int& WIDTH); // places player at a random point
    Laser shoot(); // creates a laser object travelling in the direction the player is facing
};
#endif //FINALPROJECT_PLAYER_H
