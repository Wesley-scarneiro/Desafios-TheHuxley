/*
Descrição:
O cenário é uma terra muito distante, onde ainda ocorre o caos aéreo. Você, é o desenvolvedor de software responsável pelos sistemas da Ambrosino Airlines. Sua missão é desenvolver um sistema de reserva de passagens. A Ambrosino Airlines possui 37 voos fixos.

Formato de entrada:
Uma sequência de 37 pares de inteiros, indicando o número do voo e a quantidade de lugares disponíveis no respectivo voo. Depois você lerá uma sequência de pedidos de reserva. Cada pedido de reserva é representado por um par de inteiros indicando, respectivamente, o número do documento de identidade do cliente e o número do voo que o cliente deseja viajar. A entrada se encerra quando o número do documento de identidade do cliente for igual a 9999. Existe a possibilidade de que o cliente deseje viajar em um voo que não está sendo oferecido pela Ambrosino Airlines.

Formato de saída:
Caso exista disponibilidade no voo, imprima o número do documento de identidade do cliente. Caso não exista disponibilidade ou não exista o voo desejado, imprima a string: INDISPONIVEL
Lembre-se que uma vez que o cliente faz a reserva em um voo, a disponibilidade deve ser reduzida.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para percorrer o voos[] e verificar se um determinado elemento esta listado.
    Se o elemento procurado estiver listado, entao eh chamado tambem o array vagas[] para
    gerar uma saida.
    Realiza uma busca sequencial.
*/
int verificarReserva(int voos[], int vagas[], int documento, int elemento)
{
    int i;
    
    for (i = 0; i < 37; ++i)
    {
        if (voos[i] == elemento)
        {
            // Verificando se existem vagas disponives
            if (vagas[i] != 0)
            {
                vagas[i] -= 1;
                return 1;
            }
            
            return 0;
        }
    }
    
    // Se chegou ate aqui, a identificao do voo informada nao existe.
    return 0;
}

/*
    Funcao que verifica a disponibilidade de um reserva de voo.
*/
void imprimirResultado(int documento, int resultado)
{
    if (resultado == 1)
    {
        printf("%d\n", documento);
    }
    else
    {
        printf("INDISPONIVEL\n");
    }
}

int main() 
{
    // Variaveis
    int voos[37], vagas[37], documento, codigo, i;
    
    /*
        Recebendo os voos e as suas respectivas vagas.
        A identificao dos voos e suas vagas sao guardados em arrays
        diferentes, mas com o mesmo numero de indice.
    */
    for (i = 0; i < 37; ++i)
    {
        scanf("%d %d", &voos[i], &vagas[i]);
    }
    
    /*
        Recebendo as reservas para um dos 37 voos possiveis.
        Quando 'documento' = 9999, entao sera encerrado.
        Para cada entrada eh chamada uma funcao para percorrer
        o array voos[] e verificar se existem vagas.
    */
    scanf("%d %d", &documento, &codigo);
    
    while (documento != 9999)
    {
        // Chamando a funcao
        if (documento != 9999)
        {
            imprimirResultado(documento, verificarReserva(voos, vagas, documento, codigo));
        }
        
        // Atualizando entrada
        scanf("%d %d", &documento, &codigo);
    }
    
    return 0;
}