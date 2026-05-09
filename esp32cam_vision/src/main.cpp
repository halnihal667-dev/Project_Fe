// =============================================================
//  Fire Extinguisher Robot — ESP32-CAM Flame Vision Module
//  Detects flame using HSV color thresholding on camera feed
//  Sends direction byte over UART to STM32 master
//  Phase 6 will replace this with full detection logic
// =============================================================

#include <Arduino.h>

// UART1 (GPIO1=TX, GPIO3=RX) used for STM32 link
// That is the same as Serial on ESP32-CAM

// Direction codes sent to STM32
#define DIR_NONE    'N'
#define DIR_LEFT    'L'
#define DIR_CENTER  'C'
#define DIR_RIGHT   'R'

void setup() {
    // Serial = UART0 (USB debug)
    // Serial2 = UART1 (GPIO1/3) — STM32 link
    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, 3, 1); // RX=GPIO3, TX=GPIO1

    Serial.println("ESP32-CAM Vision — boot OK");
    Serial.println("Camera init will be added in Phase 6");
}

void loop() {
    // Placeholder: send heartbeat every 2 seconds
    Serial2.println("N,0,0");  // direction=None, x=0, y=0
    Serial.println("Heartbeat sent to STM32");
    delay(2000);
}
