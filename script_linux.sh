
#!/bin/bash
x=1
ancho=0
alto=0;
while [ $x -le 241 ]
do
   ancho=$(( $x * 16 ))
   alto=$(( $x * 9 ))
   #CONVERT
   gm convert -size $ancho"x"$alto 4kA.jpg img2.rgb;
   gm convert -size $ancho"x"$alto 4kB.jpg img1.rgb
   gm convert -size $ancho"x"$alto 4kMask.jpg mascara.rgb
   #COMPILE
   nasm -f elf32 -o _enmascararASM.o _enmascararASM.asm
   gcc -m32  -o main _enmascararASM.o main.c
   ./main img1.rgb img2.rgb mascara.rgb $ancho $alto
   echo $ancho"x"$alto;

  x=$(( $x + 10 ))
done
gm convert -size $ancho"x"$alto -depth 8 salida_c.rgb out.png
gm convert -size $ancho"x"$alto -depth 8 salida_asm.rgb outASM.png 

