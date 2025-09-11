.global _main
.align 4

.data
message:
    .ascii "Hello, World!\n"
message_len = . - message

.text
_main:
    // Chama o syscall 'write' (4)
    mov x16, #4
    mov x0, #1                  // File descriptor 1 (stdout)
    adrp x1, message@page       // Ponteiro para a mensagem (página)
    add x1, x1, message@pageoff // Offset dentro da página
    mov x2, #14                 // Tamanho da mensagem
    svc #0

    // Chama o syscall 'exit' (1)
    mov x16, #1
    mov x0, #0                  // Código de saída 0
    svc #0