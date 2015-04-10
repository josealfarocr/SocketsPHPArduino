//LIBRERIAS REQUERIDAS
#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>  


//MAC DEL ARDUINO
byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0x46, 0xA3};

//IP DEL ARDUINO (LAN)
IPAddress ip(192, 168, 2, 175);

//PUERTO A ESCUCHAR
unsigned int puertoLocal = 8888;      


//PAQUETE RECIBIDO
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; 

//RESPUESTA A ENVIAR
char  respuestaBuffer[] = "Recibido";       

// INSTANCIA DE UDP
EthernetUDP Udp;



void setup() {
  
  
// INICIALIZACION DE UDP:
Ethernet.begin(mac,ip);
Udp.begin(puertoLocal);

//INICIALIZACION SERIAL PARA VERIFICACION SOLAMENTE
Serial.begin(9600);
  

}

void loop() {
  
  int tamanoPacket = Udp.parsePacket();
  
  //VERIFICO SI HAY DATOS RECIBIDOS
  if(tamanoPacket)
  {


    // LEO EL PACKETE RECIBIDO
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contenido:");
    Serial.println(packetBuffer);
    
    //LLAMADA A LA FUNCION SEGUN REQUERIMIENTO
    visualizar(packetBuffer);
  
    // ENVIO DE RESPUESTA AL EMISOR
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(respuestaBuffer);
    Udp.endPacket();
    
    
  }
  delay(10);
  
  
}




//FUNCION QUE RECIBE DATOS
void visualizar(String num) {
 

  
}


