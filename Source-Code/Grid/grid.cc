/=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module to provide functions to work with Grid objects
// @version: 1.0 03/11/2014
//=============================================================================

// Grid module (grid.cc)

#include "grid.h"

using namespace std; // Provides direct access to std

// See interface (header file).
void Grid::clearGrid() {
   // Returns all allocated memory for theGrid back to the heap
   for (int i=0; i < (gridSize * gridSize); ++i) {
   	  delete theGrid[i];
   } // for
   delete [] theGrid;
} //clearGrid

// See interface (header file).
void Grid::findNeighbours() {
   // Finds and adds all the neighbours of each cell in theGrid.
   for (int i = 0; i < (gridSize * gridSize); ++i) {
   	const int currRow = i / gridSize;                         // Stores the current row coordinate
      const int currCol = i % gridSize;                         // Stores the current column coordinate
      
      if ((currRow - 1) >= 0 && (currRow - 1) < gridSize) {     // Top neighbour exists?
         const int top = (currRow - 1) * gridSize + currCol;    // Stores position of top neighbour in theGrid
         theGrid[i]->addNeighbour(theGrid[top]);
      } // if

      if ((currRow + 1) >= 0 && (currRow + 1) < gridSize) {     // Bottom neighbour exists?
         const int bottom = (currRow + 1) * gridSize + currCol; // Stores position of bottom neighbour in theGrid
         theGrid[i]->addNeighbour(theGrid[bottom]);
      } // if

      if ((currCol - 1) >= 0 && (currCol - 1) < gridSize) {     // Left neighbour exists?
         const int left = currRow * gridSize + (currCol - 1);   // Stores position of left neightbour in theGrid
         theGrid[i]->addNeighbour(theGrid[left]);
      } // if
         
      if ((currCol + 1) >= 0 && (currCol + 1) < gridSize) {     // Right neighbour exists?
         const int right = currRow * gridSize + (currCol + 1);  // Stores position of right neighbour in theGrid
         theGrid[i]->addNeighbour(theGrid[right]);
      } // if

   } // for
} // findNeighbours

// See interface (header file).
Grid::Grid()
   : theGrid(0), gridSize(0), td(0), theWindow(0) {} // Constructor

// See interface (header file).
Grid::~Grid() {
   clearGrid();
   delete td;
   delete theWindow;
} // Destructor

// See interface (header file).
bool Grid::isWon() {
   return td->isFilled();
} // isWon

// See interface (header file).
void Grid::init(int n) {
   if (n != gridSize) { // Another new grid size required?
   	clearGrid();
   	delete td;
      delete theWindow;

      gridSize = n;
      Cell **newGrid = new Cell*[gridSize * gridSize];
      TextDisplay *newTextDisplay = new TextDisplay(gridSize);
      Xwindow *newWindow = new Xwindow;

      const int windowWidth = 500;
      const int windowHeight = 500;

      // Allocates a new block of memory from the heap for each cell.
      // Sets their coordinates and display grid as well.
      for (int i=0; i < (gridSize * gridSize); ++i) {
         const int row = i / gridSize;
         const int col = i % gridSize;
         const int width = windowWidth / gridSize;
         const int height = windowHeight / gridSize;
         const int x = row * width;
         const int y = col * height;

         Cell *newCell = new Cell;
         newCell->setCoords(row, col, x, y, width, height, newWindow);
         newCell->setDisplay(newTextDisplay);
         newGrid[i] = newCell;
      } // for

      theGrid = newGrid;
      td = newTextDisplay;
      theWindow = newWindow;

      findNeighbours();
   } // if
} // init

// See interface (header file).
// Notify 
void Grid::change(const int &state) {
   if (state != theGrid[0]->getState()) {               // New state different from current state?
      theGrid[0]->notify(state);
   } // if
} // change

// See interface (header file).
void Grid::init(int r, int c, int state) {
   if (state >= 0 && state <= 4) {                      // Valid states?
   	  
   	  if (r >= 0 && r < gridSize) {                   // Valid row coordinate?
   	  	 
   	  	 if (c >= 0 && c < gridSize) {                 // Valid column coordinate?
            
            theGrid[r * gridSize + c]->setState(state); // Stores temporary pointer to cell to be modified
         } // if
      } // if
   } // if
} // init

// See interface (header file).
ostream &operator<<(ostream &out, const Grid &g) {
   out << *(g.td);
   return out;
} // Overloaded operator<<
