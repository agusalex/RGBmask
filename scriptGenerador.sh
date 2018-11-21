#!/bin/bash
x=0
ancho=0
alto=0
while [ $x -le 241 ] #hasta 4k
do

   ancho=$(( $x * 16 ))
   alto=$(( $x * 9 ))
   res=$ancho"x"$alto
   echo "Resolucion: "$res;
   #CONVERT
   gm convert -size $res 4kA.jpg img2.rgb;
   gm convert -size $res 4kB.jpg img1.rgb
   gm convert -size $res 4kMask.jpg mascara.rgb
   #COMPILE
   nasm -f elf32 -o _enmascararASM.o _enmascararASM.asm
   gcc -m32  -o main _enmascararASM.o main.c
   ./main img1.rgb img2.rgb mascara.rgb $ancho $alto
   echo $res;

    x=$(( $x + 10 ))
done
   gm convert -size $res -depth 8 salida_c.rgb out.png
   gm convert -size $res -depth 8 salida_asm.rgb outASM.png 


