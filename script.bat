nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
lldb _enmascararASM
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 150 300