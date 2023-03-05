#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

void handleFileRead(String path);
void run_web_server(void);
void handleMotor1Request(void);
void handleMotor2Request(void);
void handle_client(void);

#endif
