set count=0
:loop
set /a count=%count%+2
set /a ancho=count*9
set /a alto=count*16
echo ancho
echo alto
if not #%count%#==#1# goto loop
gm convert -size 3840x2160 4kA.jpg img2.rgb
gm convert -size 3840x2160 4kB.jpg img1.rgb
gm convert -size 3840x2160 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 3840 2160
gm convert -size 3840x2160 -depth 8 salida_c.rgb out.png
gm convert -size 3840x2160 -depth 8 salida_asm.rgb outASM.png 
