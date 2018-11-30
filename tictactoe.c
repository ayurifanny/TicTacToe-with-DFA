#include <stdio.h>
#include "boolean.h"
#include "statechar.h"
#include "arrofstates.h"
#include "tictactoe.h"

void STARTGAME() {
/*Starting game, viewing the main menu(s)*/
	printf("  _   _   _   _   _     _   _   _   _   _     _   _   _   _ \n"); 
 	printf(" / | / | / | / | / |   / | / | / | / | / |   / | / | / | / |\n"); 
	printf("( T | u | g | a | s ) ( B | e | s | a | r ) ( T | B | F | O )\n");
 	printf(" |_/ |_/ |_/ |_/ |_/   |_/ |_/ |_/ |_/ |_/   |_/ |_/ |_/ |_/\n"); 
  	printf("  _   _   _     _   _   _   _   _   _   _     _     _     _   _   _   _   _   _   _   _\n");  
 	printf(" / | / | / |   / | / | / | / | / | / | / |   / |   / |   / | / | / | / | / | / | / | / |\n"); 
	printf("( A | y | u ) ( R | i | f | a | n | n | y ) ( M ) ( / ) ( 1 | 3 | 5 | 1 | 7 | 0 | 3 | 8 )\n");
 	printf(" |_/ |_/ |_/   |_/ |_/ |_/ |_/ |_/ |_/ |_/   |_/   |_/   |_/ |_/ |_/ |_/ |_/ |_/ |_/ |_/ \n");
 	printf("\n");
 	printf("\n");
}



int IdxSame (States current, States Tab[][10]) {
/*Get an int of the current state row idx
 	USE SEARCHING ALGORITHM, finds the same states, and return the idx*/

 	//Variables
	int i,j;
	boolean bool,same;

	//return the current idx when status is fail
	if (current.stat == 'F') {
		return current.IdxRow;

	//other condition
	} else {
		//initialize value
		i = 1;
		bool = false;

		//search for the location of the same states in the array
		while ((i<=22) && (bool == false)) {
			j=1;
			same = true;
			while ((j < 10) && (bool == false) && (same == true)) {
				if (current.TabStates[j] != Tab[i][0].TabStates[j]) {
					same = false;
				}
				j++;
			}
			if (same == true) {
				bool = true;
			}
			i++;
		}
		return i-1;
	}
}

States Delta(States current, int i, States Tab[][10]) {
/*I.S : Tab is filled with states,
		i is the user input
		current states is defined
  F.S : current states now is filled with the new state that pointed by i*/
	//Variables
	int j;

	j  = IdxSame(current, Tab);
	return Tab[j][i];		
}


void PrintState (States states) {
/*Printing states to 3x3 matrix format (like tictactoe table)*/
	//Variables
	int k,i;

	k=1;
	for (i = 1; i <= 9; i++) {
		printf("%c ", states.TabStates[i]);
		// making 3 colomns per row
		if (k%3 == 0) {
			printf("\n");
		}
		k++;
	}
}