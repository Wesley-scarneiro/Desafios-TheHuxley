/*
Descrição:
A multiplicação de dois números inteiros pode ser feita através de somas sucessivas. Proponha um algoritmo recursivo que calcule a multiplicação de dois inteiros. Você só poderá usar o operador soma.

Formato de entrada:
Dois números inteiros.

Formato de saída:
Um número inteiro representando a soma sucessiva.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Multiplica dois numeros atraves de somas sucessivas.
    Algoritmo recursivo.
*/
int somaSucessiva(int a, int b)
{
    if (a >= 0)
    {
        if (a == 0) return 0;
        else if (a > 1) return b + somaSucessiva(a-1, b);
        else return b;
    }
    else
    {
        if (a < -1) return b*(-1) + somaSucessiva(a+1, b);
        else return b*(-1);
    }
}

int main() 
{
    
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", somaSucessiva(a, b));
    
    return 0;
}