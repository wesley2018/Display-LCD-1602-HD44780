//INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS PARA A EXECUÇÃO DO CÓDIGO
#include <SPI.h>
#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>
#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //PORTAS DO ARDUINO QUE SÃO UTILIZADAS PELO DISPLAY LCD

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // NÃO PRECISA MEXER
byte ip[] = { 192, 168, 0, 177 }; // COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110  **** ISSO VARIA, NO MEU CASO É: 192.168.0.177
byte gateway[] = { 192, 168, 0, 1 }; // MUDE PARA O GATEWAY PADRÃO DO SEU ROTEADOR **** NO MEU CASO É O 192.168.0.1
byte subnet[] = { 255, 255, 255, 0 }; //COLOQUE O ENDEREÇO DA MASCARA DE REDE DO SEU ROTEADOR
EthernetServer server(80); //CASO OCORRA PROBLEMAS COM A PORTA 80, UTILIZE OUTRA (EX:8082,8089)
byte sampledata=50;

String readString = String(30); //CRIA UMA STRING CHAMADA "readString"

void setup(){
 lcd.begin(16, 2); //SETA A QUANTIDADE DE CARACTERES(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
 pinMode(6,OUTPUT);
 analogWrite(6,5); 
 lcd.setCursor(0,0);  //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1)
 lcd.print("MASTERWALKERSHOP"); //ESCREVE A PALAVRA "MASTERWALKERSHOP" NO DISPLAY LCD
 lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
 lcd.print("COR: ");//ESCREVE A PALAVRA "COR" NO DISPLAY LCD

 Ethernet.begin(mac, ip, gateway, subnet); // INICIALIZA A CONEXÃO ETHERNET

}
void loop(){

EthernetClient client = server.available(); // CRIA UMA VARIÁVEL CHAMADA client
  if (client) { //SE EXISTE CLIENTE
    while (client.connected()) { // ENQUANTO  EXISTIR CLIENTE CONECTADO
   if (client.available()) { // SE EXISTIR CLIENTE HABILITADO
    char c = client.read(); // CRIA A VARIÁVEL c

    if (readString.length() < 100) // SE O ARRAY FOR MENOR QUE 100
      {
        readString += c; // "readstring" VAI RECEBER OS CARACTERES LIDO
      }
        if (c == '\n') { // SE ENCONTRAR "\n" É O FINAL DO CABEÇALHO DA REQUISIÇÃO HTTP
          if (readString.indexOf("?") <0) //SE ENCONTRAR O CARACTER "?"
          {
          }
          else // SENÃO
        if(readString.indexOf("L=amarelo") >0){ // SE ENCONTRAR O PARÂMETRO "L=amarelo"
         lcd.setCursor(6,1); // MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("AMARELO "); // ESCREVE A PALAVRA "AMARELO"
        }
        if(readString.indexOf("L=azul") >0){//SE ENCONTRAR O PARÂMETRO "L=azul"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("AZUL     "); //ESCREVE A PALAVRA "AZUL"
        }
        if(readString.indexOf("L=branco") >0){//SE ENCONTRAR O PARÂMETRO "L=branco"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("BRANCO   "); //ESCREVE A PALAVRA "BRANCO"
        }
        if(readString.indexOf("L=laranja") >0){//SE ENCONTRAR O PARÂMETRO "L=laranja"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("LARANJA "); //ESCREVE A PALAVRA "LARANJA"
        }
        if(readString.indexOf("L=preto") >0){//SE ENCONTRAR O PARÂMETRO "L=preto"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("PRETO    "); //ESCREVE A PALAVRA "PRETO"
        }
        if(readString.indexOf("L=rosa") >0){//SE ENCONTRAR O PARÂMETRO "L=rosa"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("ROSA    "); //ESCREVE A PALAVRA "ROSA"
        }
        if(readString.indexOf("L=roxo") >0){//SE ENCONTRAR O PARÂMETRO "L=roxo"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("ROXO    "); //ESCREVE A PALAVRA "ROXO"
        }
        if(readString.indexOf("L=verde") >0){//SE ENCONTRAR O PARÂMETRO "L=verde"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("VERDE    "); //ESCREVE A PALAVRA "VERDE"
        }
        if(readString.indexOf("L=vermelho") >0){//SE ENCONTRAR O PARÂMETRO "L=vermelho"
          lcd.setCursor(6,1); //MOVE O CURSOR DO LCD(COLUNA 6 E LINHA 2)
         lcd.print ("VERMELHO  "); //ESCREVE A PALAVRA "VERMELHO"
        }
          client.println("HTTP/1.1 200 OK"); // ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
          client.println("Content-Type: text/html"); // ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
          client.println();
          readString="";
          client.stop(); // FINALIZA A REQUISIÇÃO HTTP
            }
          }
        }
      }
 }
