    section .data
        msg db "Hello, World!", 0x0a # Mensagem e nova linha
        len = $ - msg

    section .text
        global _start

    _start:
        ; Chama o syscall 'write' (0x2000004)
        mov rax, 0x2000004
        mov rdi, 1 ; File descriptor 1 (stdout)
        lea rsi, [msg] ; Ponteiro para a mensagem
        mov rdx, len ; Tamanho da mensagem
        syscall

        ; Chama o syscall 'exit' (0x2000001)
        mov rax, 0x2000001
        xor rdi, rdi ; Código de saída 0
        syscall