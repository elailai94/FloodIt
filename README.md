FloodIt
=======
### About
FloodIt is a simple tile-matching puzzle game. FloodIt is written entirely in C++08 and builts on most UNIX-like operating systems (i.e.: Linux or Mac). The graphical component of the game is implemented using the X11 library. The game is played by altering the colour of the very top left square of the grid, so that each adjacent square sharing the very top left square's colour can also be changed to the new colour. The game makes use of the Observer design pattern.

### Compilation
```bash
make
```
