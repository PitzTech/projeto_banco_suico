#include "financas.h"
#include "globais.h"

void depositar(){
  int valor;
  char confirmar_senha[30] = "SENHA_INCORRETA";

  while(is_string_equal(confirmar_senha, "SENHA_INCORRETA")) {
    valor = inputInt("Quando você deseja depositar: ");
    confirmar_senha = inputString("Digite a sua senha para confirmar a transação: \n");
  
    if (!is_string_equal(confirmar_senha, usuario_logado.senha)) {  
      printf("Senha incorreta, tente novamente!\n");
      confirmar_senha = "SENHA_INCORRETA";
    }

    clean_console();
  }

  usuario_logado.saldo += valor;

  printf("Transação concluida com sucesso!\n");
}