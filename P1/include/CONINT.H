#ifndef CONSOLE_INTS
#define CONSOLE_INTS

#include <dos.h>

#define BYTE unsigned char

//Alias para las interrupciones
#define DOSINT 0x21
#define MONITORINT 0x10
#define KEYBINT 0x16

//Alias para los modos de v�deo
BYTE MODO_TEXTO = 3;
BYTE MODO_GRAFICO = 4;

//Alias para los estilos de cursor
#define CURSOR_INVISIBLE 0
#define CURSOR_NORMAL 1
#define CURSOR_GRUESO 2

//Alias para los colores
//Colores de texto
#define BLACK_TEXT 0x00
#define BLUE_TEXT   0x01
#define GREEN_TEXT 0x02
#define CYAN_TEXT 0x03
#define RED_TEXT 0x04
#define MAGENTA_TEXT 0x05
#define BROWN_TEXT 0x06
#define LIGHTGRAY_TEXT 0x07
#define DARKGRAY_TEXT 0x08
#define LIGHTBLUE_TEXT 0x09
#define LIGHTGREEN_TEXT 0x0A
#define LIGHTCYAN_TEXT 0x0B
#define LIGHTRED_TEXT 0x0C
#define LIGHTMAGENTA_TEXT 0x0D
#define YELLOW_TEXT 0x0E
#define WHITE_TEXT 0x0F
#define BLINK_TEXT 0X80

//Colores de fondo
#define BLACK_BG 0x00
#define BLUE_BG 0x10
#define GREEN_BG 0x20
#define CYAN_BG 0x30
#define RED_BG 0x40
#define MAGENTA_BG 0x50
#define BROWN_BG 0x60
#define LIGHTGRAY_BG 0x70

int foreground = LIGHTGRAY_TEXT;
int background = BLACK_BG;



/*Declaraci�n de funciones*/
void goToXY(int x, int y);
void pausa();
void setCursorType(int type);
void setVideoMode(int mode);
int getVideoMode();
void setTextColor();
void setTextBackground();
void clearScreen();
void putChar(char c);
void colorPutChar(char c);
char getChar();
char getchE();

/*Y ahora, las implementaciones*/

void goToXY(int x, int y){
		union REGS inregs, outregs;
		inregs.h.dl = x ;
		inregs.h.dh = y ;
		inregs.h.bh = 0 ;
		inregs.h.ah = 2 ;
		int86(MONITORINT, &inregs, &outregs);
}

void pausa(){
	 union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(DOSINT, &inregs, &outregs);
}

void setCursorType(int type){
		union REGS inregs,outregs;
		inregs.h.ah = 0x01;
		switch(type){
			case CURSOR_INVISIBLE:
				inregs.h.ch = 010 ;
				inregs.h.cl = 000 ;
			break;
			case CURSOR_NORMAL:
				inregs.h.ch = 010 ;
				inregs.h.cl = 010 ;
			break;
			case CURSOR_GRUESO:
				inregs.h.ch = 000 ;
				inregs.h.cl = 010 ;
			break;
		}
		int86(MONITORINT,&inregs,&outregs);
}

void setVideoMode(int mode){
        union REGS inregs,outregs;
		inregs.h.ah = 0;
		inregs.h.al = mode;
		int86(MONITORINT, &inregs, &outregs);
}

int getVideoMode(){
		union REGS inregs,outregs;
		inregs.h.ah = 0xF;
		int86(MONITORINT, &inregs, &outregs);
		return outregs.h.al;
}

void setTextColor(int color){
    foreground = color;
}

void setTextBackground(int color){
    background = color;
}

void clearScreen(){
    setVideoMode(MODO_GRAFICO);
    setVideoMode(MODO_TEXTO);
}


void putChar(char c){
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(DOSINT, &inregs, &outregs);
}

void colorPutChar(char c){
    union REGS inregs, outregs;

	 inregs.h.ah = 9;
     inregs.h.al = c ;
	 inregs.h.bl = foreground+background;
	 inregs.h.bh = 0;
	 inregs.x.cx = 1;
	 int86(MONITORINT, &inregs, &outregs);
}


char getChar(){
     union REGS inregs, outregs;
	 int caracter;

	 inregs.h.ah = 0;
	 int86(KEYBINT, &inregs, &outregs);

	 caracter = outregs.h.al;
	 return caracter;
}

char getchE(){
	char c = getChar();
    putChar(c);
    return c;
}


#endif
