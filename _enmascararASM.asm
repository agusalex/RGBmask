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
;mask dq 0xffffffff
mask dq 0xffffffffffffffffffffffffff ;necesita muchas fefes

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
  ;Para Imrprimir
    push dword [cant] ;pusheo para imprimir
    push dword [ptrM]
    push dword [ptr2]
    push dword [ptr1]
    push dword msg1
    call _printf
    add esp, 20
   ;Termina impresion comienza otra impresion
   ;Pruebo el ECX para ver si vale 0
    mov ECX,0
    
 
  
    mov EAX, [ptr2]
    mov EBX, [ptr1]
    mov EDX, [ptrM]
   
sigo:

    CMP [cant], ECX
    JNZ ciclo
    JMP final
    
ciclo:
    ;Muevo porcion de 8 bytes de la segunda imagen.
    movq mm1,[EAX+ECX*8]
    ;Muevo porcion de 8 bytes de la mascara.          
    movq mm2,[EDX+ECX*8]
    ;Hacemos un AND LOGICO EMPAQUETA (PAND) entre mm1 y mm2.
    PAND mm1,mm2
    ;Luego invertimos la mascara. PANDN
    movq mm4, [mask]
    ;movq mm4, [EDX+ECX*8]
    PANDN mm2,mm4
    ;Movemos porcion de 8 bytes de la primer imagen. ;mm3
    movq mm3,[EBX+ECX*8]
    ;Hacemos un and logico empaquetado (PAND) entre mm3 y mm2
    PAND mm3,mm2
    ;Luego Hacemos un POR LOGICO entre mm1 y mm3 
    POR mm1,mm3;(nos queda lo que queremos de ambas imagenes) 
    ;Guardamos el resultado en espacio de memoria de IMAGEN 2.    
    movq [EAX+ECX*8], mm1   
    INC ECX
    JMP sigo


final:
        
    push dword ECX
    push dword msg_debug
    call _printf
    add esp, 8  
    add ESP, 56
    leave ;Esto salva todo, sin esto no termina
    ret