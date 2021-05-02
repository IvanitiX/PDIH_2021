from array import array
from struct import pack
from sys import byteorder
import pyaudio
import wave

class Grabadora:
    THRESHOLD = 1500 
    CHUNK_SIZE = 1024
    SILENT_CHUNKS = 1 * 44100 / 1024  # about 3sec
    FORMAT = pyaudio.paInt16
    FRAME_MAX_VALUE = 2 ** 15 - 1
    NORMALIZE_MINUS_ONE_dB = 10 ** (-1.0 / 20)
    RATE = 44100
    CHANNELS = 1
    TRIM_APPEND = RATE / 4
    AUDIO_FOLDER_PATH = "../audio_buffer/"

    def enSilencio(self,data_chunk):
        """Returns 'True' if below the 'silent' threshold"""
        return max(data_chunk) < self.THRESHOLD

    def grabar(self):
        p = pyaudio.PyAudio()
        stream = p.open(format=self.FORMAT, channels=self.CHANNELS, rate=self.RATE, input=True, output=True, frames_per_buffer=self.CHUNK_SIZE)

        silent_chunks = 0
        audio_started = False
        data_all = array('h')

        while True:
            data_chunk = array('h', stream.read(self.CHUNK_SIZE))
            if byteorder == 'big':
                data_chunk.byteswap()
            data_all.extend(data_chunk)

            silent = self.enSilencio(data_chunk)

            if audio_started:
                if silent:
                    silent_chunks += 1
                    if silent_chunks > self.SILENT_CHUNKS:
                        break
                else: 
                    silent_chunks = 0
            elif not silent:
                print (">> Empezamos a grabar")
                audio_started = True              

        sample_width = p.get_sample_size(self.FORMAT)
        stream.stop_stream()
        stream.close()
        p.terminate()

        print (">>> Terminamos de grabar.")
        return sample_width, data_all

    def grabarAArchivo(self,path):
        sample_width, data = self.grabar()
        data = pack('<' + ('h' * len(data)), *data)

        wave_file = wave.open(self.AUDIO_FOLDER_PATH + path, 'wb')
        wave_file.setnchannels(self.CHANNELS)
        wave_file.setsampwidth(sample_width)
        wave_file.setframerate(self.RATE)
        wave_file.writeframes(data)
        wave_file.close()