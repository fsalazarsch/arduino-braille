#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "braile.h"
#include "disposicion_tactil.h"
#include <string.h>

#ifdef WIN32
	#define CLEAR "cls"
	#define LS "dir"
	
#else
	#define CLEAR "reset"
	#define LS "ls"
#endif

void imprimir_menu();
void imprimir();
void desplegar_ayuda();
void traducir();

/* 
 1) buscar el reflejo de cada letra
 2) escribir el enunciado al revés
 3) 'imprimirlo' por pantalla
 4) transmitir órdenes para el arduino
*/


int main (int argc, char **argv){

	setlocale(LC_ALL, "en_US.UTF-8");
	//wchar_t str[] = L"el veloz murciélago hindú comía feliz cardillo y kiwi. La cigüeña tocaba el saxofón detrás del palenque de paja";
	//wchar_t *texto =L"⠆⠇⠈⠉⠊⠋⠌⠍⠎⠏⠐⠑⠒⠓";


	char opcion[2];
	do{
		system(CLEAR);
		imprimir_menu();
		printf("Escriba su opción:\t");
		scanf("%s", opcion);

		if (strcmp(opcion, "1") == 0 )
			imprimir();
		if (strcmp(opcion, "2") == 0 )
			traducir();
		if (strcmp(opcion, "3") == 0 )
			printf("Adios :D\n");
		if (strcmp(opcion, "*") == 0 )
			desplegar_ayuda();
	}while (strcmp(opcion, "3") != 0);

	return 0;
}


void imprimir_menu(){
	printf("Bienvenido\nEscoge una de las siguientes opciones:\n");
	printf("1) Quiero una version para imprimir mi archivo en Braille\n");
	printf("2) Quiero 'traducir' un archivo a braille\n");
	printf("3) Salir\n");
	printf("*) Ayuda\n");
}

void desplegar_ayuda(){
	printf("\n\nDetalle opciones:\n");
	printf("1) Toma un archivo en braille para imprimirlo y poder usarlo para crear la escritura manualmente\n");
	printf("2) Toma un archivo en escritura simple para portearlo a braille imprimible\n\n");
	printf("===================================================================================\n");
	printf("Presione ENTER para contonuar ...");
	getchar();
	getchar();

}

void imprimir(){
	/* Genera una version imprimible para braille, 
		a partir de un archivo en braille */

	FILE *stream;
	FILE *out;
	wchar_t buffer[100];
	char filename[50];

	printf("Escriba la ruta de su archivo:\t");
	scanf("%s", filename);

	stream=fopen(filename,"r");
	out=fopen("output.dat","w+");
		
	while( !feof(stream)){
		fwscanf (stream, L"%ls\n", buffer);			
		fwprintf (out, L"%ls\n", reflejar(buffer));		
	}

	fclose(stream);
	fclose(out);

	printf("Se ha generado el archivo:\toutput.dat\n");
	printf("========================================\n");
	printf("Presione ENTER para contonuar ...");
	getchar();
	getchar();

}


void traducir(){
	int largo;
	FILE *stream;
	FILE *out, *temp;
	wchar_t c[255];
	char filename[50];

	printf("Escriba la ruta de su archivo:\t");
	scanf("%s", filename);

	largo = 16;
	wchar_t linea[largo];

	stream=fopen(filename,"r");
	temp=fopen("temp.dat","w+");
	out=fopen("output.dat","w+");

	//primero leer todo el texto y procesarlo
	while(fgetws(c, 255, stream)) {
		fwprintf(out, L"%ls", tratamiento(c));
		}

	fclose(stream);
	rewind(out);

	while(fgetws(linea, largo, out)) {
		for(int k=0; k< (largo-1); k++)
			if((linea[k] == L'\n') || (linea[k] == 0))
				linea[k] = L' ';

		fwprintf(temp, L"%ls\n", reverse_wst(linea));

		for(int k=0; k< (largo-1); k++)
			linea[k] = L' ';
	}
	
	rewind(temp);
	rewind(out);
	
	while(fgetws(linea, largo, temp)) {			
		escribir( out, linea );
		}

	remove("temp.dat");
	fclose(stream);
	fclose(out);	
	printf("Se ha generado el archivo:\toutput.dat\n");
	printf("========================================\n");
	printf("Presione ENTER para contonuar ...");
	getchar();	
	getchar();

}