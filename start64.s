global start64

section .text
bits 64
start64:
    extern main
    call main
    mov rax, 0x2f542f532f452f54
    mov qword [0xb8000], rax
    hlt