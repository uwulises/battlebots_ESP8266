#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "motor.h"
#include <ESP8266WiFi.h>
const char *ssid = "Amica";
const char *password = "battlebots";
WiFiServer server(80);

void launch_wifi_access_point()
{
  Serial.begin(9600);
  delay(50);
  WiFi.softAP(ssid, password);
  server.begin(); // Iniciamos el servidor
  delay(50);
  Serial.println("Servidor Iniciado");
  Serial.println("Ingrese desde un navegador web usando la siguiente IP:");
  Serial.println("La red establecida por softAP tendrá una dirección IP predeterminada de 192.168.4.1");
}

void wificlient()
{
  WiFiClient client = server.available();
  if (client) // Si hay un cliente presente
  {
    Serial.println("Nuevo Cliente");

    // esperamos hasta que hayan datos disponibles
    while (!client.available() && client.connected())
    {
      delay(1);
    }

    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);

    if (linea1.indexOf("BW") > 0)
    {
      motor_backward();
      Serial.println("backward");
    }
    if (linea1.indexOf("FW") > 0)
    {

      motor_forward();
      Serial.println("forward");
    }

    client.flush();

    Serial.println("Enviando respuesta...");
    // Encabesado http
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close"); // La conexión se cierra después de finalizar de la respuesta
    client.println();
    // Pagina html  para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>BBots2023</title>");
    client.println("<body>");
    client.println("<h1 align='center'>Test Amica Battlebots 2023</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br />");
    client.println("<button onClick=location.href='./?FW'>FW</button>");
    client.println("<button onClick=location.href='./?BW'>BW</button>");
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");

    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();
  }
}
#endif