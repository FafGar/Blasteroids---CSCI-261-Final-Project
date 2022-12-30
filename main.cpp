/* CSCI 261: Final Project
 *
 * Author: Asher Dykstra (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *      N/A
 *
 * This file contains all logic processing for playing my rendition of the Atari game "Asteroids".
 * All graphical aspects are handled by SFML
 * (MORE_COMPLETE_DESCRIPTION_HERE)
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Asteroid.h"
#include "Laser.h"
#include "Alien.h"
#include "Funcs.h"

using namespace std;
using namespace sf;

int main() {


    const int WIDTH = 900;
    const int HEIGHT = 900;
    RenderWindow window( VideoMode(WIDTH, HEIGHT), "ASTEROIDS" );// create a RenderWindow object

    bool playing = false; // game state handling booleans
    bool finished = false;

    Player player(WIDTH,HEIGHT); // create a player object

    vector<Asteroid> asteroids; // create empty vectors to store asteroid and laser objects
    vector<Laser> lasers;

    Clock playerLaserClock;  // player timing clocks
    Clock playerCollisionClock;
    Clock playerHyperspaceClock;

    Alien alien(HEIGHT,WIDTH); // alien handling variables.
    Clock alienClock;
    bool isAlien;
    float alienStart;

    int lifeCheck = 4; // use to avoid slowdown due to assigning strings repeatedly
    int lifePointCounter = 0; // tracks how many extra lives the player has earned

    Font font; // all text data is established before the display loop to prevent slow down.
    if( !font.loadFromFile( "calibri.ttf" ) ) {
        cerr << "Could not load font" << endl;
        return -1;
    }

    Text lives("LIVES: 4",font); // life counter displayed during gameplay
    lives.setOrigin(lives.getLocalBounds().left+lives.getLocalBounds().width, lives.getLocalBounds().top);
    lives.setPosition(WIDTH-5,5);

    Text score("SCORE: 0", font); // score counter displayed during gameplay
    score.setPosition(5,5);

    Text start("Press enter to start", font); // start prompt on startup screen.
    start.setFillColor((Color::White));
    centerOrigin(start);
    start.setPosition(WIDTH / 2.f, HEIGHT / 2.f + 50);

    Text title("ASTEROIDS", font, 75); // title on startup screen.
    title.setFillColor(Color::White);
    centerOrigin(title);
    title.setPosition(WIDTH / 2.f, HEIGHT / 2.f);

    Text gameOver("GAME OVER", font, 90); // game over statement on game over screen
    centerOrigin(gameOver);
    gameOver.setPosition(WIDTH/2.f,90);

    Text endScore("SCORE: ", font, 60); // score display on game over screen
    endScore.setPosition(WIDTH / 2.f, gameOver.getPosition().y + 120);

    Text scoresTitle("HIGH SCORES", font, 50); // high scores header on game over screen.
    centerOrigin(scoresTitle);
    scoresTitle.setPosition(WIDTH/2.f, endScore.getPosition().y + 60);

    ifstream scoresIn("scores.txt"); // File I/O pt 1.
    string tempString;
    string highScores;
    int scoreArr[5];
    while(getline(scoresIn,tempString)){
        highScores+= tempString +="\n";
        scoreArr[stoi(tempString.substr(0,1))-1] = stoi(tempString.substr(3, tempString.length()-4));
    }
    scoresIn.close(); // Always close the file, kids
    Text scores(highScores,font,40); // high scores list on game over screen.
    scores.setOrigin(scores.getLocalBounds().left+scores.getLocalBounds().width, scores.getLocalBounds().top);
    scores.setPosition(WIDTH/2.f,scoresTitle.getPosition().y+60);

    Text playAgain("Press enter to play again",font, 50); // start again prompt on game over screen
    centerOrigin(playAgain);
    playAgain.setPosition(WIDTH/2.f, scores.getPosition().y+scores.getLocalBounds().height+200);


    while (window.isOpen()){// begin display loop.
        window.clear(Color::Black);

        if (!playing && !finished) { // display title screen until the player presses enter
            window.draw(title);
            window.draw(start);


        } else if (playing){//active play section of the display loop

            window.draw(player.getSprite());// player drawing and movement section
            //not using events to handle movement for the sake of smooth control
            if (Keyboard::isKeyPressed(Keyboard::A)){ // rotate left if "A" is pressed
                player.rotateL();
            } else if (Keyboard::isKeyPressed(Keyboard::D)){ // rotate right if "D" is pressed
                player.rotateR();
            }
            if (Keyboard::isKeyPressed(Keyboard::W)){ // gain velocity in the current direction if "W" is pressed
                player.thrust();
            } else{ // if not gaining velocity, gradually lose velocity.
                player.slowDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Space)){ // if spacebar is pressed, shoot a laser
                if (playerLaserClock.getElapsedTime().asSeconds() > 0.25f) { // the shooting functionality has a cool down timer
                    lasers.push_back(player.shoot());
                    lasers.at(lasers.size()-1).fixOrigin();
                    playerLaserClock.restart();
                    if (lasers.size() > 4){
                        lasers.erase(lasers.begin());
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::S)){ // if "S" is pressed, enter hyperspace
                if (playerHyperspaceClock.getElapsedTime().asSeconds() > 0.5f){ // the hyperspace functionality also has a cool down, but it serves as more of a debounce.
                    player.hyperspace(HEIGHT,WIDTH);
                    playerHyperspaceClock.restart();
                }
            }
            if (player.getScore()/20000 != lifePointCounter){ // add another life every 20000 points scored
                player.gainLives(1);
                lifePointCounter = player.getScore()/20000;
            }
            player.move(); //update the player's position
            screenLoop(player, WIDTH, HEIGHT); // have the player who up on the other side if they fly off screen

            for(int i=0;i<lasers.size();++i) { // laser drawing and movement section
                window.draw(lasers.at(i).getShape());
                lasers.at(i).move();
            }

            // alien handling section
            if (!isAlien && alienClock.getElapsedTime().asSeconds()>rand()%20+5){ //spawn an alien every 5-25 seconds there isn't an alien
                alien.start(WIDTH,HEIGHT);
                alienClock.restart();
                alienStart = alien.getSprite().getPosition().x;
                isAlien = true;
            }
            if (isAlien){ // there is only ever one alien object, so only move it around when it is supposed to be there
                window.draw(alien.getSprite());
                alien.move();
                if (collisionDetect(alien.getSprite().getPosition().x,alien.getSprite().getPosition().y,player.getXPos(),player.getYPos(),1)){
                    player.die(WIDTH,HEIGHT); // if the player runs into the alien, the player loses 2 lives.
                    player.die(WIDTH,HEIGHT);
                }
                if(fabs(alienStart-alien.getSprite().getPosition().x) > WIDTH){ // if the alien reaches the other side of the screen, make it disappear
                    isAlien = false;
                    alienClock.restart();
                }
                for (int j = 0; j<lasers.size(); ++j) { // if the alien gets hit with a laser, make it disappear and give the player 500 points
                    if(collisionDetect(alien.getSprite().getPosition().x,alien.getSprite().getPosition().y,lasers.at(j).getXPos(),lasers.at(j).getYPos(),1)){
                        isAlien = false;
                        lasers.erase(lasers.begin()+j);
                        player.gainPoints(500);
                        score.setString("SCORE: " + to_string(player.getScore()));
                        alienClock.restart();
                    }
                }
            }


            for(int i=0;i<asteroids.size();++i){ // asteroid drawing and movement section

                window.draw(asteroids.at(i).getShape());
                asteroids.at(i).move();
                screenLoop(asteroids.at(i),WIDTH, HEIGHT);
                // if the player runs into an asteroid, the player dies. To mitigate losing multiple lives at once, a debounce timer is implemented
                if (collisionDetect(asteroids.at(i).getXPos(),asteroids.at(i).getYPos(),player.getXPos(),player.getYPos(),asteroids.at(i).getSize())){
                    if(playerCollisionClock.getElapsedTime().asSeconds() > 0.00003f * sqrt(pow(player.getYV(), 2) + pow(player.getXV(), 2))){
                        player.die(WIDTH,HEIGHT);
                    }
                }else{
                    playerCollisionClock.restart(); // restart the debounce timer
                }
                for (int j = 0; j<lasers.size(); ++j){ // if an asteroid is hit by a laser, fracture the asteroid and give the player points based on the asteroid's size.
                    if (collisionDetect(asteroids.at(i).getXPos(),asteroids.at(i).getYPos(),lasers.at(j).getXPos(),lasers.at(j).getYPos(),asteroids.at(i).getSize())){
                        lasers.erase(lasers.begin()+j);
                        player.gainPoints(600/asteroids.at(i).getSize());
                        score.setString("SCORE: " + to_string(player.getScore()));
                        asteroids.push_back(asteroids.at(i).fracture());
                    }
                }
                if (asteroids.at(i).getSize() <= 0){ // remove any asteroids of size 0
                    asteroids.erase(asteroids.begin()+i);
                }
            }
            if(asteroids.size() <= 0){ // if no asteroids are left, make 5 more.
                for (int i=0; i<5; ++i) {
                    Asteroid asteroid(WIDTH, HEIGHT);
                    asteroid.fixOrigin();
                    asteroids.push_back(asteroid);
                }
            }

            if(player.getLives() < 1){ // If the player runs out of lives, update the final score text and transfer to the game over screen
                playing = false;
                finished = true;
                endScore.setString( "SCORE: " + to_string(player.getScore()));
                centerOrigin(endScore);
                    for(int i  = 0; i < 5; ++i) { // update the high score array if the player's score is in the top 5 scores
                    if(scoreArr[i] < player.getScore()){
                        for (int j  = 4; j>i; --j) {
                            scoreArr[j] = scoreArr[j-1];
                        }
                        scoreArr[i] = player.getScore();
                        break;
                    }
                }
                tempString = "";
                for (int j  = 0; j<5; ++j){ // update the high score list to be displayed.
                    tempString += to_string(j+1)+". " + to_string(scoreArr[j]) +"\n";
                }
                scores.setString(tempString);
            }

            if (player.getLives()!= lifeCheck) { // update the onscreen life counter if the player dies.
                lives.setString("Lives: " + to_string(player.getLives()));
                lifeCheck = player.getLives();
            }
            window.draw(lives);
            window.draw(score);
        } else if (finished){
            //display the game over screen
            window.draw(gameOver);
            window.draw(endScore);
            window.draw(scoresTitle);
            window.draw(scores);
            window.draw(playAgain);

        }
        window.display();



        Event event;
        while (window.pollEvent(event)) {      // ask the window if any events occurred
            if (event.type == Event::Closed) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();// then close our window
                //File I/O pt 2.
                ofstream scoresOut("scores.txt"); // only update the high score file when the player exits the program
                if (scoresOut.is_open()) {
                    for (int i = 0; i < 5; ++i) {
                        scoresOut << to_string(i + 1) << ". " << to_string(scoreArr[i]) << endl;
                    }
                }
                scoresOut.close(); // Always close your file stream, kids.
            } else if (event.key.code == Keyboard::Enter && !playing){ // when the player exits the intro screen or the game over screen
                isAlien = false; //set all variables to the appropriate initial conditions
                lifePointCounter = 0;
                player.resetScore();
                asteroids.clear();
                player.gainLives(4);
                score.setString("SCORE: 0");
                playing = true; //enter playing mode and populate the screen with asteroids
                for (int i=0; i<5; ++i) {
                    Asteroid asteroid(WIDTH, HEIGHT);
                    asteroid.fixOrigin();
                    asteroids.push_back(asteroid);
                }
            }

        }



    }
    return 0;
}