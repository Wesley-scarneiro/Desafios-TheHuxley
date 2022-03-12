/*
Descrição:
Você é um aluno de computação e a época de matrícula na sua universidade se aproxima. O núcleo de tecnologia da informação já começa a se agitar para preparar os sistemas para a matrícula. Porém, eles perceberam que não irão ficar com o sistema pronto a tempo e resolveram pedir a sua ajuda. Sua missão é fazer uma parte do sistema de matrícula e enviar o código para ele.
Use esse exercício para praticar o conceito de tipos de dados compostos. Ou seja, se a sua linguagem for:
C, utilize structs;
Python, utilize classes ou "named tuples";
Java, utilize "inner classes";
Pascal, utilize "record";
Matlab, adicione campos a variváveis ou use uma estrutura escalar (http://bit.ly/18OE2bc)
caso não seja nenhuma das opções acima, procure a forma mais apropriada na sua linguagem.

Formato de entrada:
Você vai receber uma lista com o cadastro de vários alunos. Inicialmente você receberá um número inteiro n indicando quantos alunos você receberá. Cada aluno contém os seguintes dados, sendo um por linha:
Código do aluno (até 30 caracteres);
nome completo do aluno (até 500 caracteres);
idade;
sexo (0 para feminino, 1 para masculino);
nota do enem (0 a 10).
Depois você receberá um número m indicando a quantidade de disciplinas que se seguirão. Cada disciplina possui o seguinte formato:
Código da disciplina (até 25 caracteres);
nome da disciplina (até 100 caracteres);
Na sequência, você irá receber um número p indicando uma sequência de matrículas de alunos em disciplinas. Cada matrícula será dada em uma linha, e cada linha contém 2 códigos, separados por um espaço em branco. O primeiro código representa o código do aluno e o segundo o código da disciplina e significa que o aluno solicitou matrícula naquela disciplina.

Formato de saída:
Você deve imprimir um relatório contendo as seguintes linhas:
Quantidade de alunos do sexo masculino;
Quantidade de alunos do sexo feminino;
Média das idades dos alunos, formatado com duas casas decimais;
Média das idades dos alunos que tiraram nota maior que 7.5 no enem, formatado com duas casas decimais;
Para cada disciplina, ordenadas em ordem alfabética, imprimir o nome da disciplina, a quantidade de alunos matriculados nela e os nomes dos alunos que se matricularam nela, também em ordem alfabética, sendo um por linha. Se não houverem alunos matriculados, simplesmente não imprima nenhum aluno.
*/

#include <stdio.h>
#include <string.h>

// Limites para os arranjos
#define T 50 // Quantidade de alunos
#define D 20 // Quantidade de disciplinas
#define NOTA 7.5 // Nota do ENEM considerada na mediaIdadesNotas

/*
    Estrutura que contem as variaveis de uma disciplina.
*/
typedef struct estruturaDisciplinas
{
    char codigo[25];
    char nome[100];
    int matriculados;
}DISCIPLINAS;

/*
    Estrutura que contem as variaveis de um aluno.
*/
typedef struct estruturaAlunos
{
    char codigo[30];
    char nome[500];
    int idade;
    int sexo;
    double nota;
    DISCIPLINAS *disciplinas[D]; // Disciplinas em que o aluno esta matriculado
    int numDisciplinas; // Quantidade de disciplinas que o aluno possui
}ALUNOS;

/*
    Estrutura que representa a lista de ALUNOS e DISCIPLINAS
*/
typedef struct estruturaListas
{
    ALUNOS alunos[T];
    int numAlunos;
    int numMatriculas;
    DISCIPLINAS disciplinas[D];
    int numDisciplinas;
}LISTAS;

/*
    Lista para registrar os resultados do problema.
*/
typedef struct estruturaResultados
{
    int sexoM;
    int sexoF;
    double somaIdades;
    double somaIdadesNotas;
    int numAlunosNotas;
    double mediaIdades;
    double mediaIdadesNotas;
}RESULTADOS;

/*
    Funcao que inicializa as variaveis de um aluno.
    Inicializa o 'numDiscplinas'.
*/
void inicializarAluno(ALUNOS *aluno)
{
    aluno->numDisciplinas = 0;
}

/*
    Funcao que inicializa as variaveis de uma disciplina.
    Inicializa 'matriculados'
*/
void inicializarDisciplina(DISCIPLINAS *disciplina)
{
    disciplina->matriculados = 0;
}

/*
    Funcao que inicializa todas as variaveis de um resultado.
*/
void inicializarResultado(RESULTADOS *resultado)
{
    resultado->sexoM = 0;
    resultado->sexoF = 0;
    resultado->somaIdades = 0;
    resultado->somaIdadesNotas = 0;
    resultado->numAlunosNotas = 0;
    resultado->mediaIdades = 0;
    resultado->mediaIdadesNotas = 0;
}

/*
    Funcao que contabiliza alguns resultados dos registros realizados.
*/
void contabilizarResultados(RESULTADOS *resultado, ALUNOS *aluno)
{
    // Contabilizando sexo
    if (aluno->sexo == 0)
    {
        ++(resultado->sexoF);
    }
    else
    {
        ++(resultado->sexoM);
    }

    // Calculando a soma das idades
    resultado->somaIdades += aluno->idade;

    // Somando as idades de alunos com notas >= 7.5
    if (aluno->nota >= NOTA)
    {
        resultado->somaIdadesNotas += aluno->idade;
        ++(resultado->numAlunosNotas);
    }
}

/*
    Funcao que busca os alunos de uma disciplina
    - pos: Indice da disciplina
*/
void buscarAlunos(LISTAS *lista, int pos)
{
    int i, j;

    for (i = 0; i < lista->numAlunos; ++i)
    {
        for (j = 0; j < lista->alunos[i].numDisciplinas; ++j)
        {
            if (lista->alunos[i].disciplinas[j] == &lista->disciplinas[pos])
            {
                printf("%s\n", lista->alunos[i].nome);
            }
        }
    }
}

/*
    Funcao que imprime os resultados.
*/
void imprimirResultados(RESULTADOS *resultado, LISTAS *lista)
{
    int i;

    // Quantidade de alunos do sexo masculino e feminino
    printf("%d\n", resultado->sexoM);
    printf("%d\n", resultado->sexoF);

    // Media das idades dos alunos
    resultado->mediaIdades = resultado->somaIdades/lista->numAlunos;
    printf("%.2lf\n", resultado->mediaIdades);

    // Media pela nota do enem
    resultado->mediaIdadesNotas = resultado->somaIdadesNotas/resultado->numAlunosNotas;
    printf("%.2lf\n", resultado->mediaIdadesNotas);

    // Imprimindo as disciplinas e alunos
    for (i = 0; i < lista->numDisciplinas; ++i)
    {
        // Nome da disciplina
        printf("%s\n%d\n", lista->disciplinas[i].nome, lista->disciplinas[i].matriculados);
        buscarAlunos(lista, i);
    }
}

/*
    Funcao que cadastra os alunos.
    Chama a funcao resultados() para contabilizar algumas informacoes de cada registro.
*/
void cadastrarAluno(ALUNOS *aluno, RESULTADOS *resultado)
{
    inicializarAluno(aluno);

    // Codigo do aluno
    scanf("%s", aluno->codigo);
    getchar();
    
    // Nome
    gets(aluno->nome);

    // Idade
    scanf("%d", &aluno->idade);
    getchar();

    // Sexo
    scanf("%d", &aluno->sexo);
    getchar();

    // Nota do enem
    scanf("%lf", &aluno->nota);
    getchar();

    // Contabilizando alguns resultados
    contabilizarResultados(resultado, aluno);
}

/*
    Funcao para cadastrar as disciplinas.
*/
void cadastrarDisciplinas(DISCIPLINAS *disciplina)
{
    inicializarDisciplina(disciplina);

    // Codigo da disciplina
    scanf("%s", &disciplina->codigo);
    getchar();

    // Nome
    gets(disciplina->nome);
}

/*
    Funcao que matricula um aluno nas disciplinas.
*/
void matricular(char *codAluno, char *codDisciplina, LISTAS *lista)
{
    int i, j;

    // Buscando o aluno
    for (i = 0; i < lista->numAlunos; ++i)
    {
        if (strcmp(lista->alunos[i].codigo, codAluno) == 0)
        {
            // Buscando disciplina
            for (j = 0; j < lista->numDisciplinas; ++j)
            {
                if (strcmp(lista->disciplinas[j].codigo, codDisciplina) == 0)
                {
                        lista->alunos[i].disciplinas[lista->alunos[i].numDisciplinas] = &lista->disciplinas[j];
                        ++lista->alunos[i].numDisciplinas;
                        ++(lista->disciplinas[j].matriculados);
                }
            }
        }
    }
}

/*
    Funcao que ordena o array de ALUNOS em ordem alfabetica.
    O algoritmo usado e o Bubble Sort.
    Identifica o primeiro caractere do nome do aluno e o compara
    com o primeiro caractere do nome de outro aluno.
*/

void ordenarAlunos(LISTAS *lista)
{
    int i, j;
    ALUNOS temp;

    for (i = lista->numAlunos - 1; i > 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (strcmp(lista->alunos[j].nome, lista->alunos[j+1].nome) > 0)
            {
                temp = lista->alunos[j];
                lista->alunos[j] = lista->alunos[j+1];
                lista->alunos[j+1] = temp;
            }
        }
    }
}

/*
    Funcao que ordena o array de DISCIPLINAS em ordem alfabetica.
    O algoritmo usado e o Bubble Sort.
    Identifica o primeiro caractere do nome da disciplina e o compara
    com o primeiro caractere do nome de outra disciplina.
*/
void ordenarDisciplinas(LISTAS *lista)
{
    int i, j;
    DISCIPLINAS temp;

    for (i = lista->numDisciplinas - 1; i > 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (strcmp(lista->disciplinas[j].nome, lista->disciplinas[j+1].nome) > 0)
            {
                temp = lista->disciplinas[j];
                lista->disciplinas[j] = lista->disciplinas[j+1];
                lista->disciplinas[j+1] = temp;
            }
        }
    }
}

int main()
{

    /*
        Lista que pode ser de alunos ou de disciplinas.
    */
   LISTAS lista;
   RESULTADOS resultado;
    int i;
    char codAluno[30], codDisciplina[25];

    // Inicializando todas as variaveis de 'resultado'.
   inicializarResultado(&resultado);

   // Recebendo a quantidade de alunos
   scanf("%d", &lista.numAlunos);
   getchar();

   // Funcao para cadastrar os alunos
    for (i = 0; i < lista.numAlunos; ++i)
    {
        cadastrarAluno(&lista.alunos[i], &resultado);
    }

    // Recebendo a quantidade de disciplinas
    scanf("%d", &lista.numDisciplinas);
    getchar();

    // Funcao para cadastrar as disciplinas
    for (i = 0; i < lista.numDisciplinas; ++i)
    {
        cadastrarDisciplinas(&lista.disciplinas[i]);
    }

    // Funcoes que ordenam os arrays de ALUNOS e DISCIPLINAS em ordem alfabetica.
   ordenarAlunos(&lista);
   ordenarDisciplinas(&lista);

    // Recebendo a quantidade de matriculas
    scanf("%d", &lista.numMatriculas);
    getchar();

    // Funcao que matricula os alunos
    for (i = 0; i < lista.numMatriculas; ++i)
    {
        // Recebendo o codigo do aluno e da disciplina
        scanf("%s %s", codAluno, codDisciplina);
        matricular(codAluno, codDisciplina, &lista);
    }

    imprimirResultados(&resultado, &lista); 

    return 0;
}