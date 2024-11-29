#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 3

typedef struct{
	char x;
	char o;
}simbols;

int validatePos(char BOARD[N][N], int i, int j);
int getKey();
void drawBoard(char BOARD[N][N], int x, int y);
char validateWinner(char BOARD[N][N]);

int main(int argc, char *argv[]) {
	
	char BOARD[N][N] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};
	
	simbols TURNS = {'X', 'O'};
	
	int X, Y, CURRENT_TURN;
	int POS;
	char winner;
	char symbolWinner;
	int cont;

	// 0: X, 1: O
	CURRENT_TURN = 0; 
	cont = 0;
	X = 0;
	Y = 0;
	//bucle que se ejecuta hasta que haya un ganado o se agoten los movimientos
	do{
		//bucle que lee las flechas del teclado hasta que se presione enter
		do{
			system("cls");
			
			if(CURRENT_TURN){
				printf("Turno de %c\n\n", TURNS.o);
			}else{
				printf("Turno de %c\n\n", TURNS.x);
			}
			
			drawBoard(BOARD, X, Y);
			
			POS = getKey();
			
			switch(POS) {
			    case 72:    // key up
			    	Y--;
			    	if(Y<0) Y=N-1;
			        break;
			    case 80:    // key down
			        Y++;
			    	if(Y>=N) Y=0;
					break;
			    case 77:    // key right
			    	X++;
			    	if(X>=N) X=0;
			        break;
			    case 75:    // key left
			    	X--;
			    	if(X<0) X=N-1;
			        break;
			}
		}while(POS!=13);
		
		if(validatePos(BOARD, Y, X)){
			if(CURRENT_TURN){
				BOARD[Y][X] = TURNS.o;
				CURRENT_TURN=0;
			}else{
				BOARD[Y][X] = TURNS.x;
				CURRENT_TURN=1;
			}
			cont++;
		}else{
			printf("\nPosicion ocupada!\n");
			system("pause");
		}
		winner = validateWinner(BOARD);
	}while(!winner && cont<9);
	
	//para no mostrar la ultima casilla seleccionada
	X=-1;
	Y=-1;
	
	//fin del juego
	system("cls");
	printf("Fin del Juego\n\n");
	drawBoard(BOARD, X, Y);
	
	if(!winner){
		printf("\nEmpate");
	}else{
		printf("\nEl ganador es %c", winner);
	}
	
	getch();
	return 0;
}

//Funcion que valida si la posicion elegida esta ocupada o no
int validatePos(char BOARD[N][N], int i, int j){
	if(BOARD[i][j]==' '){
		return 1;
	}
	return 0;
}

//Funcion para obtener la tecla presionada
int getKey(){
	int POS;
	POS = getch();
	
	if(POS==224){
		POS = getch();
	}
	
	return POS;
}

//Funcion para dibujar el tablero y marcar la casilla seleccionada
void drawBoard(char BOARD[N][N], int x, int y){
	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			if(j==x && i==y){
				printf("[ ");
			}else{
				printf("| ");
			}
			
			printf("%c", BOARD[i][j]);
			
			if(j==x && i==y){
				printf(" ]");
			}else{
				printf(" |");
			}
			
		}
		printf("\n");
	}
}

//funcion que verifica si hay un ganador y lo retorna
char validateWinner(char BOARD[N][N]){
	int i, j, b;
	char winner = 0;
	
	//validar filas
	i=0;
	while(i<N && b!=N){
		b=1;
		j=0;
		while(j<N-1){
			if(BOARD[i][j] != ' ' && BOARD[i][j+1] != ' '){
				if(BOARD[i][j] == BOARD[i][j+1]) b++;
			}
			j++;
		}
		if(b==N){
			winner = BOARD[i][j-1];
		}
		i++;
	}
	
	//validar columnas
	j=0;
	while(j<N && b!=N){
		b=1;
		i=0;
		while(i<N-1){
			if(BOARD[i][j] != ' ' && BOARD[i+1][j] != ' '){
				if(BOARD[i][j] == BOARD[i+1][j]) b++;
			}
			i++;
		}
		if(b==N){
			winner = BOARD[i-1][j];
		}
		j++;
	}
	
	//validar diagonal principal
	i=0;
	j=0;
	if(b!=N){
		b=1;	
		while(i<N-1 && b!=N){
			if(BOARD[i][j] != ' ' && BOARD[i][j] == BOARD[i+1][j+1]){
				b++;
			}
			
			i++;
			j++;
		}
		if(b==N){
			winner = BOARD[i-1][j-1];
		}
	} 

	//validar diagonal secundaria
	i=N-1;
	j=0;
	if(b!=N){
		b=1;	
		while(i>0 && b!=N){
			if(BOARD[i][j] != ' ' && BOARD[i][j] == BOARD[i-1][j+1]){
				b++;
			}
			
			i--;
			j++;
		}
		if(b==N){
			winner = BOARD[i+1][j-1];
		}
	} 
	
	
	return winner;
	
}



