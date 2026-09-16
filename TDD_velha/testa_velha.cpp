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

TEST_CASE("Teste Tabuleiro Vazio") {
  JogoVelha velha;

  int teste[3][3] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}};

  REQUIRE(velha.VerificaVelha(teste) == -1);
}

TEST_CASE("Teste Coluna O") {
  JogoVelha velha;

  int teste[3][3] = {{2, 0, 0},
                      {2, 0, 0},
                      {2, 0, 0}};

  REQUIRE(velha.VerificaVelha(teste) == 2);
}