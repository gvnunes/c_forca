#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char palavraSecreta[20];
  char palavraRevelada[40];
  sprintf(palavraSecreta, "MELANCIA");

  int acertou = 0;
  int enforcou = 0;
  int achou = 0;

  const int MAX_ERROS = 5;
  int erros = 0;

  char* chutes = malloc(sizeof(char) * MAX_ERROS);
  char chute;

  for (int letra = 0; letra < strlen(palavraSecreta); letra++) {
    palavraRevelada[letra] = '_';
  }

  do {

    system("clear");

    printf("Letras chutadas: ");
    printf("%s", chutes);
    printf("\n");

    printf("%s", palavraRevelada);
    printf("\n");



    if(strcmp(palavraSecreta, palavraRevelada) == 0) {
      acertou = 1;
      break;
    }

    printf("Erros: %d / %d", erros, MAX_ERROS);
    printf("\n");

    if(erros == MAX_ERROS){
      enforcou = 1;
      break;
    }

    printf("Digite seu chute: ");
    scanf(" %c", &chute);


    achou = 0;

    for (int letra = 0; letra < strlen(palavraSecreta); letra++) {
      if (palavraSecreta[letra] == chute) {
        palavraRevelada[letra] = chute;
        achou = 1;
      }
    }

    if(!achou) {
      chutes[erros] = chute;
      erros ++;
    }

  } while (!acertou && !enforcou);

  if (acertou){
            printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
  } else {
     printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
  }

  free(chutes);

}
