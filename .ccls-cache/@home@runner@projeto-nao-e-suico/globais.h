#ifndef GLOBAIS_H
#define GLOBAIS_H

/**
 *
 * Types
 *
 */

typedef struct {
  char nome[50], cpf[14], email[50], celular[12], senha[30];
} Usuario;

/**
 *
 * Global Variables
 *
 */

extern Usuario usuarios[10];
extern Usuario usuario_logado;
extern int tot_usuarios;

/**
 *
 * Global Constants
 *
 */

extern Usuario USER_NOT_FOUND;

/**
 *
 * Utils
 *
 */

int inputInt(char *message);

void inputString(char *variable, char *message);

int is_string_equal(char *str1, char *str2);

void clean_console();

#endif /* GLOBAIS_H */