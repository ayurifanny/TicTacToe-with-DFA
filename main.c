#include <stdio.h>
#include "boolean.h"
#include "statechar.h"
#include "arrofstates.h"
#include "tictactoe.h"


int main() {
	//Variables
	States Tab[30][10]; //array of states
	States Path[100]; //array for the state that was visited (?)
	States cur; //current state
	int i,j,k,N,count; //iterator
	int in, choice; //input
	
	
	STARTGAME();
	//Asking for input on who goes first
	printf("Silakan pilih yang akan pertama kali main :\n1. Komputer Dulu\n2. Anda Dulu\n");
	do {
		scanf("%d", &choice);
		if (choice != 1 && choice != 2) {
			printf("Masukan Anda salah, silakan input kembali :)\n");
		}
	} while (choice != 1 && choice != 2);

	//Opening file txt
	if (choice == 1) {
		STARTCStates();
		N = 20;
	} else if (choice == 2) {
		STARTPStates();
		N = 21;
	}
	
	//Assigning states to table
	for(i = 1; i <= N; i++) {
		for(j = 0; j <= 9; j++){
			CStates.IdxRow = i;
			Tab[i][j] = CStates;
			ADVStates();
		}
	}

	//Assigning the first current states
	cur = Tab[1][0];
	Path[1] = cur;
	count = 2;

	//Printing them
	PrintState(cur);
	
	//Starting the game
	while (cur.stat != 'W' && cur.stat != 'T') {
		printf("Masukkan Input Posisi yang Anda Inginkan : ");
		scanf("%d", &in);
		cur = Delta(cur, in, Tab);
		
		//Remembering the path
		Path[count] = cur;
		count++;

		//Preview the current game
		printf("Tampilan Board : \n");
		PrintState(cur);
		
		//Warnings
		if(cur.stat == 'W') {
			printf("Maaf Anda Kalah, Komputer Menang\n");
		} else if (cur.stat == 'T') {
			printf("Permainan yang sengit! Anda dan Komputer seri!\n");
		} else if (cur. stat == 'F') {
			printf("Posisi sudah terisi, silakan input ulang\n");
		} else if (cur.stat != 'C') {
			printf("Posisi yang Anda masukkan tidak tersedia\n");
		}
	
	}

	//Printing the path
	printf("States yang sudah pernah dilalui adalah :\n");
	for (i = 1; i < count; i++) {
		PrintState(Path[i]);
		printf("\n");
	}
	
	return 0;
	}



