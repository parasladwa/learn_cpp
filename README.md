
# Conway's Game of Life in C++

Made to improve my C++ skills through a classic coding challenge.

A simple C++ terminal implementation of Conway’s Game of Life to practice C++ programming.

## About

The Game of Life is a cellular automaton where cells live or die based on neighbors:

- Live cell with <2 or >3 neighbors dies.
- Live cell with 2 or 3 neighbors lives.
- Dead cell with exactly 3 neighbors becomes alive.

## Features

- Random initial grid (50x50)
- Toroidal wrapping grid edges
- Terminal visualization with `#` (alive) and `.` (dead)
- Auto-update with delay and screen clear

## How to Run

Compile with:

```bash
g++ -std=c++11 -o game_of_life main.cpp
```

Run with:

```bash
./game_of_life
```



## Future Ideas

- Custom grid sizes
- User input patterns
- Pause/resume controls
- GUI version

---



