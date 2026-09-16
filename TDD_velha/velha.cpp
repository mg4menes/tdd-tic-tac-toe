#include "velha.hpp"

int VerificaVelha( int velha[3][3] )
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (velha[i][j] != 0){
				return 0;
			}		
		}
	}

	return -1; //Tabuleiro vazio
}


