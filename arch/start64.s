global start64

extern GDT64.Data
extern stack_top

section .text
bits 64
start64:
    mov     ax, GDT64.Data
    mov     ds, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax
    mov     ss, ax

    mov rsp, stack_top

    extern kinit
    call kinit
    extern kmain
    call kmain
    
    int 15
    hlt