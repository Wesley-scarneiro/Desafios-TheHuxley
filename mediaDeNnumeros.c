/*
Descrição:
Faça um programa que calcule a média, o desvio padrão e a quantidade de números maiores que a média de n números reais dados. O número máximo de números dados é 10000.

Formato de entrada:
Uma sequência de n, onde n<=10000, números reais separados por um final de linha. A entrada se encerra quando o número lido for -1

Formato de saída:
A média formatada com duas casas decimais.
O desvio padrão formatado com duas casas decimais
Um inteiro indicando a quantidade de notas maiores que a média.
Cada um dos três números acimas deve ser seguido de um final de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para calcular o desvio padrao.
*/
double desvioPadrao(double array[], double media)
{
    int i;
    double somatorio, resultado;
    somatorio = 0;
    
    for (i = 0; array[i] != -1; ++i)
    {
        // Soma dos desvios
        somatorio = somatorio + pow((array[i] - media), 2);
    }
    
    return resultado = sqrt((somatorio/(i-1)));
}

/*
    Funcao para percorrer o array e contar quantos numeros sao maiores que a media.
*/
int maioresMedia(double array[], double media)
{
    int i, contador;
    contador = 0;
    
    for (i = 0; array[i] != -1; ++i)
    {
        if (array[i] > media)
        {
            ++contador;
        }
    }
    
    return contador;
}

int main() 
{
    // Variaveis
    int i, maiorMedia;
    double array[10000], somatorio, media, desvPadrao;
    
    somatorio = 0;
    media = 0;
    
    // Recebendo os numeros
    for (i = 0; i < 10000; ++i)
    {
        scanf("%lf", &array[i]);
        
        if (array[i] == -1)
        {
            break;
        }
        
        // Para a media
        somatorio = somatorio + array[i];
    }
    
    // Chamar funcao para media
    media = somatorio/i;
    printf("%.2lf\n", media);
    
    // Chamar funcao para o desvio padrao
    desvPadrao = desvioPadrao(array, media);
    printf("%.2lf\n", desvPadrao);
    
    // Chamar funcao para maiores que a media
    maiorMedia = maioresMedia(array, media);
    printf("%d\n", maiorMedia);
    
    return 0;
}