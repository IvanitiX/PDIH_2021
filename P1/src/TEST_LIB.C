#include "conint.h"
#include <stdio.h>

int main(){
        char teclaPulsada ; 
        goToXY(0,0);
        pausa();
        clearScreen();
        pausa();

		goToXY(20,20);
		pausa();

		printf("\n Invisible -> ");
		setCursorType(CURSOR_INVISIBLE);
		pausa();

		printf("\n Normal -> ");
		setCursorType(CURSOR_NORMAL);
		pausa();

		printf("\n Grueso -> ");
		setCursorType(CURSOR_GRUESO);
		pausa();

        setVideoMode(MODO_GRAFICO);
        pausa();
        setVideoMode(MODO_TEXTO);
        pausa();

		printf("\n Estamos en el modo de video -> %d", getVideoMode());
		pausa();

		printf("\n Prueba de color:\n");
        setTextColor(WHITE_TEXT);
        setTextBackground(BLUE_BG);
		colorPutChar('=');
		colorPutChar('=');
		pausa();
        setTextBackground(GREEN_BG);
        colorPutChar('=');
        colorPutChar('=');
        pausa();
        clearScreen();
        
        printf("\n Pulsa una tecla:\n");
        teclaPulsada = getchE();
        printf("\n Pulsaste %c \n" , teclaPulsada);
        pausa();
        

		return 0;
}
