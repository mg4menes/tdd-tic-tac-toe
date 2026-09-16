// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

int JogoVelha::VerificaVelha(int velha[3][3]) {
  if (VerificaVazio(velha)) {
    return INDEFINIDO;
  }

  int resultado = VerificaColuna(velha);
  if (TemVencedor(resultado)) {
    return resultado;
  }

  resultado = VerificaLinha(velha);
  if (TemVencedor(resultado)) {
    return resultado;
  }

  resultado = VerificaDiagonal(velha);
  if (TemVencedor(resultado)) {
    return resultado;
  }

  for (int lin = 0; lin < 3; lin++) {
    for (int col = 0; col < 3; col++) {
      if (velha[lin][col] == 0) {
        return INDEFINIDO;
      }
    }
  }

  return EMPATE;
}

bool JogoVelha::TemVencedor(int resultado) {
  return (resultado == JOGADOR_X || resultado == JOGADOR_O);
}

int JogoVelha::VerificaColuna(int velha[3][3]) {
  for (int col = 0; col < 3; col++) {
    if (velha[0][col] == velha[1][col] &&
        velha[1][col] == velha[2][col] &&
        velha[0][col] != 0) {
        return velha[0][col];
    }
  }

  return -2;
}

int JogoVelha::VerificaLinha(int velha[3][3]) {
  for (int lin = 0; lin < 3; lin++) {
    if (velha[lin][0] == velha[lin][1] &&
        velha[lin][1] == velha[lin][2] &&
        velha[lin][0] != 0) {
        return velha[lin][0];
    }
  }

  return -2;
}

int JogoVelha::VerificaDiagonal(int velha[3][3]) {
  if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) ||
      (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0])) {
        if (velha[1][1] != 0) {
          return velha[1][1];
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
