Introdução 

O surgimento da ideia para criar este projeto tem como base a necessidade de diversos profissionais da música que buscam uma forma melhor de manipular os softwares de produção musical, diminuindo o uso de teclado ou clique do mouse para poder aumentar um simples volume ou em até outras situações pausar e pressionar o play. 

Para solucionar esse problema, foram lançados no mercado diversos controladores que utilizam a interface MIDI para enviar comandos de botões, potenciômetros e diversos outros controles reais, simulando o sistema analógico dos equipamentos de audio para poder controlar os programas de música para computadores, que é um sucesso entre produtores musicais e Djs. 

O objetivo deste projeto é desenvolver um protótipo de um controlador MIDI USB utilizando arduino que proporciona funcionalidades iguais ou superiores aos encontrados no mercado, porém com um custo bem inferior e também um produto com identidade própria. 

Metodologia 

Para o desenvolvimento foi necessário entender como funciona a comunicação do arduino com o computador que utiliza o protocolo Serial, também como funciona o protocolo de comunicação de um controlador convencional que no caso utiliza o protocolo MIDI e como é a forma de comunicação dos componentes eletronicos utilizados que neste projeto foram potenciometros que são analógicos. 

A montagem funcionou da seguinte forma, os potenciometros utilizados foram conectados as portas analógicas do arduino que em seguida no código desenvolvido que foi gravado no arduino recebe o valor do potenciometro na qual a porta anaógica interpreta com valores de 0 a 1023, logo após é realizado o processamento do valor lido e convertido para um valor compativel com o protocolo midi que tem uma variação de 0 a 127. 

Para realizar a conversão foi feito um simples cálculo, o valor da porta analógica foi dividido por 8 assim obtendo uma variação de resultados próximo ao utilizado pelo midi, convertendo 0 a 1023 em 0 a 127, transformando na escala ideal para conseguir uma comunicação MIDI. 

A comunicação até agora descrita está apenas no arduino e ainda não foi passada ao computador, então para realizar a comunicação foi utilizado o protocolo de comunicação serial que é ligado pela porta usb ao computador, sendo identificado como um dispositivo serial, já dentro do computador foi utilizado um software que converte o protocolo serial em midi que é o software hairless-midiserial que se comunica com uma porta virtual midi no computador que nesse projeto foi utilizado o IAC3 do Mac OS X. Então as informações midi corretas chegam ao software de música que deseja ser controlado, realizando a configuração e apontamento de porta de entrada para o IAC3 que se comunica com o hairless-midiserial e que comunica com a porta serial usb do arduino. 

Os componentes para o desenvolvimento do controlador midi necessários foram: 

Arduino Uno R3 

6 potenciômetros deslisantes 10k 

2 potenciômetros 10k rotativo 

1 display LCD 16x2 

Jumpers Diversos 

Resumo do Projeto Enviado para Publicação no Centro Universitário de Volta Redonda (UNI Foa)

Publicação do Resumo pode ser consultada no link abaixo na página 29
http://editora.unifoa.edu.br/wp-content/uploads/2018/10/XII-Coloquio-Resumos-Exatas.pdf
