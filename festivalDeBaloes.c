/*
Descrição:
O Festival Internacional de Balonismo de Albuquerque é um grande evento para o estado do Novo México.
Turistas de diversos cantos do mundo vão para competir, se exibir, ou apenas apreciar tal evento.
Nesse festival, há também os balões de passeio, onde os turistas podem fazer uma curta viagem e admirar a paisagem local.
Porém, esse ano, os balonistas que acompanham os turistas entraram em greve. E para não ter prejuizo, o dono de alguns balões, que é seu amigo, lembrou que você sabe programar.
E pediu para você criar um programa que automatizasse os balões, para que ele voasse sem a necessidade de um balonista profissional ao lado, com os proprios turistas o controlando.
Ele quer que o balão tenha os seguintes comandos:
Subir.
Frente.
Dar a volta.
Descer.
Para todos os comandos, o balão se movimenta 10 metros:
Subir: 10 metros para cima.
Frente: 10 metros no sentido atual.
Descer: 10 metros para baixo.
Dar a volta: 10 metros no sentido atual e depois inverte o sentido.
Porém, ele te advertiu das condições de segurança:
O balão não pode ultrapassar 200 metros de altura.
Não pode se afastar mais de 2 km do local inicial.
Então, você escreveu o seguinte programa:
Subir: S
Frente: F
Dar a volta: V
Descer: D
Dado N comandos, descubra a que altura (distância do chão)  e a que distância (distância HORIZONTAL à inicial) o balão se encontra do ponto de partida.

Formato de entrada:
Um inteiro N, representando a quantidade de comandos operados no balão.
N linhas de caracteres, que podem ser: S (subir), F (frente), V (dar a volta), D (descer).

Formato de saída:
Altura (distância do chão) e distância (distância HORIZONTAL à inicial) que o balão se encontra do ponto de partida.
Seguido de uma quebra de linha.
Obs: Se o balão estiver no chão, e tentar descer, ele nem se mexe.
Obs2: Se o balão chegar nas distancias de segurança, ele não consegue burlar, ou seja, chegar na distancia máxima e ir pra frente, ele não irá se mover, o mesmo serve para a altura.
Obs3: Se o balão estiver no chão, ele não pode ir pra frente e nem dar a volta.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /*
        dvf: distancia vertical final
        dhf: distancia horizontal final
        sentido : 0 para esquerda e 1 para direita
        ncomandos: quantidade de comandos que ser?o dados
    */
    int dvf, dhf, sentido, ncomandos, i;
    char entrada;
    
    // Posicao inicial do balao - (dv, dh) = (0,0)
    dvf = 0;
    dhf = 0;
    sentido = 1;
    
    // Primeira entrada
    scanf("%d", &ncomandos);
    
    for (;ncomandos > 0; --ncomandos)
    {
        // Nova entrada
        scanf("\n%c", &entrada);
        
        // Comando para subir
        if (dvf != 200 && entrada == 'S')
        {
                dvf += 10;
        }
        
        // comando para descer - Nao pode estar no chao
        if (dvf != 0 && entrada == 'D')
        {
            dvf -= 10;
        }
        
        // Comando para ir para frente no sentido atual
        if (dvf != 0 && entrada == 'F')
        {
            // Para direita
            if (sentido == 1)
            {
                if (dhf != 2000)
                {
                    dhf += 10;
                }
            }
            // Para esquerda
            else
            {
                if (dhf != 0)
                {
                    dhf -= 10; // Se o sentido < 0, havera soma
                }
                else
                {
                    dhf += 10;
                    sentido = 1;
                }
            }
            
        }
        
        // Comando para dar volta - +10 e altera o sentido
        if (dvf != 0 && entrada == 'V')
        {
            
            if (sentido == 1)
            {
                dhf += 10;
                sentido = 0;
            }
            else
            {
                dhf -= 10;
                sentido = 1;
            }
        }
    }

    printf("%d %d\n", dvf, dhf);

	return 0;
}