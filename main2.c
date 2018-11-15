#include <stdio.h>
#include <stdlib.h>

void read_rgb (unsigned char *file, unsigned char *buffer, int rows, int columns);
void print_buffer(unsigned char *buffer, int size);

int main(int argc, char	*argv[])
{	
		// IMAGE 
	 if( argc == 6 ) {
	int i;
	for (i=1 ; i<argc; i++){
   //   printf("The argument supplied is: %s\n", argv[i]);
}

   }	
   else if( argc > 6 ) {
      printf("Too many arguments supplied.\n");
	return 0;
   }
   else {
      printf("More argument's expected.\n");
	return 0;
   }
 	FILE *pImg1; 
 	FILE *pFile;
	FILE *pmask;
 	int width =  atoi (argv[4]);
 	int high = atoi (argv[5]);
 	int imageSize = width * high;
	printf("%s will be overlaid over %s using %s as a mask\n",argv[1] ,argv[2] ,argv[3]);
	printf("image size is: %d by %d \n",width,high);
    // BUFFER 
    unsigned char buffer[imageSize]; 
    
    // READ RGB 
	unsigned char *pointerFileRead;
	pointerFileRead = (unsigned char*) malloc(imageSize * 3);
	
	//IMAGE 1
	pImg1 = fopen(argv[1], "r+b"); 
	if(!feof(pImg1)){
	printf ("PRIMER IMAGEN\n");		
    fread(pointerFileRead,(imageSize*3), (imageSize), pImg1); //Leo la img y lo guardo en pointerFileRead
   // read_rgb(pointerFileRead,buffer,high,width); //Guargo la img al buffer
    //print_buffer(pointerFileRead,(imageSize));

    fclose(pImg1); 
	}

	return 0;
}



void read_rgb (unsigned char *file, unsigned char *buffer, int rows, int columns){
	
    	int indexBuffer= 0; 
		for ( int i = 0 ; i < columns ; i++ ) {
     		for ( int j = 0 ; j < rows ; j++ ) {
     		
         			buffer[indexBuffer]= file[indexBuffer];
         			printf ("file: %d : Buffer: %d\n",file[indexBuffer],buffer[indexBuffer]); 
					indexBuffer++;       		
			}	
		}
}


void print_buffer(unsigned char *buffer, int size){
	
		printf("\nBuffer of %d elements:\n\n\n", size);
		
		for (int i=0 ; i < size; i++){
			
			printf("%d \t\t\t",buffer[i]);
		
			printf("\n");
				
		}
}
