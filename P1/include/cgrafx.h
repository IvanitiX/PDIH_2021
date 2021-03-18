#ifndef CGA_GRAPHICS
#define CGA_GRAPHICS

#include "conint.h"

void pixel(int x, int y, BYTE C);
void lineaHorizontal(int xInicio, int xFinal, int y, int color);
void lineaVertical(int yInicio, int yFinal, int x, int color);
void pintarRectangulo(int xInicio, int xFinal, int yInicio, int yFinal, int color);
void lineaDiagonalDerecha(int xInicio, int yInicio, int xFinal, int color);
void lineaDiagonalIzquierda(int xInicio, int yInicio, int xFinal, int color);
void pintarTriangulo(int xyPunta, int altura, int base,int color);

void pixel(int x, int y, BYTE C){
   union REGS inregs, outregs;
   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = C;
   inregs.h.ah = 0x0C;
   int86(MONITORINT, &inregs, &outregs);
}

void lineaHorizontal(int xInicio, int xFinal, int y, int color){
	int iter;
	for (iter=xInicio ; iter < xFinal ; iter++){
		pixel(iter,y,color);
	}
}

void lineaVertical(int yInicio, int yFinal, int x, int color){
	int iter;
	for (iter=yInicio ; iter < yFinal ; iter++){
		pixel(x,iter,color);
	}
}

void lineaDiagonalIzquierda(int xInicio, int yInicio, int xFinal, int color){
    int x ;
    int y ;
    y = yInicio;
    for (x = xInicio ; x >= xFinal ; x-- ){
        pixel(x,y,color);
        y--;
    }
}

void lineaDiagonalDerecha(int xInicio, int yInicio, int xFinal, int color){
    int x ;
    int y ;
    y = yInicio;
    for (x = xInicio ; x <= xFinal ; x++ ){
        pixel(x,y,color);
        y--;
    }
}

void pintarRectangulo(int xInicio, int xFinal, int yInicio, int yFinal, int color){
    lineaHorizontal(xInicio,xFinal,yInicio,color);
    lineaVertical(yInicio,yFinal,xInicio,color);
    lineaHorizontal(xInicio,xFinal,yFinal,color);
    lineaVertical(yInicio,yFinal,xFinal,color);
}

void pintarTriangulo(int xyPunta, int altura, int base,int color){
    int xBase0, xBaseF, yBase ;
    xBase0 = xyPunta - (base/2);
    xBaseF = xyPunta + (base/2);
    yBase = xyPunta + altura;
    lineaHorizontal(xBase0,xBaseF,yBase,color);
    lineaDiagonalDerecha(xBase0,yBase,xyPunta,color);
    lineaDiagonalIzquierda(xBaseF,yBase,xyPunta,color);
}



#endif