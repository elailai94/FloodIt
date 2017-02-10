//=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module to provide functions to work with TextDisplay objects
// @version 1.0 03/11/2014
//=============================================================================

// Textdisplay module (textdisplay.h)

#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;          //the n x n display 
  const int gridSize;         //size of the grid (n)

  /*
   * The following field helps track how the game as progressed
   * The field should track how much Cells of the grid are of each color
   * Whenever a Cell changes color, the corresponding color count should
   * be updated.
   */
  unsigned int colourCount[5];

public:
  TextDisplay(int n); //one arg constructor where the parameter is the gridSize
  ~TextDisplay(); // Destructor
    
  /*
   * The TextDisplay is an observer of each Cell. Cells call notify to 
   * update the (r,c) location to be ch
   */
  void notify(int r, int c, char ch);  

   /*
	* To check the win condition, the Grid calls the isFilled
	* method which returns true if all cells are the same color
	*/
  bool isFilled();
	
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
