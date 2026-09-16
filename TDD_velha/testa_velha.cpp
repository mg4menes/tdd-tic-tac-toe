// Copyright 2026 Marcello da Silva Mangueira

#include "velha.hpp"  // NOLINT(build/include_subdir)

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // NOLINT(build/include_subdir)

// Aviso:
//
// NOLINT(build/include_subdir) foi utilizado porque não foi possível incluir
// o diretório do arquivo sem alterar a organização dos arquivos do projeto.

// Comportamento esperado do jogo:
//
// 1: X venceu.
// 2: O venceu.
// 0: Empate.
// -1: Indefinido.
// -2: Impossível pelas regras.

// Teste (1): Testar se o tabuleiro vazio retorna -1 (Jogo indefinido).
// Teste (2): Testar se uma coluna de O retorna 2 (O vencedor).
// Teste (3): Testar se uma coluna de X retorna 1 (X vencedor).
// Teste (4): Testar se uma linha de O retorna 2 (O vencedor).
// Teste (5): Testar se uma diagonal de X retorna 1 (X vencedor).
// Teste (6): Testar se um empate retorna 0 (Jogo empatado).
// Teste (7): Testar se o jogo incompleto retorna -1 (Jogo indefinido).

JogoVelha CriarVelha() {
  JogoVelha velha;
  return velha;
}

TEST_CASE("Teste Tabuleiro Vazio") {
  int teste[3][3] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == -1);
}

TEST_CASE("Teste Coluna O") {
  int teste[3][3] = {{2, 0, 0},
                      {2, 0, 0},
                      {2, 0, 0}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == 2);
}

TEST_CASE("Teste Coluna X") {
  int teste[3][3] = {{1, 0, 0},
                      {1, 0, 0},
                      {1, 0, 0}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == 1);
}

TEST_CASE("Teste Linha O") {
  int teste[3][3] = {{2, 2, 2},
                      {0, 0, 0},
                      {0, 0, 0}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == 2);
}

TEST_CASE("Teste Diagonal X") {
  int teste[3][3] = {{1, 0, 0},
                      {0, 1, 0},
                      {0, 0, 1}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == 1);
}

TEST_CASE("Teste Empate") {
  int teste[3][3] = {{1, 1, 2},
                      {2, 1, 1},
                      {1, 2, 2}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == 0);
}

TEST_CASE("Teste Jogo Incompleto") {
  int teste[3][3] = {{0, 1, 0},
                      {0, 0, 1},
                      {0, 2, 2}};

  REQUIRE(CriarVelha().VerificaVelha(teste) == -1);
}
