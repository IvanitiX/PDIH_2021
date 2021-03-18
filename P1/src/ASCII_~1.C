#include "conint.h"

void paintRectangle(int bg, int fg, int x0, int y0, int xf, int yf){
	int x,y;

	goToXY(x0,y0);
	setTextColor(fg);
	setTextBackground(bg);

	for (y = y0 ; y <= yf ; y++){
		for (x = x0 ; x <=  xf ; x++){
			goToXY(x,y);
			if (x == x0 || y == y0 || x == xf || y == yf ){
				colorPutChar('*');
			}
			else{
				colorPutChar(' ');
			}
		}
	}
}


int main(){
	paintRectangle(BLUE_BG,WHITE_TEXT,0,0,20,20);
	pausa();
	paintRectangle(GREEN_BG,BLACK_TEXT,10,10,60,60);
	pausa();
	clearScreen();
	paintRectangle(MAGENTA_BG,MAGENTA_TEXT,0,0,9,9);
	paintRectangle(RED_BG,RED_TEXT,10,0,19,9);
	paintRectangle(CYAN_BG,CYAN_TEXT,20,0,29,9);
	paintRectangle(GREEN_BG,GREEN_TEXT,30,0,39,9);
	paintRectangle(LIGHTGRAY_BG,LIGHTGRAY_TEXT,0,5,39,5);
	paintRectangle(BLACK_BG,BLACK_TEXT,0,6,39,6);
	goToXY(19,6);
	setTextBackground(BLACK_BG);
	setTextColor(LIGHTGRAY_TEXT);
	colorPutChar('I');
	goToXY(20,6);
	colorPutChar('n');
	goToXY(21,6);
	colorPutChar('c');
	goToXY(22,6);
	colorPutChar('o');
	goToXY(23,6);
	colorPutChar('m');
	goToXY(24,6);
	colorPutChar('i');
	goToXY(25,6);
	colorPutChar('n');
	goToXY(26,6);
	colorPutChar('g');
	pausa();
	clearScreen();

	return 0;
}