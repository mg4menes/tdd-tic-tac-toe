// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

int JogoVelha::VerificaVelha(int velha[3][3]) {
  if (VerificaVazio(velha) == true) {
    return -1;
  }

  if (velha[0][0] == velha[1][0] and velha[1][0] == velha[2][0]){ //3 bolas na coluna 1
	  if (velha[0][0] == 2) {
      return 2;
	  }
  }

  if (velha[0][1] == velha[1][1] and velha[1][1] == velha[2][1]){ //3 bolas na coluna 2
	  if (velha[0][1] == 2) {
      return 2;
	  }
  }

  if (velha[0][2] == velha[1][2] and velha[1][2] == velha[2][2]){ //3 bolas na coluna 3
	  if (velha[0][2] == 2) {
      return 2;
	  }
  }

  return 0;
}

bool JogoVelha::VerificaVazio(int velha[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (velha[i][j] != 0) {
        return false;
      }
    }
  }

  return true;
}
