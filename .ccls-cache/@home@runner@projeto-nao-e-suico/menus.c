#include <stdio.h>

#include "globais.h"

#include "cadastro.h"
#include "login.h"
#include "menus.h"

void show_menu() {
  int inEscolha;
  void (*escolhas[2])();

  escolhas[0] = login;
  escolhas[1] = cadastro;

  printf("\n===============================\n");
  printf("Seja bem vindo ao paraiso fiscal\n");
  printf("As opções são:\n\n");
  printf("1 - Login\n");
  printf("2 - Cadastro");
  printf("\n===============================\n");

  inEscolha = inputInt("Digite a opção desejada: ");

  clean_console();

  (*escolhas[inEscolha - 1])();

  clean_console();
}
