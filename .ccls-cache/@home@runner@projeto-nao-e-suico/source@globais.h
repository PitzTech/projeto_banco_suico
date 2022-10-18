#include <time.h>

#ifndef GLOBAIS_H
#define GLOBAIS_H

/**
 *
 * Types
 *
 */

typedef struct {
  time_t timestamp;
  int transacao_type;
  int valor;
} Transacao;

typedef struct {
  int id;
  char nome[50], cpf[14], email[50], celular[12], senha[30];
  int saldo;
  Transacao transacoes[300];
  int tot_transacoes;
} Usuario;

typedef struct {
  int ENTRADA, SAIDA;
} ITransacaoType;

/**
 *
 * Global Variables
 *
 */

extern Usuario usuarios[10];
extern Usuario *usuario_logado;
extern Usuario default_user;
extern int tot_usuarios;

/**
 *
 * Global Constants
 *
 */

extern Usuario USER_NOT_FOUND;

ITransacaoType TransacaoType;

/**
 *
 * Utils
 *
 */

int inputInt(char *message);

void inputString(char *variable, char *message);

int is_string_equal(char *str1, char *str2);

void clean_console();

void clean_buffer();

void wait_enter_key();

int is_valid_user(Usuario user);

int is_logado();

void logout();


#endif /* GLOBAIS_H */