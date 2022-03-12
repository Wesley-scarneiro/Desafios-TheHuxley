/*
Descrição:
Você possui um colar com N (3<=N<=350) pedras vermelhas (r), azuis (b) ou brancas(w). As pedras estão organizadas randomicamente no colar. As figura abaixo mostram dois exemplos de colares com N=29:
A primeira e a segunda pedra foram marcadas na figura com os números 1 e 2 respectivamente. A configuração da figura 1 pode ser representada como uma  string de b’s e r’s, onde b representa uma pedra azul e r representa uma pedra vermelha:
brbrrrbbbrrrrrbrrbbrbbbbrrrrb
Suponha que você quebrará o colar em algum ponto, esticará ele em uma linha reta e então coletará as pedras da mesma cor de um lado até você encontrar uma pedra de uma cor diferente. Você fará o mesmo para o outro lado. As pedras coletadas de um lado não precisam ser, necessariamente, da mesma cor das pedras coletadas no outro lado.
O seu objetivo é determinar o ponto onde o colar deve ser quebrado de tal forma a coletar o maior número de pedras e imprimir esse valor do maior número de pedras.
Exemplo:
No colar da figura 1, 8 pedras podem ser coletadas se nós quebrarmos o colar entre as pedras 9 e 10 ou entre as pedras 24 e 25.
Em alguns colares pedras brancas estão incluídas, como mostrado na figura 2. Ao coletar as pedras, uma pedra branca pode ser tratada tanto como azul quanto como vermelha. Sendo assim, uma string que representa um colar poderá conter 03 símbolos: r, w e b.

Formato de entrada:
Linha 1: N, correspondendo a um inteiro indicando o número de pedras do colar.
Linha 2: uma string de N caracteres, onde cada um pode ser r, w, ou b.

Formato de saída
Uma linha contendo o número máximo de pedras que podem ser coletadas.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para receber duas referencias e alterar o valor de 'resultado' caso seja um valor menor.
*/
void verificarMaior(int *contagem, int *resultado)
{
    if (*contagem > *resultado)
    {
        *resultado = *contagem;
    }

    *contagem = 0;
}

/*
    Funcao que verifica o elemento sucessor/antecessor da posicao 'i' em uma string
    O antecessor de '0' eh 'n - 1'
*/
void antecessorDeI(int n, int i, int *h)
{
    if (i - 1 >= 0)
    {
        *h = i - 1;
    }
    else
    {
        *h = n - 1;
    }
}

/*
    Funcao que conta as pedras que nao comecao com brancas na direita.
    Realizada uma segunda contagem quando retorna a '0'.
*/
void contarDireita(int n, char colar[], int i, int *u, int *t)
{
    /*
        p: Cada posicao da string
        parar: Ponto de parada para a segunda passagem
    */
    int p, parar;

    p = i;

    // Primeira passagem
    while (colar[p] == colar[i] || colar[p] == 'w')
    {
        ++(*t);

        if ((p == n - 1 && i != 0) && (colar[0] == colar[i] || colar[0] == 'w'))
        {
            parar = i - 1;
            p = 0;
            break;
        }
        else if (p == n - 1)
        {
            *u = p;
            return;
        }
        ++p;
    }

    // Segunda passagem
    while (colar[p] == colar[i] || colar[p] == 'w')
    {
        ++(*t);
        
        if (p == parar)
        {
            *u = p;
            return;
        }
        ++p;
    }

    --p;
    *u = p;
}

/*
    Funcao que conta as pedras que nao comecam com brancas na esquerda.
*/
void contarEsquerda(int n, char colar[], int h, int u, int *t)
{
    int p;

    p = h;
    
    // Primeira passagem
    while ((colar[p] == colar[h] || colar[p] == 'w') && p != u)
    {
        ++(*t);

        if (p == 0 && (colar[n-1] == colar[h] || colar[n-1] == 'w'))
        {
            p = n - 1;
            break;
        }
        else if (p == 0)
        {
            return;
        }
        --p;
    }

    // Segunda passagem
    while ((colar[p] == colar[h] || colar[p] == 'w') && p != u)
    {
        ++(*t);
        --p;
    }
}

/*
    Funcao que conta as pedras que comecam com brancas na direita
*/
void brancaDireita(int n, char colar[], int i, int *u, int *t)
{
    int p, mudou, parar;
    char cor = 'w';

    mudou = 0;

    for (p = i; colar[p] == colar[i] || colar[p] == cor; ++p)
    {
        ++(*t);

        if (colar[p+1] != cor && mudou == 0)
        {
            cor = colar[p+1];
            mudou = 1;
        }

        if (p == n- 1 && i != 0)
        {
            if (colar[0] == colar[i] || colar[0] == cor)
            {
                parar = i - 1;
                p = 0;
                break; 
            }
            else if (mudou == 0)
            {
                cor = colar[0];
                mudou = 1;
                parar = i - 1;
                p = 0;
                break;
            }
            else
            {
                *u = p;
                return;
            }
        }
        else if (p == n - 1)
        {
            *u = p;
            return;
        }
    }

   if (colar[p] != cor)
    {
        --p;
        *u = p;
        return;
    } 

    // Segunda passagem
    while (colar[p] == colar[i] || colar[p] == cor)
    {
        ++(*t);

        if (colar[p+1] != cor && mudou == 0)
        {
            cor = colar[p+1];
            mudou = 1;
        }

        if (p == parar)
        {
            *u = p;
            break;
        }
        ++p;
    }

    --p;
    *u = p;

}

void brancaEsquerda(int n, char colar[], int h, int u, int *t) // INCOMPLETA
{
    int p, mudou;
    char cor = 'w';

    mudou = 0;

    for (p = h; (colar[p] == colar[h] || colar[p] == cor) && p != u; --p)
    {
        ++(*t);

        if (colar[p-1] != cor && mudou == 0)
        {
            cor = colar[p-1];
            mudou = 1;
        }

        if (p == 0 && h != n-1)
        {
            if (colar[n-1] == colar[h] || colar[n-1] == cor)
            {
                p = n - 1;
                break;
            }
            else if (mudou == 0)
            {
                cor = colar[n-1];
                mudou = 1;
                p = n - 1;
                break;
            }
            else
            {
                return;
            }
        }
        else if (p == 0)
        {
            return;
        }
    }

    while ((colar[p] == colar[h] || colar[p] == cor) && p != u)
    {
        ++(*t);

        if (colar[p-1] != cor && mudou == 0)
        {
            cor = colar[p-1];
            mudou = 1;
        } 
        --p;
    }
}

/*
    Funcao que percorre a string 'colar' em cada posicao 'i'
    realizando as contagens necessaria, atraves de outras
    funcoes auxiliares.
*/
void contarPedras(int n, char colar[], int *resultado)
{
    /*
        i: Cada posicao da string
        h: Antecessor de 'i'
        t: Contagem das pedras em cada quebra
        u: Posicao de parada na primeira contagem direita
    */
    int i, h, t, u;

    t = 0;

    // Percorrendo a string
    for (i = 0; i < n; ++i)
    {
        // Comecam com vermelhas ou azuis
        if (colar[i] != 'w')
        {
            /* Contagem da direita */
            contarDireita(n, colar, i, &u, &t);
            
            // Se t retornar o tamanho da string
            if (t == n)
            {
                verificarMaior(&t, resultado);
                return;
            }

            /* Contagem da esquerda */
            antecessorDeI(n, i, &h);

            // Vermelha ou azul
            if (colar[h] != 'w')
            {
                contarEsquerda(n, colar, h, u, &t);
            }

            // Branca
            else
            {
                brancaEsquerda(n, colar, h, u, &t);
            }
        }

        // Comeca com branca
        else
        {
            /*  Contagem da direita  */
            brancaDireita(n, colar, i, &u, &t);

            // Se 't' retornar o tamanho da string
            if (t == n)
            {
                verificarMaior(&t, resultado);
                return;
            }

            /*  Contagem da esquerda */
            antecessorDeI(n, i, &h);

            // Vermelha ou azul
            if (colar[h] != 'w')
            {
                contarEsquerda(n, colar, h, u, &t);
            }

            // Branca
            else
            {
                brancaEsquerda(n, colar, h, u, &t);
            }
        }

        // Verificar contagem de 't' com 'resultado'
        verificarMaior(&t, resultado);
    }
}


int main() 
{
    // Tamanho da string e resultado da maior contagem
    int n, resultado;

    // Serah interado na funcao
    resultado = 0;

    // Entrada de 'n' e da string
    scanf("%d\n", &n);
    char colar[n];
    gets(colar);

    // Funcao
    contarPedras(n, colar, &resultado);
    printf("%d\n", resultado);

    return 0;
}