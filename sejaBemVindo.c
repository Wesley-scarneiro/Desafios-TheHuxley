/*
Descrição:
Você está organizando um evento e deseja que os seus convidados se sintam importantes. Sendo assim, quando cada convidado chega ao local você pergunta o nome dele e digita no computador. Então o nome dele é exibido em um painel luminoso na entrada do salão. A mensagem que aparece é: "Seja muito bem-vindo Fulano de Tal, onde Fulano de Tal é o nome da pessoa que chegou.

Formato de entrada:
O nome da pessoa, que pode conter até 120 caracteres

Formato de saída:
O programa deve imprimir a mensagem "Seja muito bem-vindo Fulano de Tal", seguido de um final de linha.
*/

#include <stdio.h>

// Tamanho maximo da string
#define T 120

int main() 
{
    char nome[T];
    
    // Nao guarda o '\n' e nao finaliza quando encontra um espaco.
    gets(nome);
    
    printf("Seja muito bem-vindo %s\n", nome);
    
    return 0;
}