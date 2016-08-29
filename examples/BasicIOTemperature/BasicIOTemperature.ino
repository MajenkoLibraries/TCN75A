#include <Wire.h>
#include <TCN75A.h>
#include <DisplayCore.h>
#include <SSD1306.h>

TCN75A temp;
SSD1306_IOSHIELD oled;

void setup() {
    Serial.begin(115200);
    temp.begin();
    oled.initializeDevice();
}

void loop() {
    oled.startBuffer();
    oled.fillScreen(Color::Black);
    oled.setCursor(0, 16);
    oled.printf("Temperature: %6.2f C", temp.readTemperature());
    oled.endBuffer();
    delay(1000);
}
