/*
 * Tutorial Allegro5
 * Structs
 */

/*Declaração padrão*/
struct exemplo{
	int numero = 4;
	float qut = 3.4;
	char sexo = 'm';
	ALLEGRO_BITMAP *imagem = NULL;
};

/*Declaracao de uma nova struct*/
struct exemplo nome;

/*declaracao simplificada*/
typedef struct {
	int numero = 4;
	float qut = 3.4;
	char sexo = 'm';
	ALLEGRO_BITMAP *imagem = NULL;
}exemplo;

exemplo nome;

/*Acessando um valor da struct*/
nome.numero = 10;
nome.sexo = 's';


/*Ponteiros de structs*/
exemplo jobson;
exemplo *doisberto = &jobson;

(*doisberto).numero = 10;
doisberto->numero = 10;