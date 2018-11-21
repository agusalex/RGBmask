gm convert -size 1280x720 4kA.jpg img2.rgb
gm convert -size 1280x720 4kB.jpg img1.rgb
gm convert -size 1280x720 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 1280 720


gm convert -size 1920x1080 4kA.jpg img2.rgb
gm convert -size 1920x1080 4kB.jpg img1.rgb
gm convert -size 1920x1080 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 1920 1080
gm convert -size 1920x1080 -depth 8 salida_c.rgb out.png
gm convert -size 1920x1080 -depth 8 salida_asm.rgb outASM.png 


gm convert -size 2560x1440 4kA.jpg img2.rgb
gm convert -size 2560x1440 4kB.jpg img1.rgb
gm convert -size 2560x1440 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 2560 1440



gm convert -size 3840x2160 4kA.jpg img2.rgb
gm convert -size 3840x2160 4kB.jpg img1.rgb
gm convert -size 3840x2160 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 3840 2160
gm convert -size 3840x2160 -depth 8 salida_c.rgb out.png
gm convert -size 3840x2160 -depth 8 salida_asm.rgb outASM.png 

gm convert -size 4928x3264 4kA.jpg img2.rgb
gm convert -size 4928x3264 4kB.jpg img1.rgb
gm convert -size 4928x3264 4kMask.jpg mascara.rgb
nasm -f win32 -o _enmascararASM.o _enmascararASM.asm
mingw32-gcc -Wall -o main _enmascararASM.o main.c
main.exe img1.rgb img2.rgb mascara.rgb 4928 3264
