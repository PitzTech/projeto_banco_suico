#include "globais.h"
#include "menus.h"

int main() {
  typedef struct {
    int INICIAL, HOME;
  } ITelasStruct;

  ITelasStruct ITelas = {.INICIAL = 0, .HOME = 1};

  void (*telas[2])();

  telas[0] = first_menu;
  telas[1] = home_menu;

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
