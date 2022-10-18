#include <stdio.h>
#include <string.h>
#include <time.h>

#include "financas.h"
#include "globais.h"
#include "search.h"

void depositar() {
  int valor;
  char confirmar_senha[30] = "SENHA_INCORRETA";

  while (is_string_equal(confirmar_senha, "SENHA_INCORRETA")) {
    valor = inputInt("Quanto você deseja depositar: ");
    inputString(confirmar_senha,
                "Digite a sua senha para confirmar a transação: ");

    if (!is_string_equal(confirmar_senha, usuario_logado->senha)) {
      printf("Senha incorreta, tente novamente!\n");
      strcpy(confirmar_senha, "SENHA_INCORRETA");

      wait_enter_key();
    }

    clean_console();
  }

  registra_transacao(valor, TransacaoType.ENTRADA, usuario_logado->cpf);

  printf("Transação concluida com sucesso!\n");

  wait_enter_key();
}

void sacar() {
  int valor;
  char confirmar_senha[30] = "SENHA_INCORRETA";

  while (is_string_equal(confirmar_senha, "SENHA_INCORRETA")) {
    valor = inputInt("Quanto você deseja sacar: ");
    inputString(confirmar_senha,
                "Digite sua senha para confirmar a transação: ");

    if (!is_string_equal(confirmar_senha, usuario_logado->senha)) {
      printf("Senha incorreta, tente novamente!\n");
      strcpy(confirmar_senha, "SENHA_INCORRETA");

      wait_enter_key();
    }

    clean_console();
  }

  if (usuario_logado->saldo >= valor) {
    registra_transacao(valor, TransacaoType.SAIDA, usuario_logado->cpf);

    printf("Transação concluida com sucesso!\n");
  } else {
    printf("Saldo insuficiente!");
  }

  wait_enter_key();
}

void transferencia() {
  int valor;
  char confirmar_senha[30] = "SENHA_INCORRETA";
  char chave_pix[30]; // padrão EMAIL e CPF
  Usuario receiver_user_found = USER_NOT_FOUND;

  while (is_string_equal(confirmar_senha, "SENHA_INCORRETA")) {
    valor = inputInt("Qual valor da transferencia? ");

    inputString(chave_pix, "Qual o identificador do laranja (CPF / EMAIL): ");

    receiver_user_found = busca_usuario(chave_pix, 0);

    if (!is_valid_user(receiver_user_found)) {
      clean_console();
      
      printf("Identificador inválido. Te passaram o cano.\n");

      wait_enter_key();

      return;
    }

    inputString(confirmar_senha, "Digite sua senha para confirmar a transação: ");
    if (!is_string_equal(confirmar_senha, usuario_logado->senha)) {
      clean_console();
      
      printf("Senha incorreta, tente novamente!\n");
      strcpy(confirmar_senha, "SENHA_INCORRETA");

      wait_enter_key();
    }

    clean_console();
  }

  if (usuario_logado->saldo >= valor) {
    registra_transacao(valor, TransacaoType.ENTRADA, receiver_user_found.cpf);
    registra_transacao(valor, TransacaoType.SAIDA, usuario_logado->cpf);

    printf("Transação concluida com sucesso!\n");
  } else {
    printf("Saldo insuficiente!\n");
  }
  
  wait_enter_key();
}

void extrato() {
  printf("\n=====================================\n");
  printf("BEM VINDO AO LUGAR MAIS VAZIO QUE VC JÀ VIU");
  printf("\n=====================================\n");

  Transacao *user_transactions = usuario_logado->transacoes;
  int user_transactions_length = usuario_logado->tot_transacoes;

  if (user_transactions_length == 0) {
    printf("\nNão há operações a serem exibidas no momento.\n");

    wait_enter_key();

    return;
  }

  printf("\nO seu extrato é:\n");

  for (int index = 0; index < user_transactions_length; index++) {
    Transacao actual_transaction = user_transactions[index];

    char transaction_type[10];

    if (actual_transaction.transacao_type == TransacaoType.ENTRADA) {
      strcpy(transaction_type, "ENTRADA");
    } else if (actual_transaction.transacao_type == TransacaoType.SAIDA) {
      strcpy(transaction_type, "SAIDA");
    }

    printf("\n%d  - %s  - R$ %d,00\n", index + 1, transaction_type,
           actual_transaction.valor);
  }

  printf("\n\n=====================================\n\n");

  printf("Seu saldo atual é: R$ %d,00\n", usuario_logado->saldo);

  wait_enter_key();
}

void fatura() {
  printf("\n============================================\n");
  printf("BEM VINDO A SUA DOSE DE DESESPERO DIARIA");
  printf("\n============================================\n");

  printf("BEM VINDO A SUA DOSE DE DESESPERO DIARIA");
}

void emprestimo() {
  int valor;
  float porcentagem;
  char confirmar_senha[30] = "SENHA_INCORRETA";

  while (is_string_equal(confirmar_senha, "SENHA_INCORRETA")) {
    valor = inputInt("Quanto deseja de emprestimo?");
    // porcetangem = duvida
    // TODO FAZER JUROS
    inputString(confirmar_senha,
                "Digite sua senha para completar a transação!\n");

    clean_console();

    if (!is_string_equal(confirmar_senha, usuario_logado->senha)) {
      printf("Senha incorreta, tente novamnete!\n");
      strcpy(confirmar_senha, "SENHA_INCORRETA");
    }
  }
  clean_console();
}

void registra_transacao(int valor, int transacao_type, char *user_identifier) {
  int usuarioId = busca_usuario(user_identifier, 0).id;

  time_t actual_time = time(NULL);

  Transacao actual_transaction = {.timestamp = actual_time,
                                  .transacao_type = transacao_type,
                                  .valor = valor};

  int transacao_sinal = transacao_type == TransacaoType.ENTRADA ? 1 : -1;

  usuarios[usuarioId].saldo += valor * transacao_sinal;

  usuarios[usuarioId].transacoes[usuarios[usuarioId].tot_transacoes] =
      actual_transaction;

  usuarios[usuarioId].tot_transacoes += 1;
}