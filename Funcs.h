/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains function prototypes for various functions unattached to any particular class.
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#ifndef FINALPROJECT_FUNCS_H
#define FINALPROJECT_FUNCS_H

#endif //FINALPROJECT_FUNCS_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Asteroid.h"
using namespace sf;

void screenLoop(Player& player, int maxX, int maxY); // creates a looping affect if the player tries to go off-screen
void screenLoop(Asteroid& asteroid, int maxX, int maxY);// creates a looping affect if the asteroid tries to go off-screen
void centerOrigin(Sprite& sprite); // centers the origin of the sprite
void centerOrigin(RectangleShape& sprite);// centers the origin of the rectangle
void centerOrigin(Text& text);// centers the origin of the text
void centerOrigin(ConvexShape& shape);// centers the origin of the shape
bool collisionDetect(const float& posAx, const float& posAy,const float& pos2x,const float& pos2y,int aSize); // returns true if the two points specified are in contact, returns false otherwise


