//==============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module for providing functions to work with Cell objects
// @version: 1.2 03/11/2014
//==============================================================================

// Cell module (cell.cc)

#include "cell.h"

using namespace std; // Provides direct access to std

// See interface (header file).
void Cell::notifyDisplay() {
   const char ch = state + '0';
   td->notify(r, c, ch);
} // notifyDisplay

// See interface (header file).
void Cell::notifyWindow() {
   window->fillRectangle(y, x, width, height, state);
} // notifyWindow

// See interface (header file).
Cell::Cell()
   : state(0), prevState(0), numNeighbours(0), r(0), c(0), td(0), x(0), y(0), width(0), height(0), window(0)
   {} // Default constructor

// See interface (header file).
int Cell::getState() {
   return state;
} // getState

// See interface (header file).
void Cell::setState(const int& change) {
   prevState = state;
   state = change;
   notifyDisplay();
   notifyWindow();
} // setState

// See interface (header file).
void Cell::setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w) {
   this->r = r;
   this->c = c;
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
   window = w;
   notifyWindow();
} // setCoords

// See interface (header file).
void Cell::setDisplay(TextDisplay *t) {
   td = t;
} // setDisplay

// See interface (header file).
void Cell::addNeighbour(Cell *neighbour) {
   if (numNeighbours < maxNeighbours) { // Number of neighbours less than maximum number of neighbours?
      neighbours[numNeighbours] = neighbour;
      numNeighbours += 1;
   } // if
} // addNeighbour

// See interface (header file).
void Cell::notify(const int &change) {
   setState(change);
   notify(state, prevState);
} // notify

// See interface (header file).
void Cell::notify(const int &current, const int &previous) {
   // Notifies each neighbour of the cell that the current cell
   // has updated its state.
   for (int i = 0; i < numNeighbours; ++i) {
      if (neighbours[i]->getState() == previous) { // Object's neighbour's previous state same as object?
      	 neighbours[i]->setState(current);
          neighbours[i]->notify(current, previous);
      } // if
   } // for
} // notify
