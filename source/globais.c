#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globais.h"

/**
 *
 * Global Variables
 *
 */

int tot_usuarios = 0;
Usuario usuarios[10];
Usuario *usuario_logado;
Usuario default_user = {.id = 0,
                        .nome = "Corrupto Oficial",
                        .cpf = "12312313212",
                        .email = "corrupo@brasil.org.br",
                        .celular = "011912341234",
                        .senha = "vamosroubaralua",
                        .saldo = 0,
                        .tot_transacoes = 0};

/**
 *
 * Global Constants
 *
 */

Usuario USER_NOT_FOUND = {.nome = "false", .tot_transacoes = 0, .saldo = 0};

ITransacaoType TransacaoType = {.ENTRADA = 0, .SAIDA = 1};

/**
 *
 * Utils
 *
 */

int inputInt(char *message) {
  int input;
  printf("%s", message);
  scanf("%i", &input);

  clean_buffer();

  return input;
}

int is_string_equal(char *str1, char *str2) { return !strcmp(str1, str2); }

void inputString(char *variable, char *message) {
  printf("%s", message);
  scanf("%s", variable);

  clean_buffer();
}

void wait_enter_key() {
  printf("\n=====================================\n");
  printf("Para retornar aperte ENTER");
  printf("\n=====================================\n");

  // clean_buffer();
  getchar();
}

void clean_buffer() {
  while (getchar() != '\n')
    continue;
}

void clean_console() { system("clear"); }

int is_valid_user(Usuario user) {
  int is_valid = !is_string_equal(user.nome, "false");

  return is_valid;
}

int is_logado() {
  int is_logged = !is_string_equal(usuario_logado->nome, "false");

  return is_logged;
}

void logout() {
  // TODO: CONFIRMAR SE USUARIO DESEJA SAIR
   usuario_logado = &USER_NOT_FOUND;
}