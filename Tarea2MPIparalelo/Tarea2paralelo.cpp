#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<cstdlib>
#include"mpi.h"

using namespace std;

void llenadorandom(int arreglo[])
{ 
    srand(time(NULL));

    for (int indice=0; indice<2500; indice++)
    {
        arreglo[indice]=rand()%300;

    }
}

void promedio(int arreglo[], float& prom,float&sumprom)
{
    for(int indice=0; indice<2500;indice++)
    {
        sumprom=sumprom+arreglo[indice];

    }
            prom=sumprom/2500;

}


void varianza(int arreglo[], float&sumvar, float&prom, float&var)
{
    for(int indice=0; indice<2500; indice++)
    {
        sumvar=sumvar+(prom-arreglo[indice]);
    }
    var=(sumvar*sumvar)/(2499);
}

void desviacion(float&desv,float&var){
    for(int indice=0; indice<2500; indice++){
        desv=sqrt(var);
    }
    
    
}

    int arreglo[2500];
    int arreglo2 [2500];
    int arreglo3 [2500];
    int arreglo4 [2500];
	int size;
	int rank;
	float varianza1=0;
	float varianza2=0;
	float varianza3=0;
	float varianza4=0;
	float desviacion1=0;
	float desviacion2=0;
	float desviacion3=0;
	float desviacion4=0;
	
	MPI_Status estado;

int main  (int argc, char** argv)
{   
    MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
    totalprom=(promedio1+promedio2+promedio3+promedio4)/4;

    switch(rank)
    {
        case 0:
            promedio1=promedio(2500, arreglo);
            varianza1=varianza(2500, arreglo);
            desviacion1=desviacion(2500, arrego);
            MPI_Recv(&varianza2, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, &estado);
            MPI_Recv(&desviacion2, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, &estado);
            MPI_Recv(&varianza3, 1, MPI_FLOAT, 2, 0, MPI_COMM_WORLD, &estado);
            MPI_Recv(&desviacion3, 1, MPI_FLOAT, 2, 0, MPI_COMM_WORLD, &estado);
            MPI_Recv(&varianza4, 1, MPI_FLOAT, 3, 0, MPI_COMM_WORLD, &estado);
            MPI_Recv(&desviacion4, 1, MPI_FLOAT, 3, 0, MPI_COMM_WORLD, &estado);
            cout<<"El promedio 1 es "<<promedio1<<"su varianza y desviacion son "<<varianza1<<" "<<desviacion1<<endl;
            cout<<"El promedio 2 es "<<promedio1<<"su varianza y desviacion son "<<varianza2<<" "<<desviacion2<<endl;
            cout<<"El promedio 3 es "<<promedio1<<"su varianza y desviacion son "<<varianza3<<" "<<desviacion3<<endl;
            cout<<"El promedio 4 es "<<promedio1<<"su varianza y desviacion son "<<varianza4<<" "<<desviacion4<<endl;
        break;
        
        case 1:
            promedio2=promedio(2500, arreglo2);
            varianza2=varianza(2500, arreglo2);
            desviacion2=desviacion(2500, arrego2);
            MPI_Send(&varianza2, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
            MPI_Send(&desviacion2, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);


        break;
        
        case 2:
            promedio3=promedio(2500, arreglo3);
            varianza3=varianza(2500, arreglo3);
            desviacion3=desviacion(2500, arrego3);
            MPI_Send(&varianza3, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
            MPI_Send(&desviacion3, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
        
        break;

        case 3:
            promedio4=promedio(2500, arreglo4);
            varianza4=varianza(2500, arreglo4);
            desviacion4=desviacion(2500, arrego4);
            MPI_Send(&varianza3, 3, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
            MPI_Send(&desviacion3, 3, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);

        break;

        default:
        break;
    }

    MPI_Finalize();	

    return 0;
}