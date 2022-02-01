#include "ws_functions.h"
//funciones para pasar de una cadena de texto a braille

//los ordinales no aparecerán para no entorpecer la regla de los grados

int a[6] = { 0,1,0,0,0,0};
int b[6] = { 0,1,0,1,0,0};
int c[6] = { 1,1,0,0,0,0};
int d[6] = { 1,1,1,0,0,0};
int e[6] = { 0,1,1,0,0,0};
int f[6] = { 1,1,0,1,0,0};
int g[6] = { 1,1,1,1,0,0};
int h[6] = { 0,1,1,1,0,0};
int i[6] = { 1,0,0,1,0,0};
int j[6] = { 1,0,1,1,0,0};
int k[6] = { 0,1,0,0,0,1};
int l[6] = { 0,1,0,1,0,1};
int m[6] = { 1,1,0,0,0,1};
int n[6] = { 1,1,1,0,0,1};
int ñ[6] = { 1,1,1,1,1,0};
int o[6] = { 1,0,1,0,0,1};
int p[6] = { 1,1,0,1,0,1};
int q[6] = { 1,1,1,1,0,1};
int r[6] = { 0,1,1,1,0,1};
int s[6] = { 1,0,0,1,0,1};
int t[6] = { 1,0,1,1,0,1};
int u[6] = { 0,1,0,0,1,1};
int v[6] = { 0,1,0,1,1,1};
int w[6] = { 1,0,1,1,1,0};
int x[6] = { 1,1,0,0,1,1};
int y[6] = { 1,1,1,0,1,1};
int z[6] = { 0,1,1,0,1,1};

//acentos y dieresis
int á[6] = { 0,1,1,1,1,1};
int é[6] = { 1,0,0,1,1,1};
int í[6] = { 1,0,0,0,0,1};
int ó[6] = { 1,0,0,0,1,1};
int ú[6] = { 1,0,1,1,1,1};
int ü[6] = { 0,1,1,1,1,0};
int ç[6] = { 1,1,0,1,1,1};

//espacio en blanco
int bks[6] = { 0,0,0,0,0,0};

//sintaxis
int coma[6] = { 0,0,0,1,0,0};
int punto[6] = { 0,0,0,0,0,1};
int ptocoma[6] = { 0,0,0,1,0,1};
int dospts[6] = { 0,0,1,1,0,0};
int guion[6] = { 0,0,0,0,1,1};
int excl[6] = { 0,0,1,1,0,1};
int preg[6] = { 0,0,0,1,1,0};

//parentesis
int abre_parentesis[6] = { 0,1,0,1,1,0};
int cierra_parentesis[6] = { 1,0,1,0,0,1};
int abre_parentesis_cuad[6] = { 0,1,1,1,1,1};
int cierra_parentesis_cuad[6] = { 1,0,1,1,1,1};
//int abre_parentesis_llave[12] = { 0,1,0,1,0,1, 0,0,1,0,0,0}; // --> @l
//int cierra_parentesis_llave[12] = { 0,0,0,1,0,0, 1,0,1,0,1,0}; // --> |,


//comillas
int comilla_doble[6] = { 0,0,0,1,1,1};
int apostrofe[6] = { 0,0,0,0,1,0};
int acento[6] = {0,1,1,1,1,0}; // es el signo ´

//signos
int grados[6] = { 0,0,1,0,1,1};
int barra_horizontal[6] = { 1,0,1,0,1,0};
//int barra_invertida[12] = {0,0,0,0,0,1, 0,0,1,0,0,0}; // --> @.
//int barra_oblicua[12] = {0,0,0,1,0,0, 0,0,0,0,1,0};  // --> ',
int asterisco[6] = {0,0,1,0,0,1};
int underscore[6] = {0,0,0,0,1,0};
//para los numeros romanos luego de los mil poner ':'

//signos monetarios

//int euro[12] = {0,1,1,0,0,0, 1,0,1,0,1,0}; // --> |e
//int centimo[12] = {0,1,1,0,0,0, 1,0,1,0,0,0};// -> └e
//int libra[12] = {1,0,0,1,1,1, 0,0,1,0,0,0}; // -->  @é
//int dolar[12] = {1,0,0,1,0,1, 1,0,1,0,1,0}; // --> |s

int linea_corta[6] = {1,0,1,0,0,0};

//signos matematicos
int suma[6] = {0,0,1,1,0,1};
//int mas o menos  +:-
int igual[6] = {0,0,1,1,1,1};
int multiplicado[6] = {0,0,0,1,1,1};
int dividido[6] = {0,0,1,1,1,0};
int mayor[6] = {0,1,1,0,0,1}; // >
int menor[6] = {1,0,0,1,1,0}; // <
//int no_igual[12] = {0,0,1,1,1,1, 1,0,1,0,0,0}; // └=
//int porcentaje[12] = {0,0,1,0,1,1, 1,0,1,0,1,0}; // --> |º
int raices[6] = {0,1,1,0,1,0}; 
int techo[6] = {1,1,0,1,1,0};
//para las raices cubicas se pone el 3 entremedio de ambos simbolos
// el contendio de la raiz se pone después
// √3¬x, es raiz cubica de x

int arroba[6] = {0,0,1,0,0,0};
//int ampersand[12] = {1,1,0,1,1,1, 0,0,0,0,1,0}; //--> 'ç
//int hash[6] es el numeral


//exclusivos braille
int mayus[6] = { 1,0,0,0,1,0};
int numeral[6] = { 1,0,1,0,1,1};
int separador_numeros[6] = { 0,0,1,0,0,0};
//el arroba, el separador de numeros y la cursiva se escriben con esto

int subindice[6] = { 1,0,0,0,0,1}; //í
int superindice[6] = {0,1,0,0,1,0}; // será ¯
//sub indice es con * cuando es mas de un elemento
// ? y * son la entrada y salida

wchar_t subindice_izq[2] = L"'í";
wchar_t superindice_izq[2] = L"'¯";
wchar_t subescrito[2] = L"''";
wchar_t supeescrito[2] = L"¯¯";

// implementar tags
// <sub></sub>
// <sup></sup>
// <sub_izq></sub_izq>
// <sub_izq></sub_izq>
// <sub_escr></sub_escr>
// <sub_escr></sub_escr>


int * call(wchar_t ch){

	switch(ch){
	case 'a':
		return a;
	case 'b':
		return b;
	case 'c':
		return c;
	case 'd':
		return d;
	case 'e':
		return e;
	case 'f':
		return f;
	case 'g':
		return g;
	case 'h':
		return h;
	case 'i':
		return i;
	case 'j':
		return j;
	case 'k':
		return k;
	case 'l':
		return l;
	case 'm':
		return m;
	case 'n':
		return n;
	case L'ñ':
		return ñ;
	case 'o':
		return o;
	case 'p':
		return p;
	case 'q':
		return q;
	case 'r':
		return r;
	case 's':
		return s;
	case 't':
		return t;
	case 'u':
		return u;
	case 'v':
		return v;
	case 'w':
		return w;
	case 'x':
		return x;
	case 'y':
		return y;
	case 'z':
		return z;
	case ',':
		return coma;
	case '.':
		return punto;
	case ';':
		return ptocoma;
	case ':':
		return dospts;
	case '-':
		return guion;
	case L'¡':
		return excl;
	case '!':
		return excl;
	case L'¿':
		return preg;
	case '?':
		return preg;
	case '(':
		return abre_parentesis;
	case ')':
		return cierra_parentesis;
	case '[':
		return abre_parentesis_cuad;
	case ']':
		return cierra_parentesis_cuad;
	case ' ':
		return bks;
	case L'º':
		return grados;
	case L'ª':
		return a;
	case L'|':
		return barra_horizontal;
	case '"':
		return comilla_doble;
	case '\'':
		return apostrofe;
	case '*':
		return asterisco;
	case '_':
		return underscore;
	case L'´':
		return acento;
	case '+':
		return suma;
	case '=':
		return igual;
	case L'·':
		return multiplicado;
	case L'÷':
		return dividido;
	case '>':
		return mayor;
	case '<':
		return menor;
	case L'√':
		return raices;
	case L'¬':
		return techo;
	case '@':
		return arroba;
	case '#':
		return numeral;
	case L'ç':
		return ç;
	case L'¯':
		return superindice;
	case L'└':
		return linea_corta;
	case L'ƒ':
		return mayus;
	 default:
		return bks;
	}
	}
char * a_punto(int x, int y){

	if ((x == 0) && (y == 0))
		return "◦◦";
	if ((x == 1) && (y == 0))
		return "•◦";
	if ((x == 0) && (y == 1))
		return "◦•";
	if ((x == 1) && (y == 1))
		return "••";
	return " ";
	}

wchar_t *strip_tags(wchar_t *palabra){

	//sub indice es con * cuando es mas de un elemento
	// ? y * son la entrada y salida
	// se mantendrá todo con parentesis


	palabra = repl_wcs(palabra, L"<sub>", L"í?");
	palabra = repl_wcs(palabra, L"</sub>", L"*");
	palabra = repl_wcs(palabra, L"<sup>", L"¯?");
	palabra = repl_wcs(palabra, L"</sup>", L"*");

	palabra = repl_wcs(palabra, L"<sub_izq>", L"'í?");
	palabra = repl_wcs(palabra, L"</sub_izq>", L"*");
	palabra = repl_wcs(palabra, L"<sup_izq>", L"'¯?");
	palabra = repl_wcs(palabra, L"</sup_izq>", L"*");

	palabra = repl_wcs(palabra, L"<sub_izq>", L"''?");
	palabra = repl_wcs(palabra, L"</sub_izq>", L"*");
	palabra = repl_wcs(palabra, L"<sup_izq>", L"¯¯?");
	palabra = repl_wcs(palabra, L"</sup_izq>", L"*");
	
	return palabra;
	}
wchar_t *reepmplazar_caracteres_dobles(wchar_t *palabra){
	// resuelve los caracteres multiples 
	
	palabra = repl_wcs(palabra, L"{", L"@l");
	palabra = repl_wcs(palabra, L"}", L"|,");
	palabra = repl_wcs(palabra, L"\\", L"@.");
	palabra = repl_wcs(palabra, L"/", L"',");

	palabra = repl_wcs(palabra, L"€", L"|e");
	palabra = repl_wcs(palabra, L"¢", L"└e");
	palabra = repl_wcs(palabra, L"£", L"@é");
	palabra = repl_wcs(palabra, L"$", L"|s");

	palabra = repl_wcs(palabra, L"≠", L"└=");
	palabra = repl_wcs(palabra, L"%", L"|º");
	palabra = repl_wcs(palabra, L"&", L"'ç");

	palabra = repl_wcs(palabra, L"$", L"|s");
	palabra = repl_wcs(palabra, L"$", L"|s");

	palabra = repl_wcs(palabra, L"©", L"(C)");
	palabra = repl_wcs(palabra, L"®", L"(R)");
	palabra = repl_wcs(palabra, L"$", L"|s");
	palabra = repl_wcs(palabra, L"nº", L"n.o");
	palabra = repl_wcs(palabra, L"™", L"(TM)");

	return palabra;
	}
wchar_t *reepmplazar_numeros(wchar_t *palabra){

	int n,i, total_n = 0;
	wchar_t *aux;
	while (1 == swscanf(palabra + total_n, L"%*[^0123456789]%d%n", &i, &n)){
		total_n += n;
		wchar_t *snum2 = itoa(i, 10, 0);
		wchar_t *snum = itoa(i, 10, 1);

		snum = repl_wcs(snum, L"1", L"a");
		snum = repl_wcs(snum, L"2", L"b");
		snum = repl_wcs(snum, L"3", L"c");
		snum = repl_wcs(snum, L"4", L"d");
		snum = repl_wcs(snum, L"5", L"e");
		snum = repl_wcs(snum, L"6", L"f");
		snum = repl_wcs(snum, L"7", L"g");
		snum = repl_wcs(snum, L"8", L"h");
		snum = repl_wcs(snum, L"9", L"i");
		snum = repl_wcs(snum, L"0", L"j");
			
		palabra = repl_wcs(palabra, snum2, snum);
		}
		return palabra;
	}
wchar_t *mayus_a_minusculas(wchar_t *palabra){

	for (int i = 0; i< wcslen(palabra); i++){
		if (iswupper(palabra[i]) == 1 ) {

			wchar_t pal[] = L"  ";
			pal[0] = L'ƒ';
			pal[1] = towlower(palabra[i]);

			static wchar_t aux[1] = {0};
			aux[0] = palabra[i];			
			i+=1;
			palabra = repl_wcs(palabra, aux, pal);
		}
	}
	return palabra;
	}

wchar_t *tratamiento(wchar_t *palabra){
	//poner caracteres dobles con si simil en braille
	palabra = reepmplazar_caracteres_dobles(palabra);
	//quitar tags de sub y super indice
	palabra = strip_tags(palabra);
	// pasa los numeros a caracteres
	palabra = reepmplazar_numeros(palabra);
	//pasa las mayusculas a caracteres
	palabra = mayus_a_minusculas(palabra);
	//e invierte la cadena para ser pasada a braille
	palabra =reverse_wst(palabra);
	//printf("%ls\n", palabra);
	return palabra;
	}

void escribir(wchar_t *palabra){
	for (int i = 0; i< wcslen(palabra); i++){
		printf("%s ", a_punto(call(palabra[i])[0], call(palabra[i])[1]));
		}
	printf("\n");

	for (int i = 0; i< wcslen(palabra); i++){
		printf("%s ", a_punto(call(palabra[i]) [2], call(palabra[i])[3]));
		}
	printf("\n");
	for (int i = 0; i< wcslen(palabra); i++){
		printf("%s ", a_punto(call(palabra[i])[4], call(palabra[i])[5]));
		}
	printf("\n");	
	}






