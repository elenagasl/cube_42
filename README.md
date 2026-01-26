*This project has been created as part of the 42 curriculum by elengarc and danielji*

# cub3D

## Description

This project renders a 3D graphical representation of a 2D map from a first-person perspective using ray casting. It is written in **C language** and uses the [MinilibX](https://github.com/42paris/minilibx-linux) library.

## Instructions

This program only runs in a **Linux** environment.

To compile the program and its dependencies:

```bash
make
```

In order to run the program you must indicate the path to a valid `.cub` file as the first argument. Some test maps are included in the `maps` directory.

```bash
./cub3D maps/test.cub
```
Press `W`, `A`, `S` or `D` to move the point of view through the space, and Left or Right arrow keys to rotate it.

To exit the program, press `Esc` or close the window.

### Debug

The MinilibX library produces memory leaks. A Valgrind suppression file has been provided to silent them. To use it run:
```bash
valgrind --suppressions=x11.supp ./cub3D maps/test.cub
```

## Map files

A valid `.cub` map file should indicate the path to four `.xpm` texture walls (North, South, East, West), and two RGB colors (floor and ceiling).

The map uses `0` and `1` to indicate floor tiles and walls. An `N`, `S`, `E` or `W` character indicates the player's starting position and orientation.

The map should be enclosed by walls. If the map is not valid an error message will briefly describe the cause.

This is an example of a valid map:

```
NO ./textures/test1.xpm
SO ./textures/test2.xpm
WE ./textures/test3.xpm
EA ./textures/test4.xpm

F 80,80,80
C 120,120,200

         11111111111111111111111 
        1000000000110000000000001
        1011000001110000000000001  1111
        1001000000000000000000001  1001
111111111011000001110000000000001  1111
10000000001100000111011111111111 
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

  11111
  10001
  11111

```

## Resources

- 42paris: [minilibx-linux](https://github.com/42paris/minilibx-linux) 
- Lode Vandevenne: [Lode's Computer Graphics Tutorial | Raycasting](https://lodev.org/cgtutor/raycasting.html)

### How AI was used

- We asked AI for instructions on how to scale a texture without distortions step by step.
