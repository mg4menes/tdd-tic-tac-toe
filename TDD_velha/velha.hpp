// Copyright 2026 Marcello da Silva Mangueira

#ifndef TDD_VELHA_VELHA_HPP_
#define TDD_VELHA_VELHA_HPP_

class JogoVelha {
 public:
  bool VerificaVazio(int velha[3][3]);

  int VerificaLinha(int velha[3][3]);

  int VerificaColuna(int velha[3][3]);

  int VerificaVelha(int velha[3][3]);
};

#endif  // TDD_VELHA_VELHA_HPP_
