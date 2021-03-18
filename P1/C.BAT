@echo off

REM  compila el archivo que se le pasa como parámetro (sin extensión)

BCC -Ic:\BC\INCLUDE -Ic:\P1\INCLUDE -Lc:\BC\LIB	%1.C

