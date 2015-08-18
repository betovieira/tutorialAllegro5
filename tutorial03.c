/*
 * Tutorial Allegro5
 * Imagens
 */

#include <stdio.h>
#include <allegro5/allegro.h> 

/*Inclui biblioteca de imagens allegro*/
#include <allegro5/allegro_image.h>

#define LARG 1280
#define ALT 720

int main(void) {

   ALLEGRO_DISPLAY *janela = NULL;

   /*Declara e inicializa variavel de imagem*/
   ALLEGRO_BITMAP *imagem = NULL;

   if(!al_init()) {
      fprintf(stderr, "Falha ao iniciar Allegro5!\n");
      return -1;
   }

   janela = al_create_display(LARG, ALT);
   if (!janela)
   {
      fprintf(stderr, "Falha ao criar janela!\n");
      return -1;
   }

   /*Inicia extensao de imagens*/
   al_init_image_addon();

   /*Carrega imagem*/
   imagem = al_load_bitmap("imagem.png");
   if (!imagem)
   {
      fprintf(stderr, "Falha ao carregar imagem!\n");
      return -1;
   }

   al_clear_to_color(al_map_rgb(0, 0, 0));

   /*Desenha a imagem*/
   al_draw_bitmap(imagem, LARG / 2 - (al_get_bitmap_width(imagem) / 2), ALT / 2  - (al_get_bitmap_height(imagem) / 2), 0);

   al_flip_display();

   al_rest(5);

   al_destroy_display(janela);  

   /*Destroi Variavel de imagem*/
   al_destroy_bitmap(imagem);

   return 0;
} 

/* Para compilar: "gcc nomedoarquivo.c -o nomedoexecutavel -std=c99 -lallegro -lallegro_image" */