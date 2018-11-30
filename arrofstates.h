/* File: arrofstates.h */
/* Assigning char to array of states */

#ifndef __ARROFSTATES__
#define __ARROFSTATES__

#include "boolean.h"
#include "statechar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabStates[NMax+1]; /* container of statechar */
    int IdxRow;
    
    char stat; /*Status, can be 'C' = Continue, 'F' = Fail, 'W' = Win, 'T' = Tie*/
} States;

/* States */
extern boolean EndStates;
extern States CStates;

void IgnoreBlank();
/* Ignoring blanks and/or \n (enters) */

void STARTPStates();
/* I.S. : User chose player to play first
   F.S. : When CS = MARK, EndStates = true.
          When EndStates = false, CStates filled by chars of states from txt file */
  
void STARTCStates();
/* I.S. : User chose computer to play first
   F.S. : When CS = MARK, EndStates = true.
          When EndStates = false, CStates filled by chars of states from txt file */
  
void ADVStates();
/* I.S. : CS is the first char after the last CStates 
   F.S. : CStates change and filled with new states, probably MARK
          When CC = MARK, EndStates = true. */

void CopyStates();
/* Saving chars from txt file to CStates
   I.S. : CS is the first char of States
   F.S. : CStates filled with the desired states; */

#endif

