TEXTO   EQU 3
GRAFICO EQU 4
BLANCO  EQU 3
ROSA    EQU 2
VERDE   EQU 1

;MACRO pausa_tecla
;espera la pulsacion de una tecla
pausa_tecla MACRO
        push ax
        mov ah,0   ;funcion para leer una tecla
        int 16h    ;interrupcion BIOS para teclado
        pop ax
ENDM

;MACRO modo_video
;cambia el modo de video (texto-3 o grafico-4)
modo_video MACRO modo
        push ax
        mov al,modo
        mov ah,0
        int 10h
        pop ax
ENDM

;MACRO pixel
;pone un pixel en la coordenada X,Y de color C
pixel MACRO X,Y,C
        push ax
        push cx
		push dx
		mov ax,Y
		mov cx,X
		mov dx,ax
        mov al,C
        mov ah,0Ch
        int 10h
        pop dx
        pop cx
		pop ax
ENDM

pila segment stack 'stack'
	dw 100h dup (?)
pila ends

datos segment 'data'
		msg_pulsa_tecla db 'pulsa para continuar...',7,'$'
datos ends


codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax

		mov dx,OFFSET msg_pulsa_tecla
		mov ah,9
		int 21h
		pausa_tecla

		modo_video GRAFICO


        ;letra I
		;pintar una linea horizontal
		mov cx,50
		bucle1:
			pixel cx,40,VERDE
			dec cx
			jnz bucle1

        ;pintar otra linea horizontal
		mov cx,50
		bucle1bis:
			pixel cx,80,VERDE
			dec cx
			jnz bucle1bis

		;pintar una linea vertical
		mov cx,80
		bucle2:
			pixel 25,cx,ROSA
			dec cx
            cmp cx,40
			jnz bucle2

        ;letra V
		;pintar una linea diagonal ascendente izq
		mov cx,80
        mov dx,100
		bucle3:
			pixel dx,cx,BLANCO
			dec cx
            dec dx
            cmp cx,40
			jnz bucle3

        ;pintar una linea diagonal ascendente der
		mov cx,80
        mov dx,100
		bucle3bis:
			pixel dx,cx,BLANCO
			dec cx
            inc dx
            cmp cx,40
			jnz bucle3bis

        ; letra A
        ;pintar una linea diagonal ascendente der
		mov cx,80
        mov dx,120
		bucle3tris:
			pixel dx,cx,BLANCO
			dec cx
            inc dx
            cmp cx,40
			jnz bucle3tris

        ;pintar una linea diagonal ascendente izq
		mov cx,80
        mov dx,200
		bucle3tetrakis:
			pixel dx,cx,BLANCO
			dec cx
            dec dx
            cmp cx,40
			jnz bucle3tetrakis

        ;pintar la linea horizontal de la A
		mov cx,180
		bucle1tris:
			pixel cx,60,VERDE
			dec cx
            cmp cx,140 
			jnz bucle1tris

       ;letra N
        ;pintar una linea vertical
		mov cx,80
		bucle2bis:
			pixel 210,cx,ROSA
			dec cx
            cmp cx,40
			jnz bucle2bis

        ;pintar otra linea vertical
		mov cx,80
		bucle2tris:
			pixel 250,cx,ROSA
			dec cx
            cmp cx,40
			jnz bucle2tris

        ;pintar una linea diagonal ascendente izq
		mov cx,80
        mov dx,250
		bucle3pentatris:
			pixel dx,cx,BLANCO
			dec cx
            dec dx
            cmp dx,210
			jnz bucle3pentatris


       


		pausa_tecla
		modo_video TEXTO

		mov ax,4C00h
		int 21h
	main ENDP
codigo ends

END main
