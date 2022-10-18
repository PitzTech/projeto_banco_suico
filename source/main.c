#include "globais.h"
#include "menus.h"

void before_main() {
  usuario_logado = &USER_NOT_FOUND;

  usuarios[tot_usuarios++] = default_user;
  // usuario_logado = &usuarios[0];
}

int main() {

  before_main();

  typedef struct {
    int INICIAL, HOME;
  } ITelasStruct;

  ITelasStruct ITelas = {.INICIAL = 0, .HOME = 1};

  void (*telas[3])();

  telas[0] = first_menu;
  telas[1] = home_menu;
  telas[2] = deposito_sacar_menu;

  int tela_atual;

  while (1) {
    tela_atual = ITelas.INICIAL;

    if (is_logado()) {
      tela_atual = ITelas.HOME;
    }

    // Chama a tela atual
    (*telas[tela_atual])();
  }

  return 0;
}
