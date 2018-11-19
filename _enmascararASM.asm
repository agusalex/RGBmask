section .data
;msg db "hola %p",10,0
ptr1 dd 0
ptr2 dd 0
ptrM dd 0
cant dd 0
limite dd 0

section .text
;extern _printf
global _enmascararASM
_enmascararASM:
    push EBP
    mov  EBP,ESP
    
    ;Obtengo Parametros
    mov EAX,[EBP+8]
    mov [ptr1],EAX     ;puntero a Imagen1
    mov EAX,[EBP+12]
    mov [ptr2],EAX    ;puntero a Imagen2
    mov EAX, [EBP+16]
    mov [ptrM],EAX    ;puntero a Mascara
    mov EAX, [EBP+20]
    mov [cant],EAX    ;cantidad de bytes
  
    ;push dword EDI
    ;push dword msg
    ;call _printf
    ;add esp,8
    
    mov ECX, 0
    mov limite, 4 ;HARDCODEADO !! Determino el limite con el parametro cantidad/8

sigo:
   cmp ECX, limite
   jnz ciclo
   jmp final
    
ciclo:
    ;Muevo la primer porcion de 8 bytes de la primer imagen.
    movq mm1,[ptr1+ECX*8]
    ;Muevo la primer porcion de 8 bytes de la mascara.
    movq mm2,[ptrM+ECX*8]
    ;INC ecx
    ;jmp sigo


final:
    ;ACA TENEMOS QUE LIMPIAR LOS REGISTROS SUBIR EL RESULTADO A LA PILA O AL RETURN
    
    add ESP, 56
    ret