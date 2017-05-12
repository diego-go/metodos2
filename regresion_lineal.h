#ifndef REGRESION_LINEAL_H_INCLUDED
#define REGRESION_LINEAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "tabla.h"


float interpolax(float a,float b, float x_user)
{
    return x_user*b+a;
}

void regresion_lineal(tabla ot){
    int i,n;
    float sumx,sum_sqx,sumy,sumxy,a,b;
    n=ot.x.size();
    float x[n];
    float y[n];
    float xy[n];
    float x2[n];
    sumx =0;
    sum_sqx =0;
    sumy=0;
    sumxy=0;
    xy[n]=x[n]*y[n];
    x2[n]=x[n]*x[n];
    for(i=0;i<n;i++)
    {
        xy[i]=0;
        x2[i]=0;
        x[i]=ot.x[i];
        y[i]=ot.y[i];
        xy[i]=x[i]*y[i];
        x2[i]=x[i]*x[i];
        sumx = sumx +x[i];
        sum_sqx = sum_sqx + (x[i]*x[i]);
        sumy= sumy + y[i];
        sumxy = sumxy + (x[i]*y[i]);
    }
    cout<<"\n\tRegresion lineal por minimos cuadrados."<<endl;
   printf("\t _________________________________________________________\n");
   printf("\t|Xi\t\tYi\t\tXiYi\t\tX^2\t |\n");
   printf("\t _________________________________________________________\n");
   for(int i=0;i<n;i++)
   {
       printf("\t|%f\t%f\t%f\t%f|\n",x[i],y[i],xy[i],x2[i]);
       printf("\t _________________________________________________________\n");
   }
    b = (sumxy-(sumx*sumy)/n)/(sum_sqx-(sumx*sumx)/n);
    a = (sumy/n)-(b*sumx/n);
    printf("\n\tResultado de la regresion lineal: Y= %f(x) + %f\n\n\n",b,a);
    int s;
    cout<<"\n\tSi desea interpolar un valor teclee 1, de lo contrario teclee 2: ";
    while(cin>>s &&(s==1))
    {
    	cout<<"\n\tIngrese el valor que desea interpolar: ";
        float x_user;
        cin>>x_user;
        cout<<"\n\tInterpolacion de f("<<x_user<<")= "<<interpolax(a,b,x_user)<<endl;
        cout<<"\n\tSi desea interpolar un valor teclee 1, de lo contrario teclee 2: ";
    }
}

#endif
