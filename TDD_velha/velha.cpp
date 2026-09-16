// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

int JogoVelha::VerificaVelha(int velha[3][3]) {
  if (VerificaVazio(velha) == true) {
    return -1;
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
