#include "stdio.h"
#include "string.h"
#include "mpi.h"

void main(){

    int numero_procesadores, procesador_activo;
    char string1[20]="carlos";
    char string2[20]="oso";
    char string3[20]="pedro";
    int i, length;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    /*
    printf("Introdusca Palabra:\n");
    //fflush( stdout );
    scanf("%s", string1);
    */
    
    
    MPI_Init(NULL,NULL);
    
    	MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
	MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);
	
	
    	if(procesador_activo==0){
    		MPI_Recv(&flag1,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&flag2,1,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&flag3,1,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		if (flag1) {
		printf("%s Falso \n", string1);
		}    
		else {
		printf("%s Verdad \n", string1);
		}
		
    		if (flag2) {
		printf("%s Falso \n", string2);
		}    
		else {
		printf("%s Verdad \n", string2);
		}
		
		if (flag3) {
		printf("%s Falso \n", string3);
		}    
		else {
		printf("%s Verdad \n", string3);
		}
    	
    	
    	}	
		
	if(procesador_activo==1){
    	length = strlen(string1);
		for(i=0;i < length ;i++){
			if(string1[i] != string1[length-i-1]){
		   
			flag1 = 1;
		   
		 	break;
			}
		}
	MPI_Send(&flag1,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}	
	
	if(procesador_activo==2){
    	length = strlen(string2);
		for(i=0;i < length ;i++){
			if(string2[i] != string2[length-i-1]){
		   
			flag2 = 1;
		   
		 	break;
			}
		}
	MPI_Send(&flag2,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	
	if(procesador_activo==3){
    	length = strlen(string3);
		for(i=0;i < length ;i++){
			if(string3[i] != string3[length-i-1]){
		   
			flag3 = 1;
		   
		 	break;
			}
		}
	MPI_Send(&flag3,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
		
   MPI_Finalize();
}
//mpicc palindromo.c -o palindromo
//mpirun -np 4 palindromo




