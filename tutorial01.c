/*
 * Tutorial Allegro5
 * Criacao de Janela
 */

#include <stdio.h>

/*Inclui Biblioteca Allegro*/
#include <allegro5/allegro.h> 

/*Define tamanho da Tela*/
#define LARG 1280
#define ALT 720

int main(void) {

   /*Declaracao e Inicializacao da Variavel de Janela*/
   ALLEGRO_DISPLAY *janela = NULL;

   /*Inicializa Allegro5*/
   if(!al_init()) {
      fprintf(stderr, "Falha ao iniciar Allegro5!\n");
      return -1;
   }

   /*Cria Janela de Jogo*/
   janela = al_create_display(LARG, ALT);
   if (!janela)
   {
      fprintf(stderr, "Falha ao criar janela!\n");
      return -1;
   }

   /*Preenche a tela com a cor desejada*/
   al_clear_to_color(al_map_rgb(0, 0, 0));

   /*Atualiza tela*/
   al_flip_display();

   /*Pausa execucao*/
   al_rest(5);

   /*Destroi Variavel de Janela*/
   al_destroy_display(janela);
   
   return 0;
} 