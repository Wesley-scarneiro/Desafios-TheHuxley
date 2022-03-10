/*
Descrição:
Devido ao grande número de acidentes ocorridos recentemente na rua principal da cidade, um sistema de radares será instalado para multar os condutores que excederem os 50 km/h permitidos. Aqueles que excederem a velocidade, mas estiverem no máximo 10% acima da velocidade limite serão multados em R$ 230. Já os condutores que excederem a velocidade permitida em até 20% serão multados em R$ 340. Caso a velocidade do motorista exceda o limite em mais de 20%, ele terá que pagar uma multa de R$ 19,28 por cada km excedido.
Escreva uma função chamada CalculaMulta que receba como entrada a velocidade de um condutor e retorne o valor da multa que ele terá que pagar.

Formato de entrada:
Um valor inteiro

Formato de saída:
Um valor real
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Velocidade maxima permitida
float VMAX = 50;

/*
    Funcao para calcular a multa, dado a velocidade do condutor.
*/
double calcularMulta(int v)
{
    double total = 0;
    
    // ate 10% acima do limite
    if (v > VMAX && v <= (1.10*VMAX))
    {
        return total = 230;
    }
    
    // ate 20% acima do limite
    if (v > (1.10*VMAX) && v <= (1.20*VMAX))
    {
        return total = 340;
    }
    
    // acima de 20% do limite
    if (v > (1.20*VMAX))
    {
        return total = (v - VMAX) * 19.28;
    }
    
    // Se chegou ate aqui, eh pq a velocidade eh menor que o limite.
    return total;
    
}

int main() 
{
    // Variaveis
    int velocidade;
    double multa;
    
    // Entrada
    scanf("%d", &velocidade);
    
    multa = calcularMulta(velocidade);
    
    printf("%.2lf\n", multa);
    
    return 0;
}