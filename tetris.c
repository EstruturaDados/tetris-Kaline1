#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome;   
    int id;      
} Peca;

#define TAM 5

Peca fila[TAM];
int inicio = 0;
int fim = 0;
int quantidade = 0;
int proximoID = 0;

Peca gerarPeca() {
    Peca p;
    char tipos[4] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = proximoID;
    proximoID++;
    return p;
}

void inserirPeca() {
    if (quantidade == TAM) {
        printf("Fila cheia, Nao da para inserir.\n");
        return;
    }
    fila[fim] = gerarPeca();
    fim = (fim + 1) % TAM; 
    quantidade++;
}
void jogarPeca() {
    if (quantidade == 0) {
        printf("Fila vazia, Nao tem mais pecas para jogar.\n");
        return;
    }
    printf("Voce jogou a peca [%c %d]\n", fila[inicio].nome, fila[inicio].id);
    inicio = (inicio + 1) % TAM;
    quantidade--;
}
void mostrarFila() {
    printf("Fila de pecas:\n");

    if (quantidade == 0) {
        printf("(vazio)\n");
        return;
    }

    int i;
    int pos = inicio;

    for (i = 0; i < quantidade; i++) {
        printf("[%c %d] ", fila[pos].nome, fila[pos].id);
        pos = (pos + 1) % TAM;
    }
    printf("\n");
}

int main() {
    int i;
    int opcao;

    for (i = 0; i < TAM; i++) {
        inserirPeca();
    }

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogarPeca();
        } else if (opcao == 2) {
            inserirPeca();
        } else if (opcao == 0) {
            break;
        } else {
            printf("Opcao invalida.\n");
        }

        mostrarFila();
    }

    printf("Programa encerrado.\n");
    return 0;
}

