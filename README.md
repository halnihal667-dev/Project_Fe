# Fire Extinguisher Robot 🔥🤖

An autonomous fire-fighting robot built with STM32 Blue Pill and ESP32-CAM.
Detects fire using IR flame sensors and camera-based vision, navigates toward it, aims a pump servo, and extinguishes it.

## Hardware
| Component | Role |
|---|---|
| STM32 Blue Pill (F103C8) | Master controller — motors, servo, relay, IR sensors |
| ESP32-CAM (AI Thinker) | Vision module — flame detection via camera |
| L298N motor driver | Drives 2× DC motors |
| 5× IR flame sensors | Close-range flame triangulation |
| Servo motor | Aims the pump nozzle |
| Relay module | Switches pump on/off |
| Water pump | Extinguishes fire |

## Project Structure
```
Project_Fe/
├── stm32_master/        # STM32 Blue Pill firmware
│   ├── src/main.cpp
│   ├── include/config.h
│   └── platformio.ini
├── esp32cam_vision/     # ESP32-CAM firmware
│   ├── src/main.cpp
│   ├── include/config.h
│   └── platformio.ini
└── docs/                # Wiring diagrams and references
```

## Getting Started

### Prerequisites
- VS Code with PlatformIO extension
- ST-Link V2 (for STM32 upload)
- Python 3.x

### Clone and open
```bash
git clone https://github.com/YOUR_USERNAME/Project_Fe.git
cd Project_Fe
```
Open each subfolder (`stm32_master` or `esp32cam_vision`) as a separate PlatformIO project in VS Code.

### Build and upload
- STM32: connect ST-Link V2, click PlatformIO Upload
- ESP32-CAM: connect via USB-UART adapter, click PlatformIO Upload

## UART Protocol (STM32 ↔ ESP32-CAM)
ESP32-CAM sends a CSV line every 100ms:
```
<direction>,<x_percent>,<confidence>\n
```
Example: `C,52,87` = flame in center, at 52% x position, 87% confidence

## Contributing
See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.
Open an issue before starting work on a new feature.

## License
MIT
