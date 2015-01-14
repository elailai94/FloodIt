/=============================================================================
// FloodIt
//
// @author: Elisha Lai
// @description: Module to provide functions to work with Xwindow objects
// @version: 1.0 03/11/2014
//=============================================================================

// Window module (window.h)

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];

 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.

  enum {White=0, Black, Red, Green, Blue}; // Available colours.

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
  void drawString(int x, int y, std::string msg);

};

#endif
