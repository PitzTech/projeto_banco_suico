#include <stdio.h>
#include <string.h>

#include "globais.h"

/**
 *
 * Global Variables
 *
 */

int tot_usuarios = 0;
Usuario usuarios[10];
Usuario usuario_logado = {.nome = "false"};

/**
 *
 * Global Constants
 *
 */

Usuario USER_NOT_FOUND = {.nome = "false"};

/**
 *
 * Utils
 *
 */

int inputInt(char *message) {
  int input;
  printf("%s", message);
  scanf("%i", &input);

  return input;
}

int is_string_equal(char *str1, char *str2) { return !strcmp(str1, str2); }

void inputString(char *variable, char *message) {
  printf("%s", message);
  scanf("%s", variable);
}

void clean_console() { system("clear"); }
