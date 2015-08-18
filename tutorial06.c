/*
 * Tutorial Allegro5
 * Eventos
 */

#include <stdio.h>
#include <allegro5/allegro.h> 
#include <allegro5/allegro_image.h>

#define LARG 1280
#define ALT 720

/*Struct da imagem*/
typedef struct {
   int pos_x;
   int pos_y;

   ALLEGRO_BITMAP *img;
}objeto; 

int main(void) {

   int fim_do_jogo = 0; // Controle do Loop Principal

   /*controle de renderização da tela*/
   int renderizar = 1;

   /*Controle de frames por segundo*/
   const int FPS = 60;

   ALLEGRO_DISPLAY *janela = NULL;
   ALLEGRO_BITMAP *imagem = NULL;
   ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL; //Declara e inicializa variavel da fila de eventos

   /*Declara e inicializa variavel de timer*/
   ALLEGRO_TIMER *timer = NULL;

   /*Declaracao da struct*/
   objeto jobson;

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

   /*Cria timer de controle*/
   timer = al_create_timer(1.0 / FPS);
   if (!timer)
   {
      fprintf(stderr, "Falha ao criar timer!\n");
      return EXIT_FAILURE;
   }

   /*Carrega imagem*/
   imagem = al_load_bitmap("imagem.png");
   if (!imagem) {
      fprintf(stderr, "Falha ao carregar imagem!\n");
      return -1;
   }

   /*Inicializa struct*/
   jobson.pos_x = LARG / 2;
   jobson.pos_y = ALT / 2;
   jobson.img = imagem;

   /*Registra fontes de eventos*/
   al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
   al_register_event_source(fila_de_eventos, al_get_mouse_event_source());
   al_register_event_source(fila_de_eventos, al_get_display_event_source(janela));

   /*Registra Timer como fonte de eventos*/
   al_register_event_source(fila_de_eventos, al_get_timer_event_source(timer));

   al_clear_to_color(al_map_rgb(0, 0, 0));
   al_flip_display();

   /*Inicia Timer*/
   al_start_timer(timer);

   /*Loop principal do Jogo*/
   while (!fim_do_jogo) {

      /*Cria variavel de evento e a associa a fila de eventos*/
      ALLEGRO_EVENT evento;
      al_wait_for_event(fila_de_eventos, &evento);

      if (evento.type == ALLEGRO_EVENT_TIMER)
      {
         /*Permite Renderização da tela*/
         renderizar = 1;
      }
      /*Verifica se a janela foi fechada*/
      else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
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
            case ALLEGRO_KEY_UP:
               jobson.pos_y -= 10;
               break;
            case ALLEGRO_KEY_DOWN:
               jobson.pos_y += 10;
               break;
            case ALLEGRO_KEY_LEFT:
               jobson.pos_x -= 10;
               break;
            case ALLEGRO_KEY_RIGHT:
               jobson.pos_x += 10;
               break;
         }
      }

      if (renderizar) {
         renderizar = 0;
         al_draw_bitmap(jobson.img, jobson.pos_x - (al_get_bitmap_width(jobson.img) / 2), jobson.pos_y - (al_get_bitmap_height(jobson.img) / 2), 0);
         al_flip_display();
         al_clear_to_color(al_map_rgb(0, 0, 0));
      }

   }
   /*Destroi Variavel da fila de eventos*/


   al_destroy_event_queue(fila_de_eventos);
   al_destroy_bitmap(imagem);

   /*Destroi variavel de timer*/
   al_destroy_timer(timer);

   al_destroy_display(janela);

   return 0;
} 

/* Para compilar: "gcc nomedoarquivo.c -o nomedoexecutavel -std=c99 -lallegro -lallegro_image" */
