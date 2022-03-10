/*
Descrição:
Leia quatro valores inteiros A, B, C e D. A seguir, calcule e mostre a diferença do produto de A e B pelo produto de C e D.

Formato de entrada:
O arquivo de entrada contém 4 valores inteiros.

Formato de saída:
Imprima a mensagem DIFERENCA com todas as letras maiúsculas, conforme exemplo abaixo, com um espaço em branco antes e depois da igualdade e o valor da diferença dos produtos.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declaracao de variaveis - tipo int
    int a, b, c, d, produtoAB, produtoCD, diferenca;
    
    // Entrada
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    // Calculos
    produtoAB = a*b;
    produtoCD = c*d;
    diferenca = produtoAB-produtoCD;
    
    // Saida
    printf("DIFERENCA = %d", diferenca);
        
    return 0;
}