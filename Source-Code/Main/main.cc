//=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Program to enable a player to play the Flood It game
// @version: 1.0 03/11/2014
//=============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "cell.h"
#include "grid.h"
#include "textdisplay.h"

using namespace std;                                      // Provides direct access to std

// Reads in row coordinates, column coordinates, and states during initialization
// mode with input stream in until row and column coordinates, which signals the
// end of initialization mode. When reading in from a file stream, the EOF signal
// also ends initialization mode.
void initGrid(istream &in, Grid *grid) {
   int row;                                               // Stores the read in row coordinate
   int col;                                               // Stores the read in column coordinate
   int state;                                             // Stores the read in state

   // Reads in row coordinates, column coordinates, and states until row and
   // column coordinates, which signals the end of initialization mode,
   // and/or an EOF character is encountered.
   while (in >> row >> col) {
      if (row == -1 && col == -1) {                       // Stop initialization mode from in?
         break;
      } // if

      in >> state;
      grid->init(row, col, state);
   } // while

   cout << *grid;
} // initGrid

int main() {
   string s;                                              // Stores the read in command
   bool gameInProgress = false;                           // Indicates whether a game is in progress
   int numOfMovesLeft = 0;                                // Stores the number of moves left for a game

   Grid *newGrid = new Grid;

   while (cin >> s) {
      int num;                                            // Stores the read in integer
      
      if (s == "new") {                                   // Create new n x n grid?
      	cin >> num;

      	if (gameInProgress == false) {                   // Another game isn't in progress?
            newGrid->init(num);
         } // if
      } else if (s == "init") {                           // Start initialization mode from stdin?
         initGrid(cin, newGrid);
      } else if (s == "include") {                        // Start initialization mode from file?
      	string filename;                                 // Stores the read in file name
      	cin >> filename;
      	ifstream ifs(filename.c_str());                  // Connects stream and filename
         initGrid(ifs, newGrid);
      } else if (s == "game") {                           // Start a new game?
      	cin >> num;

      	  if (gameInProgress == false) {                 // Another game isn't in progress?
      	  	  gameInProgress = true;
      	     numOfMovesLeft = num;
      	     
      	     if (numOfMovesLeft == 1) {                  // Only one move left?
      	     	  cout << numOfMovesLeft << ' ' << "move left" << endl;
      	     } else {
      	        cout << numOfMovesLeft << ' ' << "moves left" << endl;
      	     } // if  
      	  } // if
      } else if (s == "switch") {                         // Switch top-left cell?
      	cin >> num;                                      // Ask Adam about whether switch can take in invalid states
         
         if (num >= 0 && num <= 4) {                      // Valid state?
         	newGrid->change(num);
      	   cout << *newGrid;
      	   numOfMovesLeft -= 1;
      	    
      	   if (numOfMovesLeft == 1) {                    // One move left? 
               cout << numOfMovesLeft << ' ' << "move left" << endl;
      	   } else {
      	      cout << numOfMovesLeft << ' ' << "moves left" << endl;
      	   } // if
         } // if

      	if (numOfMovesLeft == 0) {                      // Run out of moves?
            gameInProgress = false;
            
            if (newGrid->isWon()) {                      // Game won?
               cout << "Won" << endl;
            } else {
               cout << "Lost" << endl;
            } // if
            
            break;
      	} // if
      } else if (s == "?") {                             // Print out colour key?
         cout << "White:" << ' ' << '0' << endl;
         cout << "Black:" << ' ' << '1' << endl;
         cout << "Red:" << "   " << '2' << endl;
         cout << "Green:" << ' ' << '3' << endl;
         cout << "Blue:" << "  " << '4' << endl;
      } // if

      if (gameInProgress == true && newGrid->isWon()) {  // Game won?
      	cout << "Won" << endl;
      	break;
      } // if
   } // while

   delete newGrid;
}
