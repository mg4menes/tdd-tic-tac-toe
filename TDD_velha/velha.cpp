// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

int JogoVelha::VerificaVelha(int velha[3][3]) {
  if (TemQuantidadeIncoerente(velha)) {
    return IMPOSSIVEL;
  }

  int jogador_vencedor = VerificaVencedor(velha);

  if (vitorias_linhas > 1 || vitorias_colunas > 1) {
    return IMPOSSIVEL;
  }

  if (jogador_vencedor == JOGADOR_X || jogador_vencedor == JOGADOR_O) {
    return jogador_vencedor;
  }

  if (RestaPosicaoVazia(velha)) {
    return INDEFINIDO;
  }

  return EMPATE;
}

bool JogoVelha::TemQuantidadeIncoerente(int velha[3][3]) {
  int quantidade_x = 0;
  int quantidade_o = 0;

  for (int lin = 0; lin < 3; lin++) {
    for (int col = 0; col < 3; col++) {
      if (velha[lin][col] == JOGADOR_X) {
        quantidade_x += 1;
      } else if (velha[lin][col] == JOGADOR_O) {
        quantidade_o += 1;
      }
    }
  }

  return (quantidade_x > quantidade_o + 1) || (quantidade_o > quantidade_x + 1);
}

int JogoVelha::VerificaVencedor(int velha[3][3]) {
  vitorias_linhas = 0;
  vitorias_colunas = 0;

  int vencedor = INDEFINIDO;

  int resultado = VerificaColuna(velha);
  if (TemVencedor(resultado)) {
    vencedor = resultado;
  }

  resultado = VerificaLinha(velha);
  if (TemVencedor(resultado)) {
    vencedor = resultado;
  }

  resultado = VerificaDiagonal(velha);
  if (TemVencedor(resultado)) {
    vencedor = resultado;
  }

  return vencedor;
}

int JogoVelha::VerificaColuna(int velha[3][3]) {
  int vitorioso = INDEFINIDO;

  for (int col = 0; col < 3; col++) {
    if (velha[0][col] == velha[1][col] &&
        velha[1][col] == velha[2][col] &&
        velha[0][col] != 0) {
        vitorioso = velha[0][col];
        vitorias_colunas += 1;
    }
  }

  return vitorioso;
}

int JogoVelha::VerificaLinha(int velha[3][3]) {
  int vitorioso = INDEFINIDO;

  for (int lin = 0; lin < 3; lin++) {
    if (velha[lin][0] == velha[lin][1] &&
        velha[lin][1] == velha[lin][2] &&
        velha[lin][0] != 0) {
        vitorioso = velha[lin][0];
        vitorias_linhas += 1;
    }
  }

  return vitorioso;
}

int JogoVelha::VerificaDiagonal(int velha[3][3]) {
  int vitorioso = INDEFINIDO;

  if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) ||
      (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0])) {
        if (velha[1][1] != 0) {
          vitorioso = velha[1][1];
        }
  }

  return vitorioso;
}

bool JogoVelha::TemVencedor(int resultado) {
  return (resultado == JOGADOR_X || resultado == JOGADOR_O);
}

bool JogoVelha::RestaPosicaoVazia(int velha[3][3]) {
  for (int lin = 0; lin < 3; lin++) {
    for (int col = 0; col < 3; col++) {
      if (velha[lin][col] == 0) {
        return true;
      }
    }
  }
  return false;
}
