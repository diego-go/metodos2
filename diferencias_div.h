#ifndef DIFERENCIAS_DIV_H_INCLUDED
#define DIFERENCIAS_DIV_H_INCLUDED

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include "tabla.h"

using namespace std;

void creaMatriz(double**,int,tabla ot);
void muestraMatriz(double**,int);
void diferenciasDiv(double **,int);
float interpolacion(double**,int, double);


void diferencias_divididas (tabla ot){
    int n;
    double **mat, inp;
    double *vectorfila;
    double *vectorcol;
    //cout<<"\tPOLINOMIO DIFERENCIAS DIVIDIDAS\n\n";
    n=ot.x.size()+1;
    cout<<"\n\tIngrese el numero a interpolar: ";
    cin>>inp;
    mat=(double**)calloc(n, sizeof(double*));
    vectorcol=(double*)calloc(n, sizeof(double*));
    vectorfila=(double*)calloc(n, sizeof(double*));
     for (int i=0; i<n; i++)
        mat[i]=(double*)calloc(n, sizeof(double));
    creaMatriz(mat,n,ot);
    muestraMatriz(mat,n);
    diferenciasDiv(mat,n);
    muestraMatriz(mat,n);
    cout<<interpolacion(mat,n,inp)<<endl;

}

void creaMatriz(double** mat, int n, tabla ot)
{
       for (int i=0; i<n-1; i++)
        {
            mat[i][0]= ot.x[i];
            mat[i][1]=ot.y[i];
        }
        cout<<"\n";
}

void muestraMatriz(double** mat, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n\n";
    }
    cout<<"\n";
}

void diferenciasDiv(double **mat, int n)
{
    int aux1=2, a=1;
for (int j=2; j<n;j++)
{
    for(int i=0;i<n-aux1;i++)
    {
        mat[i][j]=(mat[i+1][a]-mat[i][a])/(mat[i+a][0]-mat[i][0]);
    }
    a+=1;
    aux1+=1;
}
}

float interpolacion(double **mat, int n, double inp)
{
   float k=0, auxiliar=1;
   for(int i=0; i<n;i++)
    {
    for(int j=0; j<i;j++)
    {
       auxiliar=auxiliar*(inp-mat[j][0]);
    }
    k=k+auxiliar*mat[0][i+1];
    auxiliar=1;
    }
    return k;
}



#endif
