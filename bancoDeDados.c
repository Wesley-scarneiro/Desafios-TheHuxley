/*
Descrição:
A empresa WOOF está entrando no mercado das redes sociais. Só que ela precisa de um banco de dados para armazenar os dados dos seus usuários.
O dono da empresa é muito amigo seu, e sabe que você é um ótimo programador, logo, te chamou para implementar esse banco de dados.
As informações dos usuários que você deve guardar são:
Idade.
Nome.
Sexo.
Estado civil.
Quantidade de amigos.
Quantidade de fotos.

Formato de entrada:
Você vai receber os dados do usuário:
Um inteiro, representando a quantidade de usuários a serem adicionados ao banco de dados.
Um inteiro, contendo a idade.
Uma string, de até 50 caracteres, contendo o nome.
Um caractere, sendo ele M ou F, que é o sexo.
Uma caractere, simbolizando o estado cívil:
 S - Solteiro, C - Casado. N - Namorando. D - Divorciado.
Um inteiro, representando o número de amigos.
Um inteiro, representando a quantidade de fotos que estão no perfil.

Formato de saída:
Imprimir as informações de todos os usuários, na sequencia em que eles foram adicionados, uma por linha.
Deve haver uma quebra de linha entre os casos de testes e ao fim do programa.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define T 100

/*
    Estrutura de dados de um usuario.
    Uso do typedef para nomear a struct.
*/
typedef struct
{
    int idade;
    char nome[100];
    char sexo;
    char estado_civil;
    int amigos;
    int fotos;
}USUARIOS;

/*
    Funcao para cadastrar usuarios.
    Uso do gets(), pois as entradas sao controladas.
*/
void cadastrar_usuarios(USUARIOS *usuario)
{
    // Idade
    scanf("%d", &usuario->idade);
    getchar();
    
    // Nome
    gets(usuario->nome);
    
    // Sexo
    scanf("%c", &usuario->sexo);
    getchar();
    
    // Estado civil
    scanf("%c", &usuario->estado_civil);
    getchar();
    
    // Numero de amigos
    scanf("%d", &usuario->amigos);
    
    // Numero de fotos
    scanf("%d", &usuario->fotos);
}

/*
    Funcao que imprime os registros de um usuario.
*/
void imprimir_usuario(USUARIOS usuario)
{
    printf("Idade: %d\n", usuario.idade);
    printf("Nome: %s\n", usuario.nome);
    printf("Sexo: %c\n", usuario.sexo);
    printf("Estado Civil: %c\n", usuario.estado_civil);
    printf("Numero de amigos: %d\n", usuario.amigos);
    printf("Numero de fotos: %d\n\n", usuario.fotos);
}

int main() 
{
    /*
        VARIAVEIS
        usuarios : Registros de USUARIOS
        i, n     : Quantidade de usuarios
    */
    USUARIOS usuarios[T];
    int i, n;
    
    // Entrade de 'n'
    scanf("%d", &n);
        
    // Recebendo os registros
    for (i = 0; i < n; ++i)
    {
        cadastrar_usuarios(&usuarios[i]);
        imprimir_usuario(usuarios[i]);
    }
    
    return 0;
}