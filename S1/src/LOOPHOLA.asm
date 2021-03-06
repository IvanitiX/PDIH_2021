pila segment stack 'stack'
	dw 100h dup (?)
pila ends
datos segment 'data'
	msg db 'hola$'
datos ends
codigo segment 'code'
	assume cs:codigo, ds:datos, ss:pila
	main PROC
		mov ax,datos
		mov ds,ax
    
        mov cx,0

    bucle:
		mov dx,OFFSET msg
		mov ah,9
		int 21h
        add cx,1        
        
        cmp cx,7
        jnz bucle

		mov ax,4C00h
		int 21h
	main ENDP
codigo ends

END main
