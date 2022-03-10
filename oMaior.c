/*
Descrição:
Faça um programa que leia três valores e apresente o maior dos três valores lidos seguido da mensagem “eh o maior”. Utilize a fórmula:

Formato de entrada:
O arquivo de entrada contém três valores inteiros.

Formato de saída:
Imprima o maior dos três valores seguido por um espaço e a mensagem "eh o maior".
Desafio você fazer sem usar "if".
hahahahaha (Risada do mal!)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para retornar o mohdulo de um nuhmero
*/
int modulo(int n)
{
    if (n < 0)
    {
        n = n * (-1);
    }
    
    return n;
}

/*
    Esta funcao verifica qual dos dois numeros dados eh maior.
    A funcao encontra o maior com base na seguinte equacao:
    maiorAB = ((a+b) + |a-b|)/2
    Em |a-b| eh aplicado a funcao modulo
*/
int maiorAB(int a, int b)
{
    int maiorAB;
    
    maiorAB = ((a+b) + modulo((a-b)))/2;
    
    return maiorAB;
}


int main() 
{
    // Variaveis
    int a, b, c, resultado;
    
    // Entrada de tres numeros
    scanf("%d %d %d", &a, &b, &c);
    
    // Chamando a funcao maiorAB
    resultado = maiorAB(maiorAB(a, b), c);
    
    printf("%d eh o maior\n", resultado);
    
	return 0;
}