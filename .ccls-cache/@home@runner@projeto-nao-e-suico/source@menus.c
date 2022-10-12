#include <stdio.h>

#include "globais.h"

#include "cadastro.h"
#include "login.h"
#include "menus.h"

void first_menu() {
  void (*escolhas[2])();

  escolhas[0] = login;
  escolhas[1] = cadastro;

  char *opcoes[2] = { "Login", "Cadastro" };
  char *descricao = "Seja bem vindo ao paraiso fiscal\n";

  show_escolhas_menu(escolhas, opcoes, 2, descricao);
}


void home_menu() {  
  void (*escolhas[4])();

  escolhas[0] = deposito_sacar_menu;
  // escolhas[1] = pix/ted;
  // escolhas[2] = fatura;
  // escolhas[3] = emprestimo;

  char *opcoes[4] = { "Depositar/Sacar", "PIX/TED", "Fatura", "Empréstimo" };
  char *descricao = "Pagina Inicial\n";

  show_escolhas_menu(escolhas, opcoes, 4, descricao);
}

void deposito_sacar_menu() {
//   int inEscolha;
//   void (*escolhas[2])();

//   escolhas[0] = depositar;
//   escolhas[1] = sacar;
//   printf("\n===============================\n");
//   printf("1 - Depositar\n");
//   printf("2 - Sacar\n");
//   printf("\n===============================\n");

//   inEscolha = inputInt("Digite a opção desejada: ");

//   clean_console();

//   (*escolhas[inEscolha - 1])();

//   clean_console();
}

void show_escolhas_menu(void (**escolhas_func)(), char ** opcoes_texto, int opcoes_num, char * descricao) {
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