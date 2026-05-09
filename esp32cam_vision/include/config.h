// =============================================================
//  ESP32-CAM pin and camera config
// =============================================================

#ifndef CONFIG_H
#define CONFIG_H

// Camera model
#define CAMERA_MODEL_AI_THINKER

// UART to STM32
#define STM32_UART_RX   3   // GPIO3
#define STM32_UART_TX   1   // GPIO1
#define STM32_BAUD      115200

// HSV thresholds for flame detection (tuned in Phase 6)
#define H_MIN   0
#define H_MAX   30
#define S_MIN   150
#define S_MAX   255
#define V_MIN   150
#define V_MAX   255

// Frame size (keep small for speed)
#define FRAME_WIDTH   320
#define FRAME_HEIGHT  240

// Direction codes
#define DIR_NONE    'N'
#define DIR_LEFT    'L'
#define DIR_CENTER  'C'
#define DIR_RIGHT   'R'

#endif
