/*
Descrição:
Escreva uma função chamada SomaDigitos que receba como entrada um número inteiro e retorne a soma de seus dígitos.
Ex: Se a entrada for 521, a saída será 8 (5 + 2 + 1)

Formato de entrada:
Um número inteiro

Formato de saída:
Um número inteiro
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para somar os digitos de qualquer numero inteiro 'n'
    O numero 'n' tera os seus digitos separados a partir da casa
    das unidades ate que a ultima separacao produza um numero igual a 
    zero.

    Variaveis:
        soma : Soma os digitos obtidos
        n: Parte inteira do quociente
        qct: Quociente da divisao por uma potencia de 10
        dig: Digito obtido que eh < 1
*/
double somaDigitos(long int n)
{
    double qct, dig, soma;
    
    // Valor inicial
    soma = 0;
    dig  = 0;
    qct  =(double)n;
    
    // Enquanto o numero 'n' for maior ou igual a zero
    while(n >= 1)
    {
        /*
            'n' sera divido por 10 a cada loop em dois resultados:
            todo quociente: qct
            parte inteira: n
        */
        qct = qct/10;
        n   = (long int)qct;
 
        // Obtendo o digito que eh < 1
        dig = (qct - n);
        
        // Fazendo a soma dos digitos
        soma = soma + (dig*10);
        
        // Retirando o digito encontrado do quociente atual
        qct = qct - dig;
    }
    
    return soma;
}

int main() 
{
    // Variaveis
    long int numero;
    double resultado;
    
    // Entrada do inteiro
    scanf("%ld", &numero);
    
    // Chamando a funcao somaDigitos()
    resultado = somaDigitos(numero);
    
    printf("%0.lf\n", resultado);
    
	return 0;
}