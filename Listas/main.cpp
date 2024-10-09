#include <cstdio>
#include <cstdlib>
#include <string>
#include "Lista.h"
#include <iostream>

using namespace std;

int main() {
    TipoDado palavra;
    int opcao;
    int indice;

    Lista_Construtor();

    do {
        system("cls");
        printf("Gerenciador de Lista de Palavras\n\n");
        printf("Selecione uma das opcoes:\n");
        printf("1 - Adicionar palavra (ordenada e sem duplicatas)\n");
        printf("2 - Localizar palavra\n");
        printf("3 - Localizar por indice\n");
        printf("4 - Exibir todas as palavras\n");
        printf("5 - Contar elementos\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("Digite a palavra: ");
                cin >> palavra;
                if (Lista_Inserir_Ordenada(palavra))
                    printf("Palavra adicionada com sucesso.\n");
                else
                    printf("Erro ao adicionar a palavra.\n");
                system("pause");
                break;

            case 2:
                printf("Digite a palavra a ser localizada: ");
                cin >> palavra;
                if (Lista_BuscarPeloElemento(palavra, indice))
                    printf("Palavra encontrada no índice %d.\n", indice);
                else
                    printf("Palavra não encontrada.\n");
                system("pause");
                break;

            case 3:
                printf("Digite o índice a ser localizado: ");
                scanf("%d", &indice);
                if (Lista_BuscarPelaPosicao(palavra, indice))
                    printf("Palavra no índice %d: %s\n", indice, palavra.c_str());
                else
                    printf("Índice inválido ou lista vazia.\n");
                system("pause");
                break;

            case 4:
                printf("Palavras na lista:\n");
                indice = 0;
                while (Lista_BuscarPelaPosicao(palavra, indice)) {
                    printf("Índice %d: %s\n", indice, palavra.c_str());
                    indice++;
                }
                system("pause");
                break;

            case 5:
                printf("Total de elementos na lista: %d\n", Lista_Tamanho());
                system("pause");
                break;

            case 6:
                Lista_Destrutor();
                printf("Sistema encerrado. Lista destruída.\n");
                break;

            default:
                printf("Opção inválida.\n");
                system("pause");
                break;
        }
    } while (opcao != 6);

    return 0;
}
