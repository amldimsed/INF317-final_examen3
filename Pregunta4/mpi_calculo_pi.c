#include "stdio.h"
#include "mpi.h"
#include "math.h"
#include "stdarg.h"

void main(){
	int numero_procesadores, procesador_activo;
	double fac=1.0, my_pi=0.0, suma=0.0, h=10.0;
	
	// presicion ddecimal y cantidad de recorrido
	int contador = 4;
	
	 for (int i=1; i<=contador; i++){
	 	h*=10.0;
	 }
	//********************************
	MPI_Init(NULL, NULL);
    
    	MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
    	MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);
    	
    	if(procesador_activo==0){
    		MPI_Recv(&my_pi,1,MPI_DOUBLE,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    			
    			printf("%f\n",my_pi);

    	}
    	
    	if(procesador_activo==1){
    		
    		for (int i = 0; i <= contador; i++)
    		{
        		suma += ( 1.0 / pow(16.0,i) )*( (4.0 / (8.0 * i + 1.0)) -
                                           (2.0 / (8.0 * i + 4.0)) -
                                           (1.0 / (8.0 * i + 5.0)) -
                                           (1.0 / (8.0 * i + 6.0)) );
        		//my_pi +=1;
    		}
    		my_pi = ceilf (suma*h)/h;
    		MPI_Send(&my_pi,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
    	
    	}
    	
    	
    	MPI_Finalize();

}
/*
mpicc mpi_calculo_pi.c -o mpi_calculo_pi -lm
mpirun -np 2 mpi_calculo_pi


gcc pi_numero.c -o pi_numero.c -lm
./fibonacci

*/
