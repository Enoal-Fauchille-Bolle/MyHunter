# My Hunter

![Language](https://img.shields.io/badge/Language-C-blue)
![Library](https://img.shields.io/badge/Library-CSFML-green)
![Build](https://img.shields.io/badge/Build-Makefile-orange)
![Last Commit](https://img.shields.io/github/last-commit/Enoal-Fauchille-Bolle/MyHunter)
![Repo Size](https://img.shields.io/github/repo-size/Enoal-Fauchille-Bolle/MyHunter)
![License](https://img.shields.io/github/license/Enoal-Fauchille-Bolle/MyHunter)
[![WakaTime](https://wakatime.com/badge/user/018bbded-63e4-4a01-bd5e-21d050739656/project/018bf821-c401-4f78-8508-234839f55788.svg)](https://wakatime.com/badge/user/018bbded-63e4-4a01-bd5e-21d050739656/project/018bf821-c401-4f78-8508-234839f55788)

My Hunter is a retro duck hunt-inspired game developed in C using the CSFML library. In this game, you control a hunter whose goal is to shoot animated ducks moving across the screen.

## Features

- **Animated Sprites:** Ducks and other game elements are animated using sprite sheets.
- **User Interaction:** Shoot ducks using mouse clicks.
- **Time-Based Animations:** Movements and animations are synchronized with sfClock for consistent gameplay.

## Requirements

- **Language:** C
- **Library:** CSFML
- **Tools:** Make (Makefile provided)

## Compilation

To compile the project, run:

```bash
make
```

This will build the binary named `my_hunter`.

## Execution

Run the game with:

```bash
./my_hunter
```

For a brief description of the program and available commands, use:

```bash
./my_hunter -h
```

## Cleanup

- Use `make clean` to remove object files.
- Use `make fclean` to remove all generated files, including the binary.
