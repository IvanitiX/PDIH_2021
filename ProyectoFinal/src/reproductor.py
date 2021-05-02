import pyaudio
import wave
import os

class Reproductor:
    CHUNK_SIZE = 1024

    def __init__(self):
        self.p = pyaudio.PyAudio()

    def reproducir(self,path):
        archivo = wave.open(path,'rb')

        stream = self.p.open(
            format = self.p.get_format_from_width(archivo.getsampwidth()),
            channels = archivo.getnchannels(),
            rate = archivo.getframerate(),
            output = True
        )

        datos = archivo.readframes(self.CHUNK_SIZE)

        while len(datos) > 0:
             # writing to the stream is what *actually* plays the sound.
            stream.write(datos)
            datos = archivo.readframes(self.CHUNK_SIZE)
        
        self.p.close(stream)
        print("Ha acabado la reproducción")
    
