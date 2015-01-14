//=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module to provide functions to work with TextDisplay objects
// @version: 1.0 03/11/2014
//=============================================================================

// Textdisplay module (textdisplay.cc)

#include "textdisplay.h"

using namespace std; // Provides direct access to std

// See interface (header file).
TextDisplay::TextDisplay(int n)
   :theDisplay(0), gridSize(n) {
   char **newDisplay = new char*[gridSize];

   // Allocates new memory from the heap for theDisplay
   for (int i = 0; i < gridSize; ++i) {
   	newDisplay[i] = new char[gridSize];
   	for (int j = 0; j < gridSize; ++j) {
         newDisplay[i][j] = '0';
   	} // for
   } // for

   theDisplay = newDisplay;

   const int totalNumOfColours = 5;
   // Initializes each element in colourCount to zero
   for (int i = 0; i < totalNumOfColours; ++i) {
      colourCount[i] = 0;
   } // for

   colourCount[0] = gridSize * gridSize;

} // Constructor

// See interface (header file).
void TextDisplay::notify(int r, int c, char ch) {
   const char prevChar = theDisplay[r][c]; // Stores the old char
   colourCount[prevChar - '0'] -= 1;
   colourCount[ch - '0'] += 1;
   theDisplay[r][c] = ch;
} // notify

// See interface (header file).
bool TextDisplay::isFilled() {
   const int totalNumOfColours = 5;            // Stores the total number of colours possible

   // Checks whether there's a colour count equal to total
   // number of cells in theDisplay grid
   for (int i=0; i < totalNumOfColours; ++i) {
       if (colourCount[i] == (gridSize * gridSize)) { // A colour count equaling total number of cells in grid?
          return true;
       } // if
   } // for

   return false;
} // isFilled

// See interface (header file).
TextDisplay::~TextDisplay() {
   // Returns all allocated memory for theDisplay back to the heap.
   for (int i = 0; i < gridSize; ++i) {
   	  delete [] theDisplay[i];
   } // for

   delete [] theDisplay;
}// destructor

// See interface (header file).
ostream &operator<<(ostream &out, const TextDisplay &td) {
   // Prints out each element in theDisplay to the screen.
   for (int i = 0; i < td.gridSize; ++i) {
   	  for (int j = 0; j < td.gridSize; ++j) {
   	  	 out << td.theDisplay[i][j];
   	  } // for
   	  out << endl;
   } // for

   return out;
} // Overloaded operator<<
