gm convert -size 4928x3264 Roma1.jpg roma1.rgb
gm convert -size 4928x3264 Roma2.jpg roma2.rgb
gm convert -size 4928x3264 mascRoma.jpg mascRoma.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe roma1.rgb roma2.rgb mascRoma.rgb 4928 3264
gm convert -size 4928x3264 -depth 8 salida_c.rgb out.png
gm convert -size 4928x3264 -depth 8 salida_asm.rgb outASM.png 
