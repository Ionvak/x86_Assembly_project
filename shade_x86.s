
                    %define LOCAL_DATA_SIZE 0

                    section .data


                    section .text
                    global shadeexceptring


shadeexceptring: 
                    ; Prologue
                    push ebp
                    mov  ebp, esp
                    sub  esp, (LOCAL_DATA_SIZE + 3) & ~3

                    ; Saving saved registers.
                    push ebx
                    push esi
                    push edi

                    ;Function body.
                    mov ebx,  [ebp + 8]
                    mov esi,  [ebx + 18]                 ;storing the width (in pixels) in cx.
                    mov edi,  [ebx + 22]                 ;storing the height (in pixels) in cx.
                    add ebx,  54                         ;storing the address of the pixel array.

                    mov ax, [esi]
                    mov dx, [edi]
                    mul dx

                    shl edx, 16
                    xor edx, eax                         ;storing the stride in edx (not rounded).
                    add edx, 3
                    and edx, ~3


                    ; Restoring saved registers.
                    pop edi
                    pop esi
                    pop ebx

                    ; Epilogue.

                    mov  esp, ebp
                    pop  ebp
                    ret