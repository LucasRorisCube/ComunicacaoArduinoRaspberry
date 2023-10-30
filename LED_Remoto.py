# Importa as bibliotecas necessarias
from smbus2 import SMBus
import time

#======================================================================
bus = SMBus(1) # Cria o objeto para comunicacao I2C
try:
	while True: # Mantem o codigo ate Ctrl C
		try:
			num1 = int(input("Digite o primeiro numero: ")) # Solicita input do usuario
			bus.write_byte(0x08, num1)	# Envia o input para o dispositivo 0x08 (Arduino) 
		except:
			print("Valor invalido")
except KeyboardInterrupt as e:
	print("Fechando")
#======================================================================

