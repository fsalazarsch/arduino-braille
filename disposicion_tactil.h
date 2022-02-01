/*
	** DIAGRAMA **
	==============

	A  B	G  H
	C  D	I  J
	E  F	K  L

	M  M
	O  P
	Q  R

*/
//sacado de aqui: https://es.wikipedia.org/wiki/Braille_(lectura)#/media/Archivo:Braille_code_dimensions.jpg

//distancia en milimetros

float dist_A_B = 2.5;
float dist_A_C = 2.5;
float dist_A_E = 6.2;
float dist_C_E = 6.2 - 2.5;
float dist_E_K = 6.0;
float dist_F_K = 6.0 - 2.5; //dist del simbolo misma linea
float dist_A_M = 10.0;
float dist_E_M = 10 - 6.2; //dist entre lineas
float profundidad = 0.5; //profundidad del punzóne lineas
float diametro_punto = 1.2; //diametro de cada punto


//pasan un texto escrito en braile para disponer como impresión

/*
	CODIGOS DACTLOGRAFIA
	====================

	(1) (4)
	(2) (5)
	(3) (6)

*/

//emparejaremos cada codigo con su opuesto para escribir




int strpos(wchar_t *hay, wchar_t needle, int offset)
{
   wchar_t haystack[wcslen(hay)];
   wmemcpy(haystack, hay+offset, wcslen(hay)-offset);
   wchar_t *p = wcschr(haystack, needle);
   if (p)
      return p - haystack+offset;
   return -1;
}


wchar_t *reflejar( wchar_t *str){
	
	wchar_t *braille_unicode = L"⠀⠁⠂⠃⠄⠅⠆⠇⠈⠉⠊⠋⠌⠍⠎⠏⠐⠑⠒⠓⠔⠕⠖⠗⠘⠙⠚⠛⠜⠝⠞⠟⠠⠡⠢⠣⠤⠥⠦⠧⠨⠩⠪⠫⠬⠭⠮⠯⠰⠱⠲⠳⠴⠵⠶⠷⠸⠹⠺⠻⠼⠽⠾⠿";
	wchar_t *opuesto_unicode = L"⠀⠈⠐⠘⠠⠨⠰⠸⠁⠉⠑⠙⠡⠩⠱⠹⠂⠊⠒⠚⠢⠪⠲⠺⠃⠋⠓⠛⠣⠫⠳⠻⠄⠌⠔⠜⠤⠬⠴⠼⠅⠍⠕⠝⠥⠭⠵⠽⠆⠎⠖⠞⠦⠮⠶⠾⠇⠏⠗⠟⠧⠯⠷⠿";

	int length = wcslen(str);
	
	int last_pos = length-1;

	wchar_t *wchr = NULL;
	wchr = (wchar_t *)malloc((length + 1) * sizeof(wchar_t));
	
	for(int i = 0; i < length; i++){
		int pos = strpos(braille_unicode, str[i], 0);
	    wchr[last_pos-i] = opuesto_unicode[pos];
		}
	
	return wchr;
}

