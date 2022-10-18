#include <stdio.h>

#include "globais.h"

#include "cadastro.h"
#include "financas.h"
#include "login.h"
#include "menus.h"

void first_menu() {
  void (*escolhas[2])();

  escolhas[0] = login;
  escolhas[1] = cadastro;

  char *opcoes[2] = {"Login", "Cadastro"};
  char *descricao = "Seja bem vindo ao paraiso fiscal\n";

  show_escolhas_menu(escolhas, opcoes, 2, descricao);
}

void home_menu() {
  void (*escolhas[6])();

  escolhas[0] = deposito_sacar_menu;
  escolhas[1] = pix_ted_menu;
  escolhas[2] = fatura;
  escolhas[3] = extrato;
  escolhas[4] = emprestimo;
  escolhas[5] = logout;
  

  char *opcoes[6] = {"Depositar/Sacar", "PIX/TED", "Fatura", "Extrato", "Empréstimo", "Logout"};
  char *descricao = "Pagina Inicial\n";

  show_escolhas_menu(escolhas, opcoes, 6, descricao);
}

void deposito_sacar_menu() {
  void (*escolhas[2])();

  escolhas[0] = depositar;
  escolhas[1] = sacar;

  char *opcoes[2] = {"Depositar", "Sacar"};
  char *descricao = "Sessão Depositar/Sacar\n";

  show_escolhas_menu(escolhas, opcoes, 2, descricao);
}

void pix_ted_menu() {
  void (*escolhas[2])();

  escolhas[0] = transferencia;
  escolhas[1] = transferencia;

  char *opcoes[2] = {"PIX", "TED"};
  char *descricao = "Sessão PIX/TED\n";

  show_escolhas_menu(escolhas, opcoes, 2, descricao);
}

void show_escolhas_menu(void (**escolhas_func)(), char **opcoes_texto,
                        int opcoes_num, char *descricao) {
  int inEscolha;

  printf("\n===============================\n");
  printf("%s\n", descricao);
  printf("As opções são:\n\n");

  for (int index = 0; index < opcoes_num; index++) {
    printf("%d - %s\n", index + 1, opcoes_texto[index]);
  }

  printf("\n===============================\n");

  inEscolha = inputInt("Digite a opção desejada: ");

  clean_console();

  escolhas_func[inEscolha - 1]();

  clean_console();
}