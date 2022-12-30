Additions for GitHub upload:
As may be apparent from the structure of this project and the rest of this README, this was a student project. It has been
uploaded to GitHub as a demonstration of my work with programming and a peak into my interests. All files save this one and 
CMakeLists.txt have been modified only lightly if at all since turning them in as an assignment.

People can use this for whatever they want, except in situations where it violates the Colorado School of Mines honor code, or
that of their own institution. If you do, Blaster (the burro) will find you and do what he does best.

The CMakeLists file will obviously have to be modified to use paths on a given machine for compilation, and the project must be
compiled using a 32 bit compiler, but otherwise everythng should work out of the box.



Asher Dykstra, Section C
(Bl)Asteroids


Description:
I have created a program that is a rendition of the arcade game "Asteroids." The player is able to pilot the ship on 
screen, shoot, and put the ship into hyperspace as one could in the original game. Asteroids fly around the screen and
the player can shoot them for points. An alien also flies by occasionally, which can also be shot for points. The player
hitting either of these things causes them to lose lives.The visual aspect of the game has been created using SFML. SFML 
also handles user input. A certain lovely mascot was unfortunately omitted due to time constraints, but was kept in
the name for marketing reasons.




Program Documentation:
No typing is needed for running my program. All inputs are detections of single keys or clicking the x on the window
it creates. The inputs are as follows: 

Always applicable:
Click x on the window : close the window and end the program

On the start screen:
Enter : Start game

During gameplay:
W key : Thrust player ship in the direction it is currently facing (Adds velocity. The ship loses velocity on its own when not being thrusted forward)
A key : Rotate player ship left
D key : Rotate player ship right
S key : Put player ship into hyperspace (randomize its location on the screen)
Space bar : Shoot a laser from the player ship

On the game over screen:
Enter: restart game

Each object the player can shoot and destroy is worth a different number of points. Smaller asteroids are worth more points
than larger asteroids, and the alien is worth 500 points.

In the realm of future improvements or changes, I would have given the alien the ability to shoot lasers at the player had 
I had more time to work. Implementation would probably include another vector in which to store the alien's lasers with 
similar spawn and despawn handling to that of the player's lasers. If one wanted to modify the look of the player or the alien, 
they could simply change the file path string in either class' constructor to reference a different image. You could modify
the look of the lasers or asteroids as well, but it would be more difficult because they are SFML shapes instead of images.




Tests:
Input								                        Output
Press enter key on start screen					                The program enters the gameplay state
Press "Q" on start screen					                Nothing happens and the program continues as normal
Press "D" during gameplay					                The player ship sprite rotates clockwise
Press the space bar during gameplay				            A laser object is spawned in the position of the player ship with the same direction
Type anything and press enter on the game over screen		The program re-enters the gameplay state and the typed characters affect nothing




Reflections:
The most important thing I learned from this project is the importance of having a plan before starting work on a project.
If I had not formally written out my project proposal I would have gotten lost many times due to working over the course 
of many distinct coding sessions. Although I didn't do it this time, I think that keeping a detailed log of what work was
done every session could have been helpful as well. I believe it could have reduced the re-familiarization period at the
beginning of each session and overall improved efficiency. I would also better familiarize myself with any external
libraries I would use before I started working. Searching through the SFML documentation was a massive time sink during
this project.