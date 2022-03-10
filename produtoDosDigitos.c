/*
Descrição:
Para um número inteiro N dado, não-negativo, encontrar o mínimo Q natural tal que o produto de todos os dígitos de Q é igual N.

Formato de entrada:
A entrada contém um número inteiro positivo N, tal que 9 < N < 100000.

Formato de saída:
O menor número, o qual o produto dos seus dígitos é igual a N, e "-1", se não existir, seguido de uma quebra de linha.
Obs: Para alguns casos o valor fica demasiado grande, use long int;
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para verificar se um numero eh primo:
    0 - Nao eh primo
    1 - Eh primo
*/
int verificarPrimo(long int n)
{
    int i, resultado;
    
    // 0 e 1 nao sao primos
    if (n == 0 || n == 1)
    {
        return resultado = 0;
    }
    
    // Verificar se ainda nao eh um primo
    for (i = 2; i <= (n-1); ++i)
    {
        // Se resto for zero, entao nao eh primo
        if (n % i == 0)
        {
            return resultado = 0;
        }
    }
    
    // Se chegou ate aqui, 'n' eh primo
    return resultado = 1;
}

/*
    Funcao para quebrar um numero < 100 000  em seus respectivos digitos.
*/
int separarDigitos(long int n)
{
    long int d1, d2, d3, d4, d5, produto;
    
    // Para n com dois digitos
    if (n > 9 && n < 100)
    {
        d1 = n/10;
        d2 = n - (10*d1);
        
        // Retorna o produto dos digitos
        return produto = d1 * d2;
    }
    
    // Para tres digitos
    else if(n > 100 && n < 1000)
    {
        d1 = n/100;
        d2 = (n/10) - (10*d1);
        d3 = n - ((100*d1) + (10*d2));
        
        return produto = d1 * d2 * d3;
    }
    
    // Para quatro digitos
    else if (n > 1000 && n < 10000)
    {
        d1 = n/1000;
        d2 = (n/100) - (10*d1);
        d3 = (n/10) - ((100*d1) + (10*d2));
        d4 = n - ((1000*d1) + (100*d2) + (10*d3));
        
        return produto = d1 * d2 * d3 * d4;
    }
    
    // Para cinco digitos
    else
    {
        d1 = n/10000;
        d2 = (n/1000) - (10*d1);
        d3 = (n/100) - ((100*d1) + (10*d2));
        d4 = (n/10) - ((1000*d1) + (100*d2) + (10*d3));
        d5 = n - ((10000*d1) + (1000*d2) + (100*d3) + (10*d4));
        
        return produto = d1 * d2 * d3 * d4 * d5;
    }
}

/*
    Funcao para encontrar o menor numero para o problema.
*/
int menorNumero(long int n)
{
    long int i, resultado;
    

    // Se o 'n' for primo, entao nao existe multiplos possiveis
    if (verificarPrimo(n) == 1)
    {
        return resultado = -1;
    }
    
    // Percorrendo todos os numeros ate 9 999 ou quando tiver resultado.
    for (i = (n + 1); i < 100000; ++i)
    {
        // Quebrando o numero i em digitos
        resultado = separarDigitos(i);
        
        if (resultado == n)
        {
            return i;
        }
    }
    
    // Se nao houve resultado no for, entao nao exite para o intervalo.
    return resultado = -1;
}

int main() 
{
    long int numero, resultado;
    
    // Entrada
    scanf("%ld", &numero);
    
    /*
        Entrada deve ser 9 < N < 100000
    */
    if (numero > 9 && numero < 100000)
    {
        // Resultado sera dado pelo retorno da funcao
        resultado = menorNumero(numero);
        printf("%ld\n", resultado);
    }
    else
    {
        resultado = -1;
        printf("%ld\n", resultado);
    }
    
	return 0;
}