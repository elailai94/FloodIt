//==============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module for providing functions to work with Cell objects
// @version: 1.2 03/11/2014
//==============================================================================

// Cell module (cell.h)

#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
#include "window.h"

const int maxNeighbours = 4;         // Maximum number of neighbours a cell can have 

// Object definition
class Cell {
  int state;                         // Current state of the cell
  int prevState;                     // Previous state of the cell
  int numNeighbours;                 // Number of neighbors
  Cell *neighbours[maxNeighbours];   // Pointers to neighbors
  int r, c;                          // Co-ordinates of the cell
  TextDisplay * td;                  // Pointer to the text display

  int x, y;
  int width, height;
  Xwindow *window;                   // Pointer to the window

  void notifyDisplay();		         // Notify the TextDisplay of the change
  void notifyWindow();              // Notify the Window of the change

public:
  Cell();                           // Default constructor

  int getState();                   //getter for private state
  void setState(const int& change); //setter for private state

  //setter for private co-ordinates of cell
  void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w);

  void setDisplay(TextDisplay * t); //setter for TextDisplay

  void addNeighbour(Cell *neighbour); //add a neighbouring cell
  
  /*
   * Intended to be called only by the grid class for changing the state of the 0 0 cell
   */
   void notify( const int & change);	

  /*
   * Intended to be called by Cells to notify their neighbors
   * current: this cells current(new) state 
   * previous: this cells past state
   */
   void notify(const int & current, const int & previous); 
};

#endif
