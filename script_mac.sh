rm -Rf _enmascararASM.o
rm -Rf main
nasm -f macho32 -o _enmascararASM.o _enmascararASM.asm
gcc -m32  -o main _enmascararASM.o main.c
./main img1.rgb img2.rgb mascara.rgb 150 300
