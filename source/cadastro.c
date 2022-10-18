#include <stdio.h>

#include "cadastro.h"
#include "globais.h"
#include "search.h"

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

    Usuario user_found = USER_NOT_FOUND;
    user_found = busca_usuario(temp_user.cpf, 0);

    if (is_valid_user(user_found)) {
      printf("Esse CPF já está cadastrado! Ligando para o FBI.\n");

      printf("Para continuar aperte ENTER.");

      getchar();

      return;
    }

    user_found = busca_usuario(temp_user.email, 0);

    if (is_valid_user(user_found)) {
      printf("Esse EMAIL já está cadastrado! Ligando para o FBI.\n");

      printf("Para continuar aperte ENTER.");

      getchar();

      return;
    }

    // TODO: JÀ EXISTE UM USUARIO COM ESSE EMAIL OU CPF

    printf("As informações digitadas são: ");

    printf("\nNome: %s", temp_user.nome);
    printf("\nCPF: %s", temp_user.cpf);
    printf("\nEmail: %s", temp_user.email);
    printf("\nCelular: %s", temp_user.celular);
    printf("\nSenha: %s", temp_user.senha);

    inputString(is_correta, "\n\nEstão corretas? (s/n)  ");

    clean_console();
  }

  temp_user.id = tot_usuarios;
  temp_user.tot_transacoes = 0;
  usuarios[tot_usuarios++] = temp_user;
}
