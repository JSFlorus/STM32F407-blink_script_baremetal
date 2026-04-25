# STM32 Blink (Bare Metal)

Simple LED blink using direct register access (no HAL).

## Features
- RCC setup
- GPIO configuration
- Bitwise control

## Hardware
- STM32F407
- LEDs on PA6 / PA7

## Flashing Method

This project was flashed over **UART1** using the STM32 built-in ROM bootloader.

### Bootloader configuration

To enter bootloader mode:

```text
BOOT0 = 1 / HIGH
BOOT1 = 0 / LOW
Press RESET
