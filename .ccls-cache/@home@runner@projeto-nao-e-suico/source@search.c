#include <stdio.h>

#include "globais.h"
#include "search.h"

Usuario busca_usuario(char *identificador, int show_message) {
  Usuario user_found = USER_NOT_FOUND;

  for (int index = 0; index < tot_usuarios; index++) {
    Usuario actual_user = usuarios[index];

    if (is_string_equal(actual_user.email, identificador) ||
        is_string_equal(actual_user.cpf, identificador)) {
      user_found = actual_user;
      break;
    }
  }

  if (!is_valid_user(user_found) && show_message == 1) {
    printf("Usuário %s não encontrado!\n", identificador);
  }

  return user_found;
}

