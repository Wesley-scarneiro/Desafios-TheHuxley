/*
Descrição:
A Escola de Música Melodia é bastante conceituada na cidade e forma grandes profissionais. Para isso, exige que seus alunos tenham no máximo 10 faltas por semestre, e que obtenham média mínima 7 para serem aprovados. Aqueles que não excedem o limite de faltas e conseguem média igual ou superior a 9,5 são aprovados com louvor.
Escreva uma função chamada ClassificaAluno que receba como entrada a media e a quantidade de faltas de um aluno e retorne sua situação ao final do semestre.

Formato de entrada:
Um número real e um número inteiro, nessa ordem

Formato de saída:
Um String em letras maiúsculas (APROVADO COM LOUVOR ou APROVADO ou REPROVADO ou REPROVADO POR FALTAS)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Funcao para classificar um aluno com base em sua media e numero de faltas
void classificaAluno(float media, int faltas)
{
    // Aprovado com louvor
    if (media >= 9.5 && faltas <= 10)
    {
        printf("APROVADO COM LOUVOR\n");
    }
    
    // Aprovado
    else if (media >= 7 && faltas <= 10)
    {
        printf("APROVADO\n");
    }
    
    // Reprovado por faltas
    else if (faltas > 10)
    {
        printf("REPROVADO POR FALTAS\n");
    }
    
    // reprovado por notas
    else
    {
        printf("REPROVADO\n");
    }
}

int main() 
{
    // Variaveis
    float media;
    int faltas;
    
    // Entrada
    scanf("%f %d", &media, &faltas);
    
    //  Chamar a funcao
    classificaAluno(media, faltas);
    
    return 0;
}
