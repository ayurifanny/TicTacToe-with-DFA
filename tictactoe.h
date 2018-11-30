/*File : tictactoe.h*/

#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

#include <stdio.h>
#include "boolean.h"
#include "statechar.h"
#include "arrofstates.h"

void STARTGAME();
/*Starting game, viewing the main menu(s)*/


int IdxSame (States current, States Tab[][10]);
/*Get an int of the current state row idx
 	USE SEARCHING ALGORITHM, finds the same states, and return the idx*/

States Delta(States current, int i, States Tab[][10]);
/*I.S : Tab is filled with states,
		i is the user input
		current states is defined
  F.S : current states now is filled with the new state that pointed by i*/

void PrintState (States states);
/*Printing states to 3x3 matrix format (like tictactoe table)*/

#endif