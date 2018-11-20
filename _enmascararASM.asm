global _enmascararASM

section .data
msg1 db "IMG1 %p ,IMG2 %p ,ptrM %p, cant %d ",10,0
msg2 db "Limite= %d",10,0
msg_fin db "Terminamos con contador en= %d",10,0
msg_debug db "CICLO",10,0
msg_sigo db "LLegue con= %d",10,0
ptr1 dd 0
ptr2 dd 0
ptrM dd 0
cant dd 0

section .text
extern _printf

_enmascararASM:
    push EBP
    mov  EBP,ESP
    
    ;Obtengo Parametros
    xor EBX,EBX
    mov EBX,[EBP+8]
    mov [ptr1],EBX     ;puntero a Imagen1
    xor EBX,EBX
    mov EBX,[EBP+12]
    mov [ptr2],EBX    ;puntero a Imagen2
    xor EAX,EAX
    mov EAX,[EBP+16]
    mov [ptrM],EAX    ;puntero a Mascara
    xor EAX,EAX
    mov EAX,[EBP+20]
    mov [cant],EAX    ;cantidad de bytes
  
    push dword [cant]
    push dword [ptrM]
    push dword [ptr2]
    push dword [ptr1]
    push dword msg1
    call _printf
    add esp, 20
    
    mov ECX,0
    
    push dword ECX
    push dword msg_sigo
    call _printf
    add esp, 8
   
sigo:
    CMP [cant], ECX
    JNZ ciclo
    JMP final
    
ciclo:
    ;Muevo la primer porcion de 8 bytes de la primer imagen.
    movq mm1,[ptr1+ECX*8]
    ;Muevo la primer porcion de 8 bytes de la mascara.
    ;movq mm2,[ptrM+ECX*8]

    
    INC ECX
    JMP sigo


final:
    ;ACA TENEMOS QUE LIMPIAR LOS REGISTROS SUBIR EL RESULTADO A LA PILA O AL RETURN
    
    push dword ECX
    push dword msg_sigo
    call _printf
    add esp, 8
    
    add ESP, 56
    ret