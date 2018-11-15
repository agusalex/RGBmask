#include <stdio.h>
#include <stdlib.h>

void print_buffer(unsigned char *buffer, int size);
void inicializar_imagen(FILE *file,unsigned char *punteroMemoria,int cant, char* ruta);
void metodoGeneral(unsigned char *imagen1, unsigned char *imagen2, unsigned char *mascara, int cantidad);
void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);

int main(int argc, char* argv[] )
{	
	// Gestionamos los parametros. Faltaría que los parametros entren por consola y no esten Hardcodeados
 	FILE *file1;
	FILE *file2;
	FILE *fileMascara;
	int alto = 150;
	int ancho = 300;
 	int cant = alto * ancho;
 	
 	//Gestionamos Imagen1
    unsigned char *punteroImg1;
    punteroImg1 = (unsigned char*) malloc(cant* 3);
    
    if(punteroImg1!= NULL){
    	printf("Reserve memoria para img1\n");
		inicializar_imagen(file1,punteroImg1,cant, "img1.rgb");
	}
	
	//Gestionamos Imagen2
    unsigned char *punteroImg2;
    punteroImg2 = (unsigned char*) malloc(cant* 3);
    
    if(punteroImg2!= NULL){
    	printf("Reserve memoria para img2\n");
		inicializar_imagen(file2,punteroImg2,cant, "img2.rgb");
	}
	
	//Gestionamos Mascara
    unsigned char *punteroMascara;
    punteroMascara = (unsigned char*) malloc(cant* 3);
    
    if(punteroMascara!= NULL){
    	printf("Reserve memoria para mascara\n");
		inicializar_imagen(fileMascara,punteroMascara,cant, "mascara.rgb");
	}
	
	metodoGeneral(punteroImg1, punteroImg2, punteroMascara,cant);

	//Liberamos los espacion de memoria de malloc
	free(punteroImg1);
	free(punteroImg2);
	free(punteroMascara);
	
	//Si todo se ejecuta correctamente damos por finalizado el programa
	return 0;
}

void inicializar_imagen(FILE *file,unsigned char *punteroMemoria,int cant, char* ruta){
	
	file = fopen(ruta, "r+b"); 
	
	if(!feof(file)){
		printf("Abri el archivo: ");
		printf(ruta);
		printf("\n");
  		fread(punteroMemoria, 1,(cant*3), file); 	//Posicion de memoria donde guardo los datos, tamaño de cada elemento(1byte),
  												 	//cantidad de elementos a contar, archivo de donde saco los datos.									 	
	}
	
    fclose(file);
    
}

void metodoGeneral(unsigned char *imagen1, unsigned char *imagen2, unsigned char *mascara, int cantidad){
	
	//Funcion que inicie un temporizador
	enmascarar_c(imagen1,imagen2,mascara,cantidad);
	//Funcion que pare un temporizador
	//Funcion que inicie un temporizador
	enmascarar_asm(imagen1,imagen2,mascara,cantidad);
	//Funcion que pare un temporizador
	
}

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant){
	int i;
	for(i=0;i<cant/3;i++)
	{
		if(mask[i*3]==255 & mask[i*3+1]==255 & mask[i*3+2]==255)
		{
			//printf(a[i*3]);
			//printf(a[i*3+1]);
			//printf(a[i*3+2]);
			//printf(a[i*3]);
			//printf(a[i*3+1]);
			//printf(a[i*3+2]);
			
			a[i*3]=b[i*3];
			a[i*3+1]=b[i*3+1];
			a[i*3+2]=b[i*3+2];
			
			//printf(a[i*3]);
			//printf(a[i*3+1]);
			//printf(a[i*3+2]);
			
		}
	}
	
	print_buffer(a,cant);
}

void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant){
	
}

void print_buffer(unsigned char *buffer, int size){
	
		printf("\nBuffer of %d elements:\n\n\n", size);
		
		int i = 0;
		for (i; i < size; i++){
			
			printf("%d \t\t\t",buffer[i]);
		
			printf("\n");
				
		}
}
				
		}
}
