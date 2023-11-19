# cub3D

## Collaborator
**GitHub:** [Omakran]((https://github.com/thee-falcon))

## Overview

Welcome to cub3D, my first RayCaster built using miniLibX! This project was part of the mandatory curriculum at 1337. It's a recreation of the iconic first-person shooter [Wolfenstein 3D][1] using C programming language. The game utilizes raycasting rendering techniques to create a 3D illusion within the console.

## About

cub3D takes a map file containing configuration details as its primary argument and performs the following actions:

- Parses the configuration file
- Initializes player information structures
- Loads textures and sprites
- Continuously refreshes the screen using a raycasting algorithm, creating different images as the player moves or otates.

The game supports various events and functionalities, including:

- Player movement (WASD keys)
- Player rotation (arrow keys)
- Exiting the game (pressing ESC)

### Building and Running the Project

1. Clone this repository:

    ```bash
    git clone git@github.com:yoamzil/42_Cub3d.git
    ```

2. Navigate to the root directory and execute `make`:

    ```bash
    cd 42_cub3D
    make
    ```

3. Run `./cub3d maps/map.cub` to start the game.

## Sources and References

- [Understanding how a raycasting algorithm works][3]
- [Wolfenstein 3D Gameplay][1]
- [Project Subject][2]

[1]: https://www.youtube.com/watch?v=7P_dic-pSKo&ab_channel=3DRealms
[2]: https://github.com/lucaslefrancq/42_cub3D/blob/master/cub3D.en.subject.pdf
[3]: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
