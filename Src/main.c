#include <stdint.h>

/* Peripheral base addresses */
#define RCC_BASE        0x40023800
#define GPIOA_BASE      0x40020000

/* Registers */
#define RCC_AHB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

/* Simple delay */
void delay(volatile uint32_t count) {
    while(count--) {
        __asm__("nop");
    }
}

int main(void) {
    /* Enable GPIOA clock */
    RCC_AHB1ENR |= (1 << 0);

    /* Set PA6 and PA7 as output (01) */
    GPIOA_MODER &= ~((3 << (6*2)) | (3 << (7*2))); // clear
    GPIOA_MODER |=  ((1 << (6*2)) | (1 << (7*2))); // set output

    while (1) {
        GPIOA_ODR |=  (1 << 6);   // PA6 ON
        GPIOA_ODR &= ~(1 << 7);   // PA7 OFF
        delay(1000000);

        GPIOA_ODR &= ~(1 << 6);   // PA6 OFF
        GPIOA_ODR |=  (1 << 7);   // PA7 ON
        delay(1000000);
    }
}