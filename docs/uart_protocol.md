# Byte-level protocol between ESP32-CAM and STM32

## Direction
ESP32-CAM sends one line every 100ms over UART at 115200 baud:

  <DIR>,<X>,<CONF>\n

| Field | Type | Values | Meaning |
|---|---|---|---|
| DIR  | char  | N / L / C / R | None, Left, Center, Right |
| X    | int   | 0–100 | Flame x-position as % of frame width |
| CONF | int   | 0–100 | Detection confidence % |

### Examples
- `N,0,0\n`   — no flame seen
- `C,50,92\n` — flame at center, 92% confidence
- `L,18,75\n` — flame on left side, 75% confidence
- `R,83,88\n` — flame on right side

## STM32 response (optional debug)
STM32 can echo current state back to CAM:
  STATE:<n>\n
Where n = 0 IDLE, 1 SEARCHING, 2 APPROACHING, 3 AIMING, 4 EXTINGUISHING
