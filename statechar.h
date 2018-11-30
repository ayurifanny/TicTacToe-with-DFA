/* File: statechar.h*/
/* Read states from txt file char by char  */

#ifndef _STATECHAR_H_
#define _STATECHAR_H_

#include "boolean.h"

//mark defines EOP
#define MARK '.'

extern char CS;
extern boolean EOP;

void STARTP();
/* 	Start to read player goes first txt file.
	If CS != MARK, then it's not EOP
	   CS == MARK, then it's EOP */

void STARTC();
/* 	Start to read computer goes first txt file.
	If CS != MARK, then it's not EOP
	   CS == MARK, then it's EOP */

void ADV();
/* Advancing 1 char to the right
   I.S. : A CS is a char from txt file, and not EOP
   F.S. : The next Char, CS probably MARK
          If CS == MARK, set EOP to be true */

#endif
