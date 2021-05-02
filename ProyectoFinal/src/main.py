"""
Archivo main.
"""
import sys
from os.path import join, dirname
from grabador import Grabadora
from reproductor import Reproductor
from reconocedor_voz import ReconocimientoVoz
from lector import TextoAVoz
from apiVacunacionCovid import VacunacionCovid

if __name__ == '__main__':

    #Nombre del dispositivo
    nombre = "pedro"

    #Declaraciones
    grabadora = Grabadora()
    reproductor = Reproductor()
    sr = ReconocimientoVoz()
    tts = TextoAVoz()
    infoCovid = VacunacionCovid()

    tts.setVoz("es-ES_EnriqueV3Voice")

    print("Empieza a hablar cuando quieras - Grabaremos mientras estés hablando")
    grabadora.grabarAArchivo('demo.wav')
    print(">> Se ha guardado el audio en demo.wav")
    sr.transcribirAudio("../audio_buffer/demo.wav")
    transcripcion = sr.getBestTranscript()
    print(">> Transcripción : " , transcripcion)

    if ("hola" in transcripcion) :
        tts.setTexto("Hola qué tal. ¿En qué puedo ayudarle?")
        tts.sintetizar("../audio_buffer/response.wav")
        reproductor.reproducir("../audio_buffer/response.wav")

    entenderJuego = False
    while entenderJuego == False:
        print("¿Quieres jugar a los animales o saber los contagios COVID? ")

        print("Empieza a hablar cuando quieras - Grabaremos mientras estés hablando")
        grabadora.grabarAArchivo('demo.wav')
        print(">> Se ha guardado el audio en demo.wav")
        sr.transcribirAudio("../audio_buffer/demo.wav")
        transcripcion = sr.getBestTranscript()
        print(">> Transcripción : " , transcripcion)

        
        if ("animales" in transcripcion):
            entenderJuego = True
            jugarAnimales = True
            while jugarAnimales:
                respuesta = "Jugaremos, ¿a quién quieres escuchar?"
                print (respuesta)

                tts.setTexto(respuesta)
                tts.sintetizar("../audio_buffer/response.wav")
                reproductor.reproducir("../audio_buffer/response.wav")

                print ("Di a quién quieres escuchar")
                grabadora.grabarAArchivo('demo.wav')
                print(">> Se ha guardado el audio en demo.wav")
                sr.transcribirAudio("../audio_buffer/demo.wav")
                transcripcion = sr.getBestTranscript()
                print(">> Transcripción : " , transcripcion)

                if ("búho" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/BUHO.wav")
                elif ("burro" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/BURRO.wav")
                elif ("caballo" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/CABALLO.wav")
                elif ("elefante" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/ELEFANTE.wav")
                elif ("gallina" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/GALLINA.wav")
                elif ("gallo" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/GALLO.wav")
                elif ("gato" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/GATO.wav")
                elif ("león" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/LEON.wav")
                elif ("lobo" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/LOBO.wav")
                elif ("mono" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/MONO.wav")
                elif ("mosca" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/MOSCA.wav")
                elif ("oveja" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/OVEJA.wav")
                elif ("pato" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/PATO.wav")
                elif ("pavo" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/PAVO.wav")
                elif ("perro" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/PERRO.wav")
                elif ("pollito" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/POLLITO.wav")
                elif ("rana" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/RANA.wav")
                elif ("toro" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/TORO.wav")
                elif ("vaca" in transcripcion):
                    reproductor.reproducir("../sonidos_animales/VACA.wav")
                else:
                    respuesta = "Perdona, no sé qué sonido hace ese animal."
                    print (respuesta)

                    tts.setTexto(respuesta)
                    tts.sintetizar("../audio_buffer/response.wav")
                    reproductor.reproducir("../audio_buffer/response.wav")

                respuestaSeguir = False
                while respuestaSeguir == False:
                    respuesta = "¿Quieres seguir jugando?"
                    print (respuesta)

                    tts.setTexto(respuesta)
                    tts.sintetizar("../audio_buffer/response.wav")
                    reproductor.reproducir("../audio_buffer/response.wav")

                    print ("Responde si o no, grabamos")
                    grabadora.grabarAArchivo('demo.wav')
                    print(">> Se ha guardado el audio en demo.wav")
                    sr.transcribirAudio("../audio_buffer/demo.wav")
                    transcripcion = sr.getBestTranscript()
                    print(">> Transcripción : " , transcripcion)

                    if ("si" in transcripcion or "sí" in transcripcion):
                        respuestaSeguir = True
                        respuesta = "¡Muy bien! Seguiremos jugando"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")
                    
                    elif ("no" in transcripcion):
                        respuestaSeguir = True
                        jugarAnimales = False
                        respuesta = "¡Vale! Terminamos de jugar"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")

                    else:
                        respuestaSeguir = False
                        respuesta = "Perdona, no te he entendido. Repite"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")

        elif ("vacunación" in transcripcion.lower()) or ("covid" in transcripcion.lower()):
            jugarCovid = True
            entenderJuego = True
            while jugarCovid:
                respuesta = "Ok, coméntame de qué Comunidad Autónoma quieres informarte, o si es en todo el país."
                print (respuesta)

                tts.setTexto(respuesta)
                tts.sintetizar("../audio_buffer/response.wav")
                reproductor.reproducir("../audio_buffer/response.wav")

                print ("Di la Comunidad Autónoma, o 'en total/en España' ")
                grabadora.grabarAArchivo('demo.wav')
                print(">> Se ha guardado el audio en demo.wav")
                sr.transcribirAudio("../audio_buffer/demo.wav")
                transcripcion = sr.getBestTranscript()
                print(">> Transcripción : " , transcripcion)

                if("total" in transcripcion.lower()) or ("españa" in transcripcion.lower()):
                    estado = infoCovid.getEstadoVacunacionGeneral()
                    print(estado)
                    tts.setTexto(estado)
                    tts.sintetizar("../audio_buffer/response.wav")
                    reproductor.reproducir("../audio_buffer/response.wav")
                else:
                    estado = infoCovid.getEstadoVacunacionCCAA(transcripcion)
                    print(estado)
                    tts.setTexto(estado)
                    tts.sintetizar("../audio_buffer/response.wav")
                    reproductor.reproducir("../audio_buffer/response.wav")
                
                respuestaSeguir = False
                while respuestaSeguir == False:
                    respuesta = "¿Alguna consulta más sobre la vacunación?"
                    print (respuesta)

                    tts.setTexto(respuesta)
                    tts.sintetizar("../audio_buffer/response.wav")
                    reproductor.reproducir("../audio_buffer/response.wav")

                    print ("Responde si o no, grabamos")
                    grabadora.grabarAArchivo('demo.wav')
                    print(">> Se ha guardado el audio en demo.wav")
                    sr.transcribirAudio("../audio_buffer/demo.wav")
                    transcripcion = sr.getBestTranscript()
                    print(">> Transcripción : " , transcripcion)

                    if ("si" in transcripcion or "sí" in transcripcion):
                        respuestaSeguir = True
                        respuesta = "¡Muy bien! Consultemos de nuevo"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")
                    
                    elif ("no" in transcripcion):
                        respuestaSeguir = True
                        jugarCovid = False
                        respuesta = "¡Vale! Terminamos de jugar"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")

                    else:
                        respuestaSeguir = False
                        respuesta = "Perdona, no te he entendido. Repite"
                        print (respuesta)

                        tts.setTexto(respuesta)
                        tts.sintetizar("../audio_buffer/response.wav")
                        reproductor.reproducir("../audio_buffer/response.wav")



        else:
            entenderJuego = False
            respuesta = "Perdona, no te he entendido. Repite"
            print (respuesta)

            tts.setTexto(respuesta)
            tts.sintetizar("../audio_buffer/response.wav")
            reproductor.reproducir("../audio_buffer/response.wav")      


    imprimir = "Eso es todo. ¡Adiós!"
    print(imprimir)
    tts.setTexto("Eso es todo. Adiós")
    tts.sintetizar("../audio_buffer/response.wav")
    reproductor.reproducir("../audio_buffer/response.wav")
        






