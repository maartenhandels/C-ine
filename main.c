/*
 * main.c
 *
 *  Created on: Apr 1, 2019
 *      Author: maarten
 */
#include <stdio.h>
#include "gestor.h"
#include "cartelera.h"


int main(void)
{
	printf("Hola mundo\n");

	char c = '5';

	int x = c - '0';

	printf("El numero es %i\n", x);

	Cartelera cart;

	cart.cine = "urbil";

	cart.numPelis = 2;

	cart.peliculas = malloc (sizeof(Pelicula)*2);

	cart.peliculas[0].titulo = "Interstellar";
	cart.peliculas[1].titulo = "Bambi";

	printf("Llega aqui\n");

	ficheroCartelera(cart);

	char caracter;

	do
	{
		printf("Menu Principal: \n");
		printf("1.- Cartelera\n2.- Compra de entradas\n");
		scanf(" %c", &caracter);
		printf("%c\n", caracter);


		if(caracter == 'g')
		{
			menuGestor();
		}else if(caracter == '1'){


		}


	}while(caracter!='q');

}



