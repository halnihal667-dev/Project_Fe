// =============================================================
//  Fire Extinguisher Robot — STM32 Blue Pill Master Controller
//  Handles: Motors, Servo, Relay/Pump, IR Sensors, UART to CAM
//  Phase 7 will replace this with the full state machine
// =============================================================

#include <Arduino.h>

// --- Pin Definitions ---
// Motor Driver (L298N)
#define MOTOR_L_IN1  PB0
#define MOTOR_L_IN2  PB1
#define MOTOR_R_IN3  PB10
#define MOTOR_R_IN4  PB11
#define MOTOR_L_ENA  PA8   // PWM Timer1 CH1
#define MOTOR_R_ENB  PA11  // PWM Timer1 CH4

// Servo (pump aiming)
#define SERVO_PIN    PA0   // PWM Timer2 CH1

// Relay (pump on/off)
#define RELAY_PIN    PC13

// IR Flame Sensors
#define IR_FRONT     PA1
#define IR_FRONT_L   PA2
#define IR_FRONT_R   PA3
#define IR_REAR_L    PA4
#define IR_REAR_R    PA5

// UART2 used for ESP32-CAM comms (PA2=TX2, PA3=RX2 on Blue Pill)
// We use Serial1 here (USART1 = PA9/PA10) for CAM link
// Serial  = USART1 debug via ST-Link virtual COM

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200); // UART to ESP32-CAM

    // Motor pins
    pinMode(MOTOR_L_IN1, OUTPUT);
    pinMode(MOTOR_L_IN2, OUTPUT);
    pinMode(MOTOR_R_IN3, OUTPUT);
    pinMode(MOTOR_R_IN4, OUTPUT);
    pinMode(MOTOR_L_ENA, OUTPUT);
    pinMode(MOTOR_R_ENB, OUTPUT);

    // Relay
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); // pump OFF at boot

    // IR sensors
    pinMode(IR_FRONT,   INPUT);
    pinMode(IR_FRONT_L, INPUT);
    pinMode(IR_FRONT_R, INPUT);
    pinMode(IR_REAR_L,  INPUT);
    pinMode(IR_REAR_R,  INPUT);

    Serial.println("STM32 Master — boot OK");
}

void loop() {
    // Full state machine added in Phase 7
    // For now: echo CAM data to debug serial
    if (Serial1.available()) {
        String msg = Serial1.readStringUntil('\n');
        Serial.print("CAM says: ");
        Serial.println(msg);
    }
}
