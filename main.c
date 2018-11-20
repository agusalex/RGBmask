#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_buffer(unsigned char *buffer, int size);
int multiploOcho(int ancho, int alto);
void inicializar_imagen(FILE *file,unsigned char *punteroMemoria,int cant, char* ruta);
void metodoGeneral(unsigned char *imagen1, unsigned char *imagen2, unsigned char *mascara, int cantidad);
void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
extern void enmascararASM(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void escribirResultado(unsigned char *punteroMemoria, int cant, char* ruta);

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
	FILE *file1=NULL;
	FILE *file2=NULL;
	FILE *fileMascara=NULL;
	char *imagen1 = argv[1];
	char *imagen2 = argv[2];
	char *mascara = argv[3];
	int ancho =  atoi (argv[4]); //convierte de string a numero
	int alto = atoi (argv[5]);
	int cant = multiploOcho(ancho,alto);
	

	
 	//Gestionamos Imagen1
    unsigned char *punteroImg1;
    punteroImg1 = (unsigned char*) malloc(cant);
    
    if(punteroImg1!= NULL){
    	printf("Reserve memoria para %s\n",imagen1);
		inicializar_imagen(file1,punteroImg1,cant, imagen1);
	}
	
	//Gestionamos Imagen2
    unsigned char *punteroImg2;
    punteroImg2 = (unsigned char*) malloc(cant);
    
    if(punteroImg2!= NULL){
    	printf("Reserve memoria para %s\n",imagen2);
		inicializar_imagen(file2,punteroImg2,cant, imagen2);
	}
	
	//Gestionamos Mascara
    unsigned char *punteroMascara;
    punteroMascara = (unsigned char*) malloc(cant);
    
    if(punteroMascara!= NULL){
	printf("Reserve memoria para %s\n",mascara);
		inicializar_imagen(fileMascara,punteroMascara,cant,mascara);
	}
	printf("PARAMETRO %p\n",punteroImg1);
	printf("PARAMETRO %p\n",punteroImg2);
	printf("PARAMETRO %p\n",punteroMascara);
	printf("PARAMETRO %d\n",cant);
	metodoGeneral(punteroImg1, punteroImg2, punteroMascara,cant);

	//Liberamos los espacion de memoria de malloc
	free(punteroImg1);
	free(punteroImg2);
	free(punteroMascara);
	
	//Si todo se ejecuta correctamente damos por finalizado el programa
	return 0;
}

void inicializar_imagen(FILE *file,unsigned char *punteroMemoria,int cant, char* ruta){
	
	file = fopen(ruta, "rb"); 
	
	if(!feof(file)){
		printf("Abri el archivo: ");
		printf("%s",ruta);
		printf("\n");
  		fread(punteroMemoria, 1,cant, file); 	//Posicion de memoria donde guardo los datos, tamaño de cada elemento(1byte),
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
	
	//Crear un archivo con el resultado en C..
	escribirResultado(imagen1,cantidad,"salida_c.rgb");
	
	//Funcion que inicie un temporizador
	tAntes = time(NULL);
	enmascararASM(imagen1,imagen2,mascara,cantidad/8);
	//Funcion que pare un temporizador
	tDespues = time(NULL);
	tiempo2 = difftime(tDespues, tAntes);

	//Crear un archivo con el resultado en ASM..
	escribirResultado(imagen2,cantidad,"salida_asm.rgb");
	
	printf("\n%f", tiempo1);
	printf("\n%f", tiempo2);
	
}
int multiploOcho(int ancho, int alto){
	
	int bytes = (ancho*alto)*3;	
	int resto = bytes%8;
	if(resto==0){
		return bytes;
	}
	else{
		int diferencia = 8-resto;
		return bytes + diferencia;
	}
}

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant){
	int i;
	for(i=0;i<cant/3;i++)
	{
		if((mask[i*3]==255)& (mask[i*3+1]==255)& (mask[i*3+2]==255))
		{
			a[i*3]=b[i*3];
			a[i*3+1]=b[i*3+1];
			a[i*3+2]=b[i*3+2];
		}
	}
}

void escribirResultado(unsigned char *punteroMemoria, int cant, char* ruta)
{
	FILE *file;

    file = fopen( ruta , "wb" );
    fwrite(punteroMemoria , 1 , cant , file );
    
    fclose(file);
}

void print_buffer(unsigned char *buffer, int size){
	
		printf("\nBuffer of %d elements:\n\n\n", size);
		
		int i;
		for (i=0; i < size; i++){
			printf(" %d",i);
			printf("%d \t\t\t",buffer[i]);
			printf("\n");

		}	
		
}
