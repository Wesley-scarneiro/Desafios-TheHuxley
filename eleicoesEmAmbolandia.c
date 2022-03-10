/*
Descrição:
Escreva um programa que transforme o computador numa urna eletrônica para eleição, em segundo turno, para presidente de um país chamado Ambrolândia. Nessas eleições concorrem os candidatos 83-Alibabá e 93-Alcapone. Cada voto deve ser dado pelo número do candidato, permitindo-se ainda o voto 0 para voto em branco. Qualquer voto diferente dos já citados é considerado nulo. No final da eleição o programa deve emitir um relatório contendo a votação de cada candidato, a quantidade votos em branco, a quantidade de votos nulos e o candidato eleito e os respectivos percentuais.
Em Ambrolândia, o percentual de votos é calculado considerando os votos válidos. O voto nulo não é considerado um voto válido. Entretanto, o voto em branco é considerado um voto válido.

Formato de entrada:
A entrada consiste de um conjunto de números inteiros, um por linha. A eleição termina quando o número digitado é -1.
O número de inteiros dados é maior que um e menor que cem milhões.
Considere também que cada candidato tem pelo menos um voto.

Formato de saída:
A saída consiste de um relatório impresso no seguinte formato:
x
y
z
w
k
a
b

Onde, x é quantidade de votos do candidato Alibabá, y a quantidade de votos do candidato Alcapone, z a quantidade de votos em branco, w a quantidade de votos nulos, k é o número 83 ou 93 indicando qual foi o candidato vencedor, a é o percentual de votos do candidato Alibabá e b é o percentual de votos do candidato Alcapone.
O percentual de votos deve ser impresso com duas casas decimais e sem o sinal de porcentagem. Exemplo, para representar trinta e quatro ponto vinte e cinco porcento você deve imprimir: 34.25
Considere também que sempre haverá um candidato vencedor, ou seja, nunca haverá um empate.
*/

#include <stdio.h>

/*
    Funcao para verificar o vencedor da eleicao.
*/
void funcaoVencedor(int votoA, int votoB, int votoBranco, int votoNulo, int total)
{
	double pVotoA, pVotoB;
	
	// Alibaba venceu
	if (votoA > votoB)
	{
		int ganhador = 83;
		
		// Porcentagem de Alibaba e Alcapone
		pVotoA = ((double)votoA/total) * 100;
		pVotoB = ((double)votoB/total) * 100;
		
		// Imprimindo resultados
		printf("%d\n%d\n%d\n%d\n", votoA, votoB, votoBranco, votoNulo);	
		printf("%d\n%.2lf\n%.2lf\n", ganhador, pVotoA, pVotoB);
	}
	// Alcapone ganhou
	else
	{
		int ganhador = 93;
		
		// Porcentagem de Alibaba e Alcapone
		pVotoA = ((double)votoA/total) * 100;
		pVotoB = ((double)votoB/total) * 100;
		
		// Imprimindo resultados
		printf("%d\n%d\n%d\n%d\n", votoA, votoB, votoBranco, votoNulo);	
		printf("%d\n%.2lf\n%.2lf\n", ganhador, pVotoA, pVotoB);
	}
}

int main() 
{
    // Variaveis
    int entrada, votoA, votoB, votoBranco, votoNulo, total;
    
    // Entrada
    scanf("%d", &entrada);
    
    // Valores inicias
    votoA = 0;
    votoB = 0;
    votoBranco = 0;
    votoNulo = 0;
    
    // Realiza a contagem de votos e calcula o total
    for (total = 0; entrada != -1; total = votoA + votoB + votoBranco)
    {
        // Se o voto for para o Alibaba
        if (entrada == 83)
        {
        	++votoA;
		}
		// Se for para o Alcapone
		else if (entrada == 93)
		{
			++votoB;
		}
		// Se for em branco
		else if (entrada == 0)
		{
			++votoBranco;
		}
		// Se for nulo
		else
		{
			++votoNulo;
		}
		
		// Nova entrada
		scanf("%d", &entrada);
    }
    
    // VERIFICANDO O VENCEDOR
    funcaoVencedor(votoA, votoB, votoBranco, votoNulo, total);

    return 0;
}
