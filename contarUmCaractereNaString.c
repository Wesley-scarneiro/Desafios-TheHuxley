/*
Descrição:
Faça um programa para ler uma string e um caracter qualquer e calcule o número de ocorrências desse caracter na string. Exemplo: Seja a string "maracatu" e o caracter 'a', então o número de ocorrências é 3.

Formato de entrada:
Você lerá duas linhas. Na primeira linha você receberá uma string com no máximo 50 caracteres. Na segunda linha você receberá um único caracter.

Formato de saída:
Imprima um número inteiro indicando quantas vezes o caracter dado aparece na string.  Depois de imprimir o número, imprima um final de linha (ou seja, pule uma linha).
*/

#include <stdio.h>

// Tamanho maximo da string
#define T 50

/*
    Funcao que procura um determinado caractere em uma string.
    Retorna quantas vezes esse caractere aparece.
*/
void procurar(char palavra[T], char c)
{
  int i, cont;

  cont = 0;

  for (i = 0; palavra[i] != '\0'; i++)
  {
      if (palavra[i] == c)
      {
        ++cont;
      }
  }
  printf("%d\n", cont);
}

int main()
{
  // Varivaveis
  char palavra[T], c;

    scanf("%s\n", palavra);
    scanf("%c", &c);

  // funcao
  procurar(palavra, c);

  return 0;
}
