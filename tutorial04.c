/*
 * Tutorial Allegro5
 * Eventos
 */

#include <stdio.h>
#include <allegro5/allegro.h> 
#include <allegro5/allegro_image.h>

#define LARG 1280
#define ALT 720

int main(void) {

   /*Controle do Loop Principal*/
   int fim_do_jogo = 0;

   ALLEGRO_DISPLAY *janela = NULL;
   ALLEGRO_BITMAP *imagem = NULL;

   /*Declara e inicializa variavel da fila de eventos*/
   ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;

   if(!al_init()) {
      fprintf(stderr, "Falha ao iniciar Allegro5!\n");
      return -1;
   }

   janela = al_create_display(LARG, ALT);
   if (!janela) {
      fprintf(stderr, "Falha ao criar janela!\n");
      return -1;
   }

   al_init_image_addon();

   /*Instala extensoes de mouse e teclado*/
   al_install_keyboard();
   al_install_mouse();

   /*Cria fila de eventos*/
   fila_de_eventos = al_create_event_queue();
   if (!fila_de_eventos) {
      fprintf(stderr, "Falha ao criar fila de eventos!\n");
      return -1;
   }

   /*Carrega imagem*/
   imagem = al_load_bitmap("imagem.png");
   if (!imagem) {
      fprintf(stderr, "Falha ao carregar imagem!\n");
      return -1;
   }

   /*Registra fontes de eventos*/
   al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
   al_register_event_source(fila_de_eventos, al_get_mouse_event_source());
   al_register_event_source(fila_de_eventos, al_get_display_event_source(janela));

   al_clear_to_color(al_map_rgb(0, 0, 0));
   al_flip_display();

   /*Loop principal do Jogo*/
   while (!fim_do_jogo) {

      /*Cria variavel de evento e a associa a fila de eventos*/
      ALLEGRO_EVENT evento;
      al_wait_for_event(fila_de_eventos, &evento);

      /*Verifica se a janela foi fechada*/
      if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         fim_do_jogo = 1;
      }

      /*Verifica pressionamento de tecla do teclado*/
      else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
         /*Verifica qual tecla foi pressionada*/
         switch (evento.keyboard.keycode)
         {
            case ALLEGRO_KEY_ESCAPE:
               fim_do_jogo = 1;
               break;
            case ALLEGRO_KEY_ENTER:
               al_draw_bitmap(imagem, LARG / 2 - (al_get_bitmap_width(imagem) / 2), ALT / 2  - (al_get_bitmap_height(imagem) / 2), 0);
               al_flip_display();
               fim_do_jogo = 1;
               break;
         }
      }

   }

   al_rest(5);

   /*Destroi Variavel da fila de eventos*/
   al_destroy_event_queue(fila_de_eventos);

   al_destroy_display(janela);
   al_destroy_bitmap(imagem);

   return 0;
} 

/* Para compilar: "gcc nomedoarquivo.c -o nomedoexecutavel -std=c99 -lallegro -lallegro_image" */