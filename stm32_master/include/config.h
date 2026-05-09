// =============================================================
//  Fire Extinguisher Robot — Pin and config definitions
// =============================================================

#ifndef CONFIG_H
#define CONFIG_H

// UART baud for CAM link
#define CAM_BAUD        115200

// Motor PWM range
#define PWM_MAX         255
#define PWM_MIN         0
#define DEFAULT_SPEED   180   // 0-255

// Servo angles
#define SERVO_CENTER    90
#define SERVO_LEFT_MAX  45
#define SERVO_RIGHT_MAX 135

// IR sensor: LOW = flame detected (active low sensors)
#define FLAME_DETECTED  LOW

// Relay: HIGH = pump ON
#define PUMP_ON         HIGH
#define PUMP_OFF        LOW

// State machine states
#define STATE_IDLE          0
#define STATE_SEARCHING     1
#define STATE_APPROACHING   2
#define STATE_AIMING        3
#define STATE_EXTINGUISHING 4

#endif
