import json
import os
from ibm_watson import SpeechToTextV1
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator
from dotenv import load_dotenv

class ReconocimientoVoz:
    
    def __init__(self):
        #Cargamos del archivo .env la clave y URL de IBM Watson
        load_dotenv()
        API_KEY = os.getenv('API_KEY_SR')
        URL = os.getenv('URL_SR')

        #Creamos el autenticador y SR
        self.autenticador = IAMAuthenticator(API_KEY)
        self.reconocedor = SpeechToTextV1(authenticator=self.autenticador)
        self.reconocedor.set_service_url(URL)

        #Variables de instancio
        self.tipoAudio = 'audio/wav'
        self.margenAlternativas = 0.9
        self.modeloReconocimiento = 'es-ES_BroadbandModel'
        self.resultado = ""
    
    def transcribirAudio(self,path):
        with open(path,'rb') as archivoAudio:
            self.resultado = self.reconocedor.recognize(
                audio = archivoAudio,
                contentType = self.tipoAudio,
                word_alternatives_threshold = self.margenAlternativas,
                model = self.modeloReconocimiento
            ).get_result()
        #print(json.dumps(self.resultado, indent=2))
    
    def setTipoAudio(self,extensionMIME):
        if 'audio/' in extensionMIME:
            self.tipoAudio = extensionMIME
    
    def setModelo(self, modelo):
        if ('BroadbandModel' in modelo) or ('NarrowbandModel' in modelo):
            self.modelo_reconocimiento = modelo
    
    def setMargenAlternativas(self, margen):
        if (margen < 1):
            self.margenAlternativas = margen

    def getAlternatives(self):
        return self.resultado["results"][0]["alternatives"]

    def getBestTranscript(self):
        alternativas = self.getAlternatives()
        mejorTranscripcion = " "
        mejorConfianza = 0.0

        for i in alternativas:
            if (i["confidence"] >= mejorConfianza):
                mejorTranscripcion = i["transcript"]
                mejorConfianza = i["confidence"]
        
        return mejorTranscripcion


