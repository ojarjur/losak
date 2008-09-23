/* console.h: Functions for writting directly to the console. */
/* Copyright (c) 2004 - 2007 by Omar Jarjur

This program is free software; you can redistribute it and/or
modify it under the terms of version 2 of the GNU General Public
License as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifdef BARE_HARDWARE
#include "console.h"
#define VIDEO_MEM 0xb8000

#define WHITE_BLACK 0x07
#define BLACK_BLACK 0x00
#define WHITE_BLUE 0x17
#define BLUE_BLUE 0x11
#define BLACK_WHITE 0x70
#define WHITE_WHITE 0x77

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

int xPos, yPos;
char char_buff[20];

char getChar(int col, int row) {
  if ((col < MAX_WIDTH) && (row < MAX_HEIGHT)) {
    return *((char*)(VIDEO_MEM + (row * 2 * MAX_WIDTH) + (col * 2)));
  }
  return 0;
}

void writeChar(char myChar, unsigned char aspect, int col, int row) {
  char* charAddr;
  if ((col < MAX_WIDTH) && (row < MAX_HEIGHT)) {
    charAddr = (char*)VIDEO_MEM + (row * 2 * MAX_WIDTH) + (col * 2);
    *charAddr = myChar;
    charAddr++;
    *charAddr = aspect;
  }
}

void copyLines(int col, int row, int width, int height) {
  int i, j;
  for (j = row; j < (row+height); j++) {
    for (i = col; i < (col+width); i++) {
      writeChar(getChar(i,(j+1)), WHITE_BLUE, i, j);
    }
  }
  for (i = col; i < (col+width); i++) {
    writeChar(' ', WHITE_BLUE, i, (row+height));
  }
}

void clearScreen(unsigned char aspect){
  int row, col;
  for (row=0; row < MAX_HEIGHT; row++){
    for (col=0; col<MAX_WIDTH; col++){
      writeChar(' ',aspect,col,row);
    }
  }
}

void print(char c) {
  int i;
  if (c == '\n') {
    for (i = xPos; i < 79; i++) {
      writeChar(' ',WHITE_BLUE,i,yPos);
    }
    xPos = 0;
    yPos++;
  } else if (c == '\r') {
    xPos = 0;
  } else if (c == '\t') {
    i = xPos;
    xPos = (((xPos+4)/4)*4);
    for (i; (i<xPos)&&(i<79); i++) {
      writeChar(' ',WHITE_BLUE,i,yPos);
    }
  } else if (c == 8) { /** Backspace */
    if (xPos > 0) {
      writeChar(' ',WHITE_BLUE,xPos,yPos);
      xPos--;
    }
  } else {
    writeChar(c,WHITE_BLUE,xPos,yPos);
    xPos++;
  }
  if (xPos >= 79) {
    writeChar('\\',WHITE_BLUE,79,yPos);
    xPos -= 79;
    yPos++;
  }
  if (yPos > 24) {
    copyLines(0,0,80,24);
    yPos = 24;
  }
  writeChar('_',WHITE_BLUE,xPos,yPos);
}

void printf(char* str) {
  int currChar;
  for (currChar = 0;
       (str!=0)&&(str[currChar]!=0);
       currChar++) {
    print(str[currChar]);
  }
}

void init_console() {
  xPos = yPos = 0;
  clearScreen(BLUE_BLUE);
}

#endif
