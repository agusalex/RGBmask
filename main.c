#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_buffer(unsigned char *buffer, int size);
void inicializar_imagen(FILE *file,unsigned char *punteroMemoria,int cant, char* ruta);
void metodoGeneral(unsigned char *imagen1, unsigned char *imagen2, unsigned char *mascara, int cantidad);
void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);

int main(int argc, char* argv[] )
{	
   if( argc == 6 ) {
	int i;
	printf("Ejecutando con parametros: ");
	for (i=1 ; i<argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n\n");
   }	
   else if( argc > 6 ) {
      printf("Demasiados Parametros...\n");
	return 0;
   }
   else {
      printf("Faltan Parametros...\n");
	return 0;
   }
   
	//Gestion de Parametros.
	FILE *file1;
	FILE *file2;
	FILE *fileMascara;
	char *imagen1 = argv[1];
	char *imagen2 = argv[2];
	char *mascara = argv[3];
	int ancho =  atoi (argv[4]); //convierte de string a numero
	int alto = atoi (argv[5]);
	int cant = alto * ancho;
	
 	//Gestionamos Imagen1
    unsigned char *punteroImg1;
    punteroImg1 = (unsigned char*) malloc(cant* 3);
    
    if(punteroImg1!= NULL){
    	printf("Reserve memoria para %s\n",imagen1);
		inicializar_imagen(file1,punteroImg1,cant, imagen1);
	}
	
	//Gestionamos Imagen2
    unsigned char *punteroImg2;
    punteroImg2 = (unsigned char*) malloc(cant* 3);
    
    if(punteroImg2!= NULL){
    	printf("Reserve memoria para %s\n",imagen2);
		inicializar_imagen(file2,punteroImg2,cant, imagen2);
	}
	
	//Gestionamos Mascara
    unsigned char *punteroMascara;
    punteroMascara = (unsigned char*) malloc(cant* 3);
    
    if(punteroMascara!= NULL){
	printf("Reserve memoria para %s\n",mascara);
		inicializar_imagen(fileMascara,punteroMascara,cant,mascara);
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
		printf("%s",ruta);
		printf("\n");
  		fread(punteroMemoria, 1,(cant*3), file); 	//Posicion de memoria donde guardo los datos, tamaño de cada elemento(1byte),
  												 	//cantidad de elementos a contar, archivo de donde saco los datos.									 	
	}
	
    fclose(file);
}

void metodoGeneral(unsigned char *imagen1, unsigned char *imagen2, unsigned char *mascara, int cantidad){
	
	float tiempo1;
	float tiempo2;
	time_t tAntes;
	time_t tDespues;
	
	//Funcion que inicie un temporizador
	tAntes = time(NULL);
	enmascarar_c(imagen1,imagen2,mascara,cantidad);
	//Funcion que pare un temporizador
	tDespues = time(NULL);
	tiempo1 = difftime(tDespues, tAntes);
	
	//Funcion que inicie un temporizador
	tAntes = time(NULL);
	enmascarar_asm(imagen1,imagen2,mascara,cantidad);
	//Funcion que pare un temporizador
	tDespues = time(NULL);
	tiempo2 = difftime(tDespues, tAntes);
	
	printf("\n%f", tiempo1);
	printf("\n%f", tiempo2);
	
}

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant){
	int i;
	for(i=0;i<cant/3;i++)
	{
		if(mask[i*3]==255 & mask[i*3+1]==255 & mask[i*3+2]==255)
		{
			a[i*3]=b[i*3];
			a[i*3+1]=b[i*3+1];
			a[i*3+2]=b[i*3+2];
		}
	}
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
