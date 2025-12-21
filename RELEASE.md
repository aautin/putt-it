## Configuration of the development workflow and environment
- Conan and CMake configurations, selecting the projects to build and compilation settings, no packages conflicts and easy imports
- The main branch is protected by CI rules and automates release deployments
- Putt-It is downloadable through releases in a zip file, including all the dependencies

## The game
- We can shoot the ball in a direction, the ball movement is affected by air friction
- The ball is shootable again when its move ends
- The ball spawns in the map's middle and respawns when it goes beyond window's limits
- A cup is placed on the window, its position is random and the ball must reach it to end the game