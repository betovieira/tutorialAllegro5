/*
 * Tutorial Allegro5
 * Primitives
 */

#include <stdio.h>
#include <allegro5/allegro.h> 

/*Inclui bilioteca do Allegro Primitives*/
 #include <allegro5/allegro_primitives.h>

#define LARG 1280
#define ALT 720

int main(void) {

   ALLEGRO_DISPLAY *janela = NULL;

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

   /*Inicia extenção de Primitives*/
   al_init_primitives_addon();

   al_clear_to_color(al_map_rgb(0, 0, 0));

   /*Exemplos de Primitives*/
   al_draw_line(400, 300, 600, 100, al_map_rgb(0, 255, 0), 3);
   al_draw_filled_triangle(800, 100, 700, 200, 850, 300, al_map_rgb(255, 255, 0));
   al_draw_rounded_rectangle(300, 500, 500, 600, 30, 30, al_map_rgb(255, 0, 0), 4);
   al_draw_filled_circle(800, 500, 75, al_map_rgb(0, 0, 255));

   al_flip_display();

   al_rest(5);

   al_destroy_display(janela);   
   return 0;
} 

/* Para compilar: "gcc nomedoarquivo.c -o nomedoexecutavel -std=c99 -lallegro -lallero_primitives" */