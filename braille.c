#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "braile.h"
#include <locale.h>

/* 
 1) buscar el reflejo de cada letra
 2) escribir el enunciado al revés
 3) 'imprimirlo' por pantalla
 4) transmitir órdenes para el arduino
*/

//char * transcribir(char[]){
//}




int strpos(char *hay, char *needle, int offset)
{
   char haystack[strlen(hay)];
   strncpy(haystack, hay+offset, strlen(hay)-offset);
   char *p = strstr(haystack, needle);
   if (p)
      return p - haystack+offset;
   return -1;
}


int main (){


setlocale(LC_ALL, "en_US.UTF-8");

int index;


//wchar_t str[] = L"el veloz murciélago hindú comía feliz cardillo y kiwi. La cigüeña tocaba el saxofón detrás del palenque de paja";
//wchar_t str[] = L"el veloz murciélago hindú comía feliz cardillo";

wchar_t str[] = L"aaaaaa<BBBB>TEXT TO EXTRACT</BBBB>aaaaaaaaa";
  
//wchar_t wc = L'\x3b1';
wchar_t* s = L"aFElipe";
	

//strip_tags(str);

mayus_a_minusculas(s);
//for (int i = 0; i< wcslen(str); i++){
//	call( str[i] );
	//wprintf(L"%lc ", str[i]);
//}

//tratamiento( str );

//escribir( str );


return 0;
}