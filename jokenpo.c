#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

// Define as cores das fontes para o console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"

// Reseta para a cor padrão
#define RESET   "\x1b[0m"

// Jokenpo.c

int main(){
    while(1){

        // Permite o uso de acentuação
        setlocale(LC_ALL, "Portuguese");

        char nome_jogador[12];
        int jogada_jogador = -1;
        int jogada_computador;
        int placar_jogador = 0, placar_computador = 0;
        int c;
        int sair;

        // lista para chamar os nomes das jogadas possíveis (substitui um switch)
        char jogadas_possiveis[3][7] = {"PEDRA", "PAPEL", "TESOURA"};

        bool vitoria, derrota, empate;

        // permite que a geração de números aleatórios seja diferente para cada execução do programa
        srand(time(NULL));

        printf("JokenBot: ... Outro desafiante? ... \n");
        printf("\nJokenBot: Quem ousa me desafiar!? Diga o seu nome, desafiante! ");
        fgets(nome_jogador, 12, stdin);

        // substitui o caractere de newline ao clicar ENTER pelo de fim de string
        nome_jogador[strcspn(nome_jogador, "\n")] = '\0';

        // limpa o console para melhorar a jogabilidade
        system("cls");

        printf("Hahaha! Boa sorte");
        printf(BLUE " %s" RESET, nome_jogador);
        printf("\nQuem marcar 5 pontos vence! >:D\n\n");

        while(1){
        printf("\nEscolha a jogada");
        printf(GREEN" vencedora\n\n"RESET);
        printf("0 - PEDRA\n1 - PAPEL\n2 - TESOURA\n3 - ENCERRAR DUELO");

        printf("\n\nSua jogada: ");
        scanf("%d", &jogada_jogador);

        // limpa o buffer de entrada, impedindo que o caractere de newline seja executado no próximo input de dados
        while ((c = getchar()) != '\n' && c != EOF);

        system("cls");

        // gera uma jogada aleatória entre 0 e 2
        jogada_computador = rand() % 3;
        printf("\n\n===============================================================");
        printf(BLUE"\n%s [%s]"RESET, nome_jogador, jogadas_possiveis[jogada_jogador]);
        printf(" x ");
        printf(CYAN"[%s] JokenBot\n\n"RESET, jogadas_possiveis[jogada_computador]);

        // isola os comportamentos de vitória, empate e derrota
        vitoria = (jogada_jogador == 0 && jogada_computador == 2)||
                  (jogada_jogador == 1 && jogada_computador == 0)||
                  (jogada_jogador == 2 && jogada_computador == 1);

        empate = jogada_jogador == jogada_computador;

        derrota = (jogada_jogador == 0 && jogada_computador == 1)||
                  (jogada_jogador == 1 && jogada_computador == 2)||
                  (jogada_jogador == 2 && jogada_computador == 0);

        if(vitoria){
            printf(GREEN "JokenBot: Foi um golpe de sorte! >:|" RESET);
            placar_jogador++;
        }
        else if(empate){
            printf(YELLOW "JokenBot: é... :|" RESET);
        }
        else if(derrota){
            printf(RED "JokenBot: Muito fácil hahaha >:D" RESET);
            placar_computador++;
        } else {
            printf("JokenBot: Esta tão nervoso que não lembra dos movimentos válidos? xD");
        }

        printf(BLUE"\n\n%s %d" RESET, nome_jogador, placar_jogador);
        printf(" x ");
        printf(CYAN"%d CPU\n" RESET, placar_computador);
        printf("===============================================================\n\n");

        if (placar_jogador == 5){
            printf(GREEN"VOCÊ VENCEU!"RESET);
            printf(BLUE"\nJokenBot: É... terei que reconhecer que você me superou :)"RESET);
            break;
        }
        if (placar_computador == 5){
            printf(RED"VOCÊ PERDEU"RESET);
            printf(CYAN"\nJokenBot: Mais uma vítima para a conta! >:D"RESET);
            break;
        }
    }

        printf("\n\nDeseja jogar novamente? \n\n0 - NAO \nOutra tecla - SIM");
        scanf("%d", &sair);
        while ((c = getchar()) != '\n' && c != EOF);

        system("cls");

        if(sair == 0){
            printf("\nJokenBot: Nos vemos novamente! ;)\n");
            break;
        }
    }

    return 0;
}