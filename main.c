#include <stdio.h>
#include <stdlib.h>

void read_rgb (unsigned char *file, unsigned char *buffer, int rows, int columns);
void print_buffer(unsigned char *buffer, int size);

int main()
{	
	// IMAGE 
 	FILE *pImg1; 
 	FILE *pFile;
 	int width = 200;
 	int high = 150;
 	int imageSize = width * high;
    
    // BUFFER 
    unsigned char buffer[imageSize]; 
    
    // READ RGB 
	unsigned char *pointerFileRead;
	pointerFileRead = (unsigned char*) malloc(imageSize * 3);
	
	//IMAGE 1
	pImg1 = fopen("img1.rgb", "r+b"); 
	if(!feof(pImg1)){
	printf ("PRIMER IMAGEN\n");		
    fread(pointerFileRead,(imageSize*3), (imageSize), pImg1); //Leo la img y lo guardo en pointerFileRead
    read_rgb(pointerFileRead,buffer,high,width); //Guargo la img al buffer
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