nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 150 300
gm convert -size 300x150 -depth 8 salida_c.rgb out.png
gm convert -size 300x150 -depth 8 salida_asm.rgb outASM.png 