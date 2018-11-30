/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "statechar.h"
#include <stdio.h>

//initializing variables
char CS;
boolean EOP;

static FILE * state;
static int retval;

void STARTP() {
/*  Start to read txt file.
  If CS != MARK, then it's not EOP
     CS == MARK, then it's EOP */

  //Opening state txt
  state = fopen("stateplayer.txt","r");
  ADV();
}

void STARTC() {
/*  Start to read txt file.
  If CS != MARK, then it's not EOP
     CS == MARK, then it's EOP */

  //Opening state txt
	state = fopen("statecomp.txt","r");
	ADV();
}

void ADV() {
/* Advancing CS to the next char. 
   I.S. : A char, not EOP
   F.S. : The next char after, probably EOP
		 If CS is MARK, then EOP = true */

	/* Algorithm */
  //scanning
	retval = fscanf(state,"%c",&CS);
  // if EOP
	EOP = (CS == MARK);
	if (EOP) {
       fclose(state);
 	}
}
