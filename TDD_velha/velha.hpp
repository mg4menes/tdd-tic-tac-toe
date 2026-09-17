// Copyright 2026 Marcello da Silva Mangueira

#ifndef TDD_VELHA_VELHA_HPP_
#define TDD_VELHA_VELHA_HPP_

class JogoVelha {
 public:
  int vitorias_detectadas = 0;

  enum Resultado {
    IMPOSSIVEL = -2,
    INDEFINIDO = -1,
    EMPATE = 0,
    JOGADOR_X = 1,
    JOGADOR_O = 2
  };

  bool TemQuantidadeIncoerente(int velha[3][3]);

  int VerificaVencedor(int velha[3][3]);

  bool RestaPosicaoVazia(int velha[3][3]);

  int VerificaLinha(int velha[3][3]);

  int VerificaColuna(int velha[3][3]);

  int VerificaDiagonal(int velha[3][3]);

  bool TemVencedor(int resultado);

  int VerificaVelha(int velha[3][3]);
};

#endif  // TDD_VELHA_VELHA_HPP_
