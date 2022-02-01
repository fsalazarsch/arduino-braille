#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "braile.h"
#include "disposicion_tactil.h"

/* 
 1) buscar el reflejo de cada letra
 2) escribir el enunciado al revés
 3) 'imprimirlo' por pantalla
 4) transmitir órdenes para el arduino
*/


int main (){

setlocale(LC_ALL, "en_US.UTF-8");
//wchar_t str[] = L"el veloz murciélago hindú comía feliz cardillo y kiwi. La cigüeña tocaba el saxofón detrás del palenque de paja";

wchar_t *s = L"aFElipeÑ1ñ";
wchar_t *texto =L"⠆⠇⠈⠉⠊⠋⠌⠍⠎⠏⠐⠑⠒⠓";

	
s = tratamiento(s);
escribir( s );


printf("%ls\n", reflejar(texto));

return 0;
}