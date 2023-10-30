# Importa as bibliotecas necessarias
from smbus import SMBus # ou from smbus import SMBus
import time

#======================================================================
bus = SMBus(1) # Cria o objeto para comunicacao I2C
try:
	while 1: # Mantem o codigo ate Ctrl C
		b = bus.read_byte(0x08) # Solicita um valor do dispositivo 8 (Arduino)
		print(b) # Escreve o valor recebido no terminal
		time.sleep(0.1)
except KeyboardInterrupt as e:
	print("Fechando")
#======================================================================

