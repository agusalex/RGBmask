nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe romita1.rgb romita2.rgb mask.rgb 4928 3264