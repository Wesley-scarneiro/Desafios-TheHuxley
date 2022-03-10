/*
Descrição:
A ampulheta é um dos instrumento de medição de tempo mais antigos da humanidade. É constituída por duas âmbulas iguais (recipientes que contem areia), por duas hastes que as suportam e areia. A areia dentro da ampulheta deve preencher uma âmbula por completo e deixar a outra totalmente vazia. Seu programa deve imprimir na tela uma ampulheta com âmbulas triângulares de lado l e seus respectivos níveis de areia, superior e inferior.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/*
    Imprime uma ampulheta de caracteres de acordo com as condicoes dadas.
*/
void imprimirAmpulheta(int lado, int NAS, int NAI)
{
    int i, j;
    
    // Ampulheta superior
    for (i = lado-1; i >= 0; --i)
    {
        printf("*");
        // O segundo for controla o preenchimento das linhas
        for (j = 1; j <= (2*lado) - 1; ++j)
        {
            // Colocacao do cume
            if (i == 0 && j == lado - i)
            {
                printf("*");
            }
            
            // Colocacao das 2* laterais
            else if (j == (lado-i) || j == (lado+i))
            {
                printf("*");
            }
            
            // Colocacao da base
            else if ((i+1 == lado) && (j % 2 != 0))
            {
                printf("*");
            }
            
            // Prenchimento com areia
            else if ((NAS != 0 && i <= NAS) && (j > lado-i && j < lado+i))
            {
                printf(".");
            }
            // Espacos vazios
            else
            {
                printf(" ");
            }
        }
        
        // Quebra de linha
        printf("*\n");
    }
    
    // Ampulheta inferior
    for (i = 0; i < lado; ++i)
    {
        printf("*");
        // O segundo for controla o preenchimento das linhas
        for (j = 1; j <= (2*lado) - 1; ++j)
        {
            // Colocacao do cume
            if (i == 0 && j == lado - i)
            {
                printf("*");
            }
            
            // Colocacao das 2* laterais
            else if (j == (lado-i) || j == (lado+i))
            {
                printf("*");
            }
            
            // Colocacao da base
            else if ((i+1 == lado) && (j % 2 != 0))
            {
                printf("*");
            }
            
            // Prenchimento com areia
            else if ((NAI != 0 && (i >=(lado-(1+NAI)) && i != lado-1)) && (j > lado-i && j < lado+i))
            {
                printf(".");
            }            
            
            // Espacos vazios
            else
            {
                printf(" ");
            }
        }
        
        // Quebra de linha
        printf("*\n");
    }
}


int main() 
{
    /*
        COLOCACAO DO CUME(if)
	    se i == 0  E j == lado - i

        COLOCACAO DAS 2*(else if)
	    se j == lado-i OU j == lado+i

        COLOCACAO DA BASE(else if)
	    se (i+1) == lado E j % 2 != 0

        COLOCACAO DOS ESPACOS(else)
	    Se todas as condicoes anteriores forem falsas!
    */
    
    // Variaveis
    int casos, lado, NMA, NAS, NAI, i;
    
    // Primeira entrada - Quantidade de casos a ser calculada.
    scanf("%d", &casos);
    
    
    // Enquanto a quantidade de casos for != 0
    for (i = 1; i <= casos; ++i)
    {
        // Segunda entrada - Lado e NAI
        scanf("%d %d", &lado, &NAI);
        
        // Condicoes para o atual caso
        NMA = lado - 2;
        NAS = NMA - NAI;
        
        printf("Caso %d:\n", i);
        
        // Chamando a funcao
        imprimirAmpulheta(lado, NAS, NAI);
    }
    
	return 0;
}

/*
Saida:

Caso 1:
** * * * **
* *     * *
*  *   *  *
*   *.*   *
*    *    *
*    *    *
*   * *   *
*  *...*  *
* *.....* *
** * * * **
Caso 2:
** * * * * * * * * **
* *               * *
*  *             *  *
*   *           *   *
*    *         *    *
*     *       *     *
*      *     *      *
*       *   *       *
*        *.*        *
*         *         *
*         *         *
*        * *        *
*       *...*       *
*      *.....*      *
*     *.......*     *
*    *.........*    *
*   *...........*   *
*  *.............*  *
* *...............* *
** * * * * * * * * **
Caso 3:
** * * * * **
* *       * *
*  *     *  *
*   *   *   *
*    *.*    *
*     *     *
*     *     *
*    * *    *
*   *...*   *
*  *.....*  *
* *.......* *
** * * * * **
*/