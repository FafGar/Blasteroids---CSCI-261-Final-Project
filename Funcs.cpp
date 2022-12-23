/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains function definitions for various functions unattached to any particular class.
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include "Funcs.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Asteroid.h"
#include <cmath>
using namespace sf;
using namespace std;


void screenLoop(Player& player, int maxX, int maxY){
    if (player.getXPos() < 0) { // if the player touches an end of the screen, make them appear at the opposite edge
        player.setXPos((float)maxX);
    } else if (player.getXPos() > maxX){
        player.setXPos(0);
    } else if (player.getYPos() < 0){
        player.setYPos((float)maxY);
    } else if (player.getYPos() > maxY){
        player.setYPos(0);
    }
}
void screenLoop(Asteroid& asteroid, int maxX, int maxY) {
    if (asteroid.getXPos() < -20) {// if the asteroid touches an end of the screen, make them appear at the opposite edge
        asteroid.setXPos((float)maxX+20);
    } else if (asteroid.getXPos() > maxX+20){
        asteroid.setXPos(-20);
    } else if (asteroid.getYPos() < -20){
        asteroid.setYPos((float)maxY+20);
    } else if (asteroid.getYPos() > maxY+20){
        asteroid.setYPos(-20);
    }
}
void centerOrigin(Sprite& sprite){
    sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width/2, // center the origin of the sprite
                     sprite.getLocalBounds().top + sprite.getLocalBounds().height/2);
}
void centerOrigin(RectangleShape& sprite){
    sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width/2,// center the origin of the rectangle
                     sprite.getLocalBounds().top + sprite.getLocalBounds().height/2);
}
void centerOrigin(Text& text){
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2,// center the origin of the text
                   text.getLocalBounds().top + text.getLocalBounds().height/2);
}
void centerOrigin(ConvexShape& shape){
    shape.setOrigin(shape.getLocalBounds().left + shape.getLocalBounds().width/2, // center the origin of the convex shape
                    shape.getLocalBounds().top + shape.getLocalBounds().height/2);
}
bool collisionDetect(const float& posAx, const float& posAy,const float& pos2x,const float& pos2y, const int aSize) {
    if (fabs(posAy - pos2y) <= 20*aSize && fabs(posAx - pos2x) <= 20*aSize ){ // if the two provided points are in contact, return true
        return true;
    }
    else { // otherwise, return false.
        return false;
    }
}

