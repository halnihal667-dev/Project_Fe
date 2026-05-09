# Contributing to Project_Fe

Thanks for wanting to help! Here's how to contribute cleanly.

## Branch naming
- `feature/your-feature-name` — new features
- `fix/what-you-fixed` — bug fixes
- `docs/what-you-updated` — documentation only

## Rules
1. Never push directly to `main`
2. Always open a Pull Request and describe what you changed and why
3. Test on real hardware before submitting, or clearly mark as untested
4. Keep STM32 and ESP32-CAM code in their separate folders — don't mix

## Setting up locally
```bash
git clone https://github.com/YOUR_USERNAME/Project_Fe.git
```
Open `stm32_master` or `esp32cam_vision` as individual PlatformIO projects.

## Issues
Use the issue templates provided. Bug reports need:
- Which board (STM32 / ESP32-CAM)
- What you expected vs what happened
- Serial monitor output if available
