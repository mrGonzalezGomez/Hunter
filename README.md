# My Hunter

## Overview

My Hunter is an interactive game developed using the SFML library. It features a dynamic gameplay where players need to shoot down moving targets using mouse clicks. The game integrates various SFML modules such as Graphics, System, and Audio to create an engaging user experience.

## Features

- **Dynamic Enemy Movement:** Enemies move across the screen, and their speed increases over time.
- **Mouse Click Interaction:** Players interact with the game using mouse clicks to shoot targets.
- **Score System:** The game tracks the player's score based on their ability to hit the targets.
- **Audio Feedback:** Sound effects are played on shooting targets and other game interactions.

## Dependencies

To run My Hunter, you need to have the SFML library installed. The game uses the following SFML modules:
- `SFML/Graphics.h`
- `SFML/System.h`
- `SFML/Audio.h`

## Compilation

Compile the game using GCC with the following command:
```
gcc -o my_hunter main.c -l sfml-graphics -l sfml-system -l sfml-audio
```

## Usage

To start the game, simply run the compiled executable:
```
./my_hunter
```

For help or to display game instructions, use:
```
./my_hunter -h
```

## Contributing

Contributions to My Hunter are welcome. Please send your contributions as pull requests on GitHub.
