/*
 * cartelera.c
 *
 *  Created on: Apr 6, 2019
 *      Author: maarten
 */
#include "cartelera.h"
#include <stdio.h>
#include <string.h>
#define TAMANYO_tit 100
#define TAMANYO_descr 200

void imprimirCartelera(Cartelera cart)
{
	for (int i =0; i<cart.numPelis;i++)
	{
		printf("Cine: %s, Pelicula: %s, Descripcion: %s\n", cart.cine, (cart.peliculas[i]).titulo, (cart.peliculas[i]).descripcion);
	}
}

void ficheroCartelera(Cartelera cart)
{
	FILE *f;
	char cine[100];

	printf("Llega aqui2\n");

	strcpy(cine, cart.cine);
	strcat(cine, "Cartelera.txt");

	printf("Llega aqui3\n");

	f = fopen(cine, "w+");

	char *cine2 = cart.cine;

	int lonCharCine = strlen(cine2);

	printf("Llega aqui4\n");

//	fprintf(f, lonCharCine);
	fprintf(f, cart.cine);
	fprintf(f, "\n");
//	fprintf(f, cart.numPelis);
//	int lonPeli = 0;


	for(int i=0; i<cart.numPelis; i++)
	{

		fprintf(f, "%s", cart.peliculas[i].titulo);
		fprintf(f, "\n");
		fprintf(f, "%s", cart.peliculas[i].descripcion);
		fprintf(f, "\n");

	}

	fclose(f);


}
Cartelera leerCartelera(char *cine)
{
	Cartelera cart;
	FILE *f;
	char ch;
	char fichero[100];
	//int lonCharCine;
	int numPelis = 0;
	int contador = 0;

	strcpy(fichero, cine);
	strcat(fichero, "Cartelera.txt");

	f = fopen(fichero, "r");

	//lonCharCine = ch - '0';

	cart.cine = malloc(sizeof(char)*TAMANYO_tit);

	numPelis = (lineasFichero(fichero)-1)/2;
	cart.numPelis = numPelis;

	cart.peliculas = malloc(sizeof(Pelicula)*numPelis);


	char buff[255];

	fscanf(f, "%s", buff);
	strcpy(cart.cine, buff);


	while((ch = fgetc(f)) != EOF)
	{
		cart.peliculas[contador].titulo = malloc (sizeof(char)*TAMANYO_tit);
		fscanf(f, "%s", buff);
		strcpy(cart.peliculas[contador].titulo,buff);

		cart.peliculas[contador].titulo = malloc (sizeof(char)*TAMANYO_descr);
		fscanf(f, "%s", buff);
		strcpy(cart.peliculas[contador].descripcion,buff);

		contador++;

	}

	cart.numPelis = contador;

	return cart;

}

void anyadirPelicula(Cartelera *cartelera, Pelicula peli)
{
	int numPelis2 = cartelera->numPelis+1;
	Cartelera *carte = (Cartelera*)malloc(numPelis2* sizeof(Cartelera));

	for(int i = 0; i<numPelis2;i++)
	{
		if (i==numPelis2-1)
		{
			(carte->peliculas[i]).titulo = peli.titulo;
			(carte->peliculas[i]).descripcion = peli.descripcion;
		}
		else
		{
			(carte->peliculas[i]).titulo = (cartelera->peliculas[i]).titulo;
			(carte->peliculas[i]).descripcion = (cartelera->peliculas[i]).descripcion;
		}
	}

	cartelera->numPelis=numPelis2;
	cartelera->peliculas = carte->peliculas;
	printf("La pelicula se ha anyadido a la cartelera\n");

}


void quitarPelicula(Cartelera *cartelera, Pelicula PeliABorrar)
{
	int numPelis2 = cartelera->numPelis +1;
	Cartelera *carte = (Cartelera*)malloc(numPelis2* sizeof(Cartelera));

	for(int i=0; i<numPelis2; i++)
	{
		if(strcpy(PeliABorrar.titulo, (carte->peliculas[i]).titulo))
		{
			(carte->peliculas[i]).titulo = (carte->peliculas[i-1].titulo);
			(carte->peliculas[i]).descripcion = (carte->peliculas[i-1]).descripcion;
			numPelis2--;
		}
	}

	cartelera->numPelis = numPelis2;
	printf("La pelicula se ha borrado de la cartelera\n");
}

int lineasFichero(char *fichero)
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;

    fileptr = fopen(fichero, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.
    printf("There are %d lines in in a file\n", count_lines);

    return count_lines;
}

