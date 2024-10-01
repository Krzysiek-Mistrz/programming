
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "ESP32_Hotspot";
const char* password = "12345678";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10000);

  WiFi.softAP(ssid, password);

  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("Otworzono strone glowna.");
    request->send(200, "text/html", 
                  "<html><body>"
                  "<h1>Witaj na ESP32!</h1>"
                  "<a href=\"/klik\">Kliknij tutaj</a>"
                  "</body></html>");
  });

  server.on("/klik", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("Link został kliknięty!");
    request->send(200, "text/html", "<html><body><h1>Link kliknięty!</h1></body></html>");
  });

  server.begin();
}

void loop() {}
