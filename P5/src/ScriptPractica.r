# Script de la práctica

#Carga de librerías
library(tuneR)
library(seewave)
library(audio)

#Path de trabajo
setwd("C:/Users/Ivan/Desktop/Clase/PDIH/P5/aud")

#Carga de archivos
perro <- readWave("perro.wav")
oveja <- readWave("oveja.wav")

#Comprobamos que estén cargados
perro
oveja

# Dibujamos su onda
plot(extractWave(perro,from = 1, to = length(perro@left)),col = "green" )
plot(extractWave(oveja,from = 1, to = length(oveja@left)),col = "cyan")

#Unir sonidos
union <- pastew(perro,oveja,output="Wave")
f <- perro@samp.rate

#Dibujamos la onda unida
plot(extractWave(union,from = 1, to = length(union@left)),col = "red")

#Pasamos el filtro de frecuencia
filtrado <- bwfilter(union, f=f, channel=1, n=1, from=10000, to=20000, bandpass=TRUE, listen=FALSE, output = "Wave")

#Dibujamos la onda filtrada
plot(extractWave(filtrado,from = 1, to = length(filtrado@left)),col = "blue" )

#Guardamos el resultado
savewav(filtrado,f=filtrado@samp.rate)

#Se lee un nuevo archivo
vaca <- readWave("vaca.wav")
vaca
plot(extractWave(vaca,from = 1, to = length(vaca@left)),col = "purple")

#Ponemos eco
vacaEco <- echo(vaca,f=vaca@samp.rate,amp = c(0.9,0.6,0.3), delay = c(2,4,6), output = "Wave")
str(vacaEco)
plot(extractWave(vacaEco,from = 1, to = length(vacaEco@left)),col = "pink")

#Y lo ponemos al revés
vacaEcoReverse <- revw(vacaEco, output = "Wave")
str(vacaEcoReverse)
plot(extractWave(vacaEcoReverse,from = 1, to = length(vacaEcoReverse@left)),col = "orange")

#Guardamos el resultado
savewav(vacaEcoReverse,f=vacaEcoReverse@samp.rate)


