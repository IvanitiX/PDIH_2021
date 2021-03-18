#include "cgrafx.h"

int main(){
	setVideoMode(MODO_GRAFICO);

	lineaHorizontal(0,319,170,1);
	lineaVertical(170,199,140,1);
	lineaVertical(170,199,180,1);

	pintarRectangulo(40,80,120,169,2);
	pintarTriangulo(50,30,70,1);
	pintarTriangulo(60,60,100,1);

	pintarTriangulo(150,20,60,3);
	lineaVertical(100,140,150,3);
	lineaHorizontal(130,180,100,3);
	pintarRectangulo(140,170,70,99,3);
	lineaHorizontal(150,160,85,3);
	pixel(150,75,3);
	pixel(160,75,3);

	pausa();
	setVideoMode(MODO_TEXTO);

	return 0;
}