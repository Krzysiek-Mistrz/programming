#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Krzysiek_Mistrz";
const char* password = "00000000";

AsyncWebServer server(80);
int pomoc = 1;

void setup() {
  Serial.begin(115200);
  delay(5000);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /");
    
    request->send(200, "text/html",
                  "<html><body>"
                  "<h1>Hello, ESP32!</h1>"
                  "<a href=\"/link\">Kliknij tutaj</a>"  // link do obsługi kliknięcia
                  "</body></html>");
  });

  server.on("/link", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("Link został kliknięty!");  // komunikat wysyłany przez UART
    request->send(200, "text/html", 
                    "<html><body>"
                    "<h1>Link klikniety!</h1>"
                    "<a href=\"./..\">Powroc do strony glownej</a>"
                    "</body></html>");
  });

  server.begin();
}

void loop() {}