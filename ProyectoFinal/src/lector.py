import os
from ibm_watson import TextToSpeechV1
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator
from dotenv import load_dotenv

class TextoAVoz:
    def __init__(self):
        #Cargamos del archivo .env la clave y URL de IBM Watson
        load_dotenv()
        API_KEY = os.getenv('API_KEY_TTS')
        URL = os.getenv('URL_TTS')

        #Creamos el autenticador y SR
        self.autenticador = IAMAuthenticator(API_KEY)
        self.lector = TextToSpeechV1(authenticator=self.autenticador)
        self.lector.set_service_url(URL)

        #Variables de instancio
        self.tipoAudio = 'audio/wav'
        self.texto = "Hola Mundo"
        self.vozHablada = 'es-ES_LauraV3Voice'

    
    def sintetizar(self,path):
        with open(path,'wb') as archivoAudio:
            archivoAudio.write(
                self.lector.synthesize(
                    self.texto,
                    accept = self.tipoAudio,
                    voice = self.vozHablada
                ).get_result().content
            )

    def setTipoAudio(self,extensionMIME):
        if 'audio/' in extensionMIME:
            self.tipoAudio = extensionMIME

    def setVoz(self,voz):
        if 'Voice' in voz:
            self.vozHablada = voz

    def setTexto(self,texto):
        self.texto = texto
