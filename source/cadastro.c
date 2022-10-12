#include <stdio.h>

#include "cadastro.h"
#include "globais.h"

void cadastro() {
  Usuario temp_user;
  char is_correta[3] = "n";
  printf("\n===============================\n");
  printf("Bem vindo ao CADASTRO anonimo");
  printf("\n===============================\n");

  while (is_correta[0] != 's' || is_correta[0] == 'S') {
    printf("\nDigite suas informações de conta:\n\n");

    inputString(temp_user.nome, "Nome: ");
    inputString(temp_user.cpf, "CPF: ");
    inputString(temp_user.email, "Email: ");
    inputString(temp_user.celular, "Celular: ");
    inputString(temp_user.senha, "Senha: ");

    clean_console();

    printf("As informações digitadas são: ");

    printf("\nNome: %s", temp_user.nome);
    printf("\nCPF: %s", temp_user.cpf);
    printf("\nEmail: %s", temp_user.email);
    printf("\nCelular: %s", temp_user.celular);
    printf("\nSenha: %s", temp_user.senha);

    inputString(is_correta, "\n\nEstão corretas? (s/n)  ");

    clean_console();
  }

  usuarios[tot_usuarios++] = temp_user;
}
