    .section .text
    .global _start

_start:
    LDR R0, =_stack_top      // Инициализация указателя стека
    MOV SP, R0

    BL main                  // Переход на main
    B .                      // Бесконечный цикл на случай выхода из main

_stack_top:
    .word 0x20020000         // Указатель на вершину памяти SRAM (зависит от микроконтроллера)

