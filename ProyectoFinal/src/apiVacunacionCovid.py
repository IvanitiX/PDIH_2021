import urllib3
import json
import re

class VacunacionCovid:
    URL = "https://covid-vacuna.app/data/latest.json"
    def __init__(self):
        self.http = urllib3.PoolManager()
        self.peticion = self.http.request('GET',self.URL)
        if (self.peticion.status == 200):
            self.jsonInfo = json.loads(self.peticion.data.decode('utf-8'))

    def getEstadoVacunacionGeneral(self):
        jsonTotal = 0
        for ccaa in self.jsonInfo:
            if ccaa['ccaa'] == "Totales":
                jsonTotal = ccaa
        if (jsonTotal != 0):
            vacunacionUnaDosis = int(float(str(jsonTotal['porcentajePoblacionAdministradas'])[0:4:1])*100)
            vacunacionCompleta = int(float(str(jsonTotal['porcentajePoblacionCompletas'])[0:4:1])*100)
            vacunacionUnaDosis -= vacunacionCompleta
            frase = f"En España, se ha vacunado el {vacunacionUnaDosis} % con una dosis y el {vacunacionCompleta} % con las dos."
        else:
            frase = "Lo siento, no he oído bien a qué región de España te refieres. Repítalo con claridad, por favor."
        return frase

    def getEstadoVacunacionCCAA(self,comunidad):
        jsonCCAA = 0
        for ccaa in self.jsonInfo:
            nombre = ccaa['ccaa'].split(' ')
            if len(nombre) > 1:
                nombre = nombre[len(nombre) -1]
            else:
                nombre = nombre[0]
            if re.search(self.normalize(nombre), self.normalize(comunidad) , re.IGNORECASE):
                jsonCCAA = ccaa
        if (jsonCCAA != 0):
            nombre = jsonCCAA['ccaa']
            vacunacionUnaDosis = int(float(str(jsonCCAA['porcentajePoblacionAdministradas'])[0:4:1])*100)
            vacunacionCompleta = int(float(str(jsonCCAA['porcentajePoblacionCompletas'])[0:4:1])*100)
            vacunacionUnaDosis -= vacunacionCompleta
            frase = f"En {nombre}, se ha vacunado el {vacunacionUnaDosis} % con una dosis y el {vacunacionCompleta} % con las dos."
        else:
            frase = "Lo siento, no he oído bien a qué región de España te refieres. Repítalo con claridad, por favor."
        return frase

    def normalize(self,s):
        replacements = (
            ("á", "a"),
            ("é", "e"),
            ("í", "i"),
            ("ó", "o"),
            ("ú", "u"),
        )
        for a, b in replacements:
            s = s.replace(a, b).replace(a.upper(), b.upper())
        return s
        