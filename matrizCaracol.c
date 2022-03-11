/*
Descrição:
Ambrosino, um programador aposentado, começou a criar caracois. Mas não são caracóis comuns, eles vieram de um planeta distante onde os caracois sabem  falar e ler. Entretanto, Ambrosino começou a perceber que os caracois estão exibindo um comportamento muito estranho. Eles estão andando em um movimento espiral. Rapidamente, ele se lembrou dos primeiros algoritmos para percorrer matrizes. Normalmente o seu professor de programação mostrava como percorrer uma matriz horizontalmente (linha por linha) ou verticalmente (coluna por coluna). Então ele pensou, e se eu quiser percorrer a matriz da mesma maneira que os caracóis estão andando?
Você irá receber a dimensão e depois os números inteiros de uma matriz quadrada como entrada. Mas os números serão dados na ordem do "caminho de caracol". As figuras abaixo mostram como seria esse caminho. Sua missão é receber essa matriz e depois imprimir linha por linha.
No primeiro caso, na matriz 2X2, você receberá
2
8
5
3
7
e deve imprimir:
8
7
5
3
Já na matriz 4x4 você receberá:
4
3
1
6
12
14
30
20
15
77
76
56
34
2
8
9
65
e deve imprimir:
3
34
56
76
1
2
65
77
6
8
9
15
12
14
30
20

Formato de entrada:
Consiste de um número n representando a dimensão de uma matriz n X n. Depois, serão dados os n*n números inteiros de acordo com o "caminho de caracol".

Formato de saída:
Imprima a matriz, linha por linha, da esquerda para a direita, um número por linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Esboço de solução.
*/

int main() 
{
    // Tamanho da matriz quadrada
    int n;
    
    // Entrada do tamanho da matriz
    scanf("%d", &n);
    
    if (n == 1)
    {
        scanf("%d", &n);
        printf("%d\n", n);
    }
    else
    {
    // Criando a matriz
    int matriz[n][n];

    // Variaveis para percorrer a matriz de forma esperiral
    int i, j, t, limB, limD, limC, limE;
    
    i = 0;
    j = 0;
    t = 0;
    limB = n - 2;
    limD = n - 2;
    limC = 1;
    limE = 1;

    while (t < n*n)
    {
        while (i <= limB)
        {
            scanf("%d", &matriz[i][j]);
            ++i;
            ++t;
        }
        --limB;
        
        while (j <= limD)
        {
            scanf("%d", &matriz[i][j]);
            ++j;
            ++t;
        }
        --limD;
        
        while (i >= limC)
        {
            scanf("%d", &matriz[i][j]);
            --i;
            ++t;
        }
        ++limC;
        
        while (j >= limE)
        {
            scanf("%d", &matriz[i][j]);
            --j;
            ++t;
        }
        ++limE;
        ++j;
        ++i;
        
        // Para matrizes de tamanho impar
        if (t == ((n*n)-1) && n % 2 != 0)
        {
            scanf("%d", &matriz[i][j]);
        	++t;
		}
    }
    
        // Imprimindo matriz
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
              printf("%d\n", matriz[i][j]);
            }
        }
    }
    
    return 0;
}