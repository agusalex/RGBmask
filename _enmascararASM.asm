
section .data

cantidad dd 0.0;
msg db "hola =%p",10,0

section .text
extern _printf
global _enmascararASM
_enmascararASM:
    push EBP
    mov  EBP,ESP
    
    ;Obtengo Parametros
    mov EDI,[EBP+8]     ;puntero a Imagen1
    mov EAX,[EBP+12]    ;puntero a Imagen2
    mov EBX,[EBP+16]    ;puntero a Mascara
    mov ECX, [EBP+20]   ;cantidad de bytes
  
    push dword EDI
    push dword msg
    call _printf
    add esp,8
    
   ; mov ecx;0
    ;Determino el limite con el parametro cantidad/8

sigo:
   ; cmp ecx, limite
    jnz ciclo
    jmp final
    
ciclo:
    ;Muevo la primer porcion de 8 bytes de la primer imagen.
    ;mov mmx1,imagen1
    ;Muevo la primer porcion de 8 bytes de la mascara.
    ;mov mmx2, mascara
    INC ecx
    jmp sigo


final:
    ;ACA TENEMOS QUE LIMPIAR LOS REGISTROS SUBIR EL RESULTADO A LA PILA O AL RETURN
    
    add ESP, 56
    ret