# Wiring Reference — Fire Extinguisher Robot

## UART Link — STM32 Blue Pill ↔ ESP32-CAM
| STM32 Pin | ESP32-CAM Pin | Note |
|---|---|---|
| PA9  (TX1) | GPIO3 (RX) | Through logic level converter (3.3V↔3.3V, direct OK) |
| PA10 (RX1) | GPIO1 (TX) | Through logic level converter |
| GND | GND | Common ground MUST be connected |

Baud: 115200

## Motor Driver — L298N ← STM32
| L298N Pin | STM32 Pin | Note |
|---|---|---|
| IN1 | PB0  | Left motor direction A |
| IN2 | PB1  | Left motor direction B |
| IN3 | PB10 | Right motor direction A |
| IN4 | PB11 | Right motor direction B |
| ENA | PA8  | Left motor PWM (Timer1 CH1) |
| ENB | PA11 | Right motor PWM (Timer1 CH4) |
| 12V | Battery+ | Motor supply (separate from MCU) |
| GND | Common GND | |
| 5V out | Do NOT use for STM32 | Use separate regulator |

## Servo — Pump aiming
| Servo Wire | Connect to |
|---|---|
| Signal (orange) | PA0 — Timer2 CH1 PWM |
| VCC (red) | 5V from BEC / regulator |
| GND (brown) | Common GND |

## Relay Module — Pump control
| Relay Pin | Connect to |
|---|---|
| IN | PC13 (STM32) |
| VCC | 5V |
| GND | Common GND |
| COM | Pump power wire |
| NO  | Battery+ for pump |

Add flyback diode (1N4007) across pump terminals.

## IR Flame Sensors (×5)
| Sensor | STM32 Pin | Position |
|---|---|---|
| Sensor 1 | PA1 | Front center |
| Sensor 2 | PA2 | Front left |
| Sensor 3 | PA3 | Front right |
| Sensor 4 | PA4 | Rear left |
| Sensor 5 | PA5 | Rear right |

All sensors: VCC→3.3V, GND→GND, DO→pin above.
Active LOW — output goes LOW when flame detected.

## Power Architecture
```
2S LiPo (7.4V)
    │
    ├── L298N 12V in (motors)
    │       └── L298N 5V out → NOT USED (noisy)
    │
    ├── Buck converter 1 → 5V 2A → Servo + Relay + ESP32-CAM
    │
    └── Buck converter 2 → 3.3V 1A → STM32 Blue Pill 3.3V pin
```
NEVER power STM32 from L298N's onboard 5V — motor noise will reset it.
