#include "velha.hpp"

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//Comportamento esperado do jogo:
//
// 1: X venceu
// 2: O venceu
// 0: Empate
// -1: Indefinido
// -2: Impossível pelas regras++

//Teste (1): Testar se o tabuleiro vazio retorna -1 (Jogo indefinido)

TEST_CASE("Teste Tabuleiro Vazio") {
	int teste1[3][3] = {{0, 0, 0 }, 
						{ 0, 0, 0 },
						{ 0, 0, 0 }};

    REQUIRE(VerificaVelha(teste1) == -1);
} 
 
