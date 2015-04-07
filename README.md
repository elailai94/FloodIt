FloodIt
=======
### About
FloodIt is a simple tile-matching puzzle game. FloodIt is written entirely in C++08 and builts on most UNIX-like operating systems (i.e.: Linux or Mac). The graphical component of the game is implemented using the X11 library. The game is played by altering the colour of the very top left square of the grid, so that each adjacent square sharing the very top left square's colour can also be changed to the new colour. The game makes use of the Observer design pattern.

### Screenshots
#### Sample Game Interaction
![FloodIt_Screenshot1](https://cloud.githubusercontent.com/assets/7763904/7017279/37efc230-dcc3-11e4-8da2-bbf5a04c9429.png)
#### Board (Graphical Display)
![FloodIt_Screenshot2](https://cloud.githubusercontent.com/assets/7763904/7017281/3a1535ae-dcc3-11e4-8a5d-1cf835225e74.png)

### Compilation
```bash
make
```

### Execution
```bash
./flood-graphical
```

### Usage
#### Game Commands
- **new  n** creates a new *n* x *n* grid, where *n* >= 1. If there was already an active grid, that grid is destroyed and replaced with the new one.
- **init** enters initialization mode. Subsequently, reads triples of integers *r c s* and sets the cell at row *r*, column *c* to state *s*. The top-left corner is row 0, column 0. The coordinates -1 -1 end initialization mode. It is possible to enter initialization mode more than once, and even while the game is running. A set of invalid co-ordinates and state will be ignored. When initialization mode ends, the board should be displayed.
- **include f** includes the file *f*, which contains a list of cell initializations of the same form of initialization from *init*. This file doesn't have to end with the coordinates -1 -1.
- **game g** starts a new game, with a commitment to solve the game in *g* moves or fewer, once the board has been initialized. *game* can't be called once a game has been started.
- **switch s** switches the top-left (0,0) cell to s within a game, changes all appropriate neighbours, and then redisplays the grid.

> Note: By pressing **CTRL-D**, an end-of-file (EOF) signal terminates the game.

### Known Issues
- X11 library has memory leaks.
