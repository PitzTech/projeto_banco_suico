#include <stdio.h>

#include "globais.h"
#include "search.h"

Usuario busca_usuario(char *identificador) {
  Usuario user_found = USER_NOT_FOUND;

  for (int index = 0; index < tot_usuarios; index++) {
    Usuario actual_user = usuarios[index];

    if (is_string_equal(actual_user.email, identificador) ||
        is_string_equal(actual_user.cpf, identificador)) {
      user_found = actual_user;
      break;
    }
  }

  if (is_string_equal(user_found.nome, "false")) {
    printf("Usuário %s não encontrado!\n", identificador);
  }

  return user_found;
}
