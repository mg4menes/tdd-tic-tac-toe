// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

int JogoVelha::VerificaVelha(int velha[3][3]) {
  if (VerificaVazio(velha) == true) {
    return -1;
  }

  return VerificaColuna(velha);
}

int JogoVelha::VerificaColuna(int velha[3][3]) {
  for (int col = 0; col < 3; col++) {
    if (velha[0][col] == velha[1][col] && velha[1][col] == velha[2][col]) {
      if (velha[0][col] != 0) {
        return velha[0][col];
      }
    }
  }

  return -2;
}

bool JogoVelha::VerificaVazio(int velha[3][3]) {
  for (int lin = 0; lin < 3; lin++) {
    for (int col = 0; col < 3; col++) {
      if (velha[lin][col] != 0) {
        return false;
      }
    }
  }

  return true;
}
