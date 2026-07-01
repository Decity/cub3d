*This project has been created as part of the 42 curriculum by ebelle and crabin.*

# cub3D

## Description

cub3D is a first-person ray-casting engine inspired by Wolfenstein 3D. Built entirely in C using the miniLibX graphics library, it renders a navigable 3D environment from a 2D map using the **ray-casting** technique: for each vertical column of pixels, a ray is cast from the player's position and the distance to the nearest wall is used to determine the height of the column to draw, creating the illusion of depth.

The engine handles:
- Raycasting
- Directional wall textures (North, South, East, West faces render different XPM images)
- Configurable floor and ceiling colors (RGB)
- Smooth movement and rotation
- Strict map validation (closed walls, valid characters, proper `.cub` format)
- FPS display

## Instructions

### Dependencies

- `cc` (C compiler)
- X11 and Xext libraries (Linux): `libx11-dev`, `libxext-dev`
- `make`

### Compilation

```bash
make
```

This builds `libft`, `minilibx-linux`, and the `cub3D` binary.

| Rule | Effect |
|------|--------|
| `make` / `make all` | Build `cub3D` |
| `make clean` | Remove object files |
| `make fclean` | Remove objects and binary |
| `make re` | Full rebuild |
| `make debug` | Build with `-g` flag |

### Running

```bash
./cub3D <path/to/map.cub>
```

Example:

```bash
./cub3D maps/test1.cub
```

### Map format (`.cub`)

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 160,160,160
C 19,19,19

111111
100001
1000N1
111111
```

- `NO` `SO` `WE` `EA` — paths to XPM wall textures
- `F` / `C` — floor / ceiling RGB colors in range `[0,255]`
- Map characters: `1` wall, `0` empty, `N`/`S`/`E`/`W` player spawn + facing direction
- Map must be enclosed by walls on all sides
- Map must be the last element in the file

### Controls

| Key | Action |
|-----|--------|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` or `Q` / `E` | Rotate left / right |
| `ESC` | Quit |
| Window close button | Quit |

## Resources

### Ray-casting

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — primary reference for DDA algorithm and projection math
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

### AI usage

AI was used during this project for the following tasks:
- Answering development related questions and offer feedback
- Help clean up norm errors
- Edit this README
