# ComunicacaoArduinoRaspberry

Projetos da disciplina de SEL0630 - Projetos em Sistemas Embarcados: Prática 4

# Nome dos integrantes:

Gabriel Vinicius dos Santos (11819424)

Lucas Alves Roris (11913771)

# Prática 4

Nessa prática foi desenvolvido um sistema capaz de utiliza um microcontrolador como o Arduino para ler dados de um potênciometro e transmitir por I2C para uma Raspberry Pi, já que por sua vez, ela não possui portas analógicas. Além de um programa que A Raspberry Pi controla o Arduino acendendo e apagando um LED com o comando do usuário.

## Leitura do Potenciômetro

Como sabemos, as portas da Raspiberry Pi 3B+ não possuem suporte ao analógico, ou seja, caso seja necessário ler um disponitivo analógico, é necessário um corversor ou um outro componente que leia analógico e transforme para digital. Nessa prática foi usado um arduino com um código disponibilizado neste repositório que lê o dado do potenciômetro de suas portas analógicas e transmite pelo protocolo I2C para a Raspberry, onde o código de leitura também está disponibilizado como ```Ler_Potenciometro.py```.

O circuito usado pode ser visto abaixo:

![alt text](https://github.com/LucasRorisCube/ComunicacaoArduinoRaspberry/blob/main/Images/print_neofetch.png?raw=true)

Foi necessário um componente abaixo para converter a tensão de 3.3V da Raspiberry para 5V do arduino, chamado Level-Shifter.

## Acionamento remoto

Usando o código ```LED_Remoto.py```, um código simples para transmissão de um número via I2C para o arduino, é possível se comunicar com o Arduino e realizar ações dependendo do número enviado. Neste caso estamos apenas enviando 0 ou 1 para ligar ou desligar o LED. Como usamos o LED pré instalado no arduino, não existe um circuito específico para essa aplicação.

## Observações

Lembrando que o código usado no arduino foi sempre o mesmo (```codigoArduino.ino```), sendo configurado a transmissão e recepção independentemente.
