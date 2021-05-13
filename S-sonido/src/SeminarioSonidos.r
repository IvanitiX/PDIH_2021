# Script del seminario

#Carga de librer�as
library(tuneR)
library(seewave)
library(audio)

#Path de trabajo
setwd("C:/Users/Ivan/Desktop/Clase/PDIH/S-sonido/aud")

#Carga de archivos
oveja <- readWave("oveja.wav")
perro <- readWave("perro.wav")

#Comprobamos que est�n cargados
oveja
perro

# Dibujamos su onda
plot(extractWave(oveja,from = 1, to = length(oveja@left)),col = "green" )
plot(extractWave(perro,from = 1, to = length(perro@left)),col = "cyan")

#Unir sonidos
union <- pastew(oveja,perro)

#O�r la uni�n (Frecuencia del sonido del perro)
f <- perro@samp.rate
listen(union, f=f)


#O�r la uni�n (Frecuencia del sonido de la oveja)
f <- oveja@samp.rate
listen(union, f=f)

#Guardar la uni�n
savewav(union, f=f, filename = file.path("mezcla.wav"))

