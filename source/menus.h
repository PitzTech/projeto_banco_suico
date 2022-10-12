#ifndef MENUS_H
#define MENUS_H

void show_escolhas_menu(void (**escolhas_func)(), char ** opcoes_texto, int opcoes_num, char * descricao);

void first_menu();

void home_menu();

void deposito_sacar_menu();

void pix_ted_menu();

#endif /* MENUS_H */
