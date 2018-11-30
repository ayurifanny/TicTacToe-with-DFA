
/* File: arrofstates.c */

#include "boolean.h"
#include "statechar.h"
#include "arrofstates.h"

boolean EndStates;
States CStates;


void IgnoreBlank() {
/* Ignoring blanks and/or \n (enters) */
  
  while ((CS == BLANK || CS == '\n') && CS != MARK) {
     ADV();
    } 
  }

void STARTPStates() {
/* I.S. : User chose player to play first
   F.S. : When CS = MARK, EndStates = true.
          When EndStates = false, CStates filled by chars of states from txt file */
  
    STARTP();
    IgnoreBlank();
    
    //if CS = EOP
    if (CS==MARK) {
      EndStates = true;
    } else {
      EndStates = false;
      CopyStates();
    }
  }

void STARTCStates() {
/* I.S. : User chose computer to play first
   F.S. : When CS = MARK, EndStates = true.
          When EndStates = false, CStates filled by chars of states from txt file */
  
    STARTC();
    IgnoreBlank();
    
    //if CS = EOP
    if (CS==MARK) {
      EndStates = true;
    } else {
      EndStates = false;
      CopyStates();
    }
  }

void ADVStates() {
/* I.S. : CS is the first char after the last CStates 
   F.S. : CStates change and filled with new states, probably MARK
          When CC = MARK, EndStates = true. */

    //ignoring blanks and enters
    IgnoreBlank();

    //if EOP
    if(CS==MARK) {
      EndStates = true;
    } else {
      EndStates = false;
      CopyStates();
      IgnoreBlank();
    }
  }

void CopyStates() {
/* Saving chars from txt file to CStates
   I.S. : CS is the first char of States
   F.S. : CStates filled with the desired states; */

    //Variables
    int i;

    //Algorithm
    //Initializing i
    i = 1;

    //repeating steps to read chars
    while ((CS!=MARK) && (i <= NMax) && ((CS != BLANK) && (CS != '\n'))) {

      //Assigning status of CStates
      if(CS=='C' || CS == 'F' || CS == 'W' || CS == 'T') {
        CStates.stat = CS;
        i++;
        ADV();

        //When chars is not compontent of stat
      } else {

        //assigning to tables
        CStates.TabStates[i] = CS;
        ADV();
        i++;
      }
    }   
  }

