#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<cstdlib>

using namespace std;

void llenadorandom(int arreglo[])
{ 
    srand(time(NULL));

    for (int indice=0; indice<10000; indice++)
    {
        arreglo[indice]=rand()%300;

    }
}

void promedio(int arreglo[], float& prom,float&sumprom)
{
    for(int indice=0; indice<10000;indice++)
    {
        sumprom=sumprom+arreglo[indice];

    }
            prom=sumprom/10000;

}

void varianza(int arreglo[], float&sumvar, float&prom, float&var)
{
    for(int indice=0; indice<10000; indice++)
    {
        sumvar=sumvar+(prom-arreglo[indice]);
    }
    var=(sumvar*sumvar)/(9999);
}

void desviacion(float&desv,float&var){
    for(int indice=0; indice<10000; indice++){
        desv=sqrt(var);
    }
    
    
}

int main(int argc, char const *argv[])
{   
    int arreglo[10000];
    int op,op1;
    float prom, sumprom=0,sumvar=0, var, desv;
    
    while(op1==0)
    {
    cout<<"1.- Llenar y mostrar arreglo"<<endl;
    cout<<"2.- Mostrar promedio"<<endl;
    cout<<"3.- Mostrar Varianza"<<endl;
    cout<<"4.- Mostrar Desviacion Estandar"<<endl;
    cout<<"5.- Salir"<<endl;
    cin>>op;
    
    
    if(op==1)
    {

        llenadorandom(arreglo);
        
        for(int indice=0; indice<10000; indice++){
            cout <<"numero "<<indice<<" arreglo "<<arreglo[indice]<<endl;
        }
    }

    if(op==2){
        promedio(arreglo,prom,sumprom);
        cout<<"El promedio es: "<<prom<<endl;
    }

    if(op==3)
    {
        varianza(arreglo,sumvar,var, prom);
        cout<<"La varianza es: "<<var<<endl; 
    }
    if(op==4){
        desviacion(desv,var);
        cout<<"La desviacion es:"<<desv<<endl;
    }

    if(op==5){
        op1=1;
        cout<<"chauchera"<<endl;
    }
        return 0;
    }
}



