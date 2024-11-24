#define RCC_BASE    0x40021000
#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800

#define RCC_APB2ENR (*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOA_CRL   (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_BSRR  (*(volatile unsigned int *)(GPIOA_BASE + 0x10))

#define RCC_APB2ENR_IOPAEN (1 << 2) // Включение тактирования GPIOA

int main(void) {
    // Включить тактирование GPIOA
    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Настроить GPIOA1 и GPIOA2 как выходы (Push-Pull, низкая скорость)
    GPIOA_CRL &= ~((0xF << 4) | (0xF << 8)); // Сброс CNF и MODE для PA1 и PA2
    GPIOA_CRL |= ((1 << 4) | (1 << 8));      // MODE1 = 01, MODE2 = 01 (низкая скорость)
    GPIOA_CRL &= ~((1 << 6) | (1 << 10));    // CNF1 = 00, CNF2 = 00 (Push-Pull)

    // Включить светодиод
    GPIOA_BSRR = (1 << 1);  // Установить PA1 в высокий уровень
    GPIOA_BSRR = (1 << (2 + 16)); // Установить PA2 в низкий уровень

    while (1) {
        // Бесконечный цикл, светодиод остаётся включённым
    }

    return 0;
}

