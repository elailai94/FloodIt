//=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module to provide functions to work with Grid objects
// @version: 1.0 03/11/2014
//=============================================================================

// Grid module (grid.h)

#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include "cell.h"
#include "textdisplay.h"
#include "window.h"

class Grid {
  Cell **theGrid;                   // The actual n x n grid. 
  int gridSize;                     // Size of the grid (n)
  TextDisplay *td;                  // The text display.
  Xwindow * theWindow;              // The window display.

  void clearGrid();                 // Frees the theGrid field.

  void findNeighbours();            // Finds all neighbours for each cell in theGrid field.

public:
  Grid();                           // Constructor
  ~Grid();                          // Destructor

  // Checks if a game has been won.
  bool isWon();						
  
  // Sets up an n x n grid.  Clears old grid, if necessary.
  void init(int n);
  
  // Notifies Cell (0,0) of the change to new state: state
  void change(const int & state);
  
  // Sets the state for r,c to state
  void init(int r, int c, int state);
  
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
