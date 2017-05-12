#ifndef REGRESION_CUADRATICA_H_INCLUDED
#define REGRESION_CUADRATICA_H_INCLUDED

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include "tabla.h"

class _regresioncuadratica
{
private:
    float sumx, sumy, sumxx, sumx3, sumx4, sumxy, sumx2y;
    unsigned int on;
public:
	_regresioncuadratica(tabla);
	void resuelve_sistema();
};

_regresioncuadratica:: _regresioncuadratica(tabla ot)
{

	on=ot.x.size();
	sumx=0;
    sumy=0;
    sumxx=0;
    sumx4=0;
    sumx3=0;
    sumxy=0;
    sumx2y=0;
	for (unsigned int i = 0; i < on; i++)
	{
		sumx+=ot.x[i];
		sumy+=ot.y[i];
		sumxx+=ot.x[i]*ot.x[i];
		sumx4+=pow(ot.x[i],4);
		sumx3+=pow(ot.x[i],3);
		sumxy+=ot.x[i]*ot.y[i];
		sumx2y+=ot.x[i]*ot.x[i]*ot.y[i];
		cout<<setprecision(4)<<ot.x[i]<<"\t";
		cout<<setprecision(4)<<ot.y[i]<<"\t";
		cout<<setprecision(4)<<ot.x[i]*ot.x[i]<<"\t";
		cout<<setprecision(4)<<pow(ot.x[i],4)<<"\t";
		cout<<setprecision(4)<<pow(ot.x[i],3)<<"\t";
		cout<<setprecision(4)<<ot.x[i]*ot.y[i]<<"\t";
		cout<<setprecision(4)<<ot.x[i]*ot.x[i]*ot.y[i]<<endl;
	}

}

void _regresioncuadratica:: resuelve_sistema()
{
	float mat[3][4], x[3],c;
	mat[0][0]=sumx4; mat[0][1]=sumx3; mat[0][2]=sumxx; mat[0][3]=sumx2y;
	mat[1][0]=sumx3; mat[1][1]=sumxx; mat[1][2]=sumx;  mat[1][3]=sumxy;
	mat[2][0]=sumxx; mat[2][1]=sumx;  mat[2][2]=on;     mat[2][3]=sumy;


    for(int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }
	for(int j=0; j<3; j++)
    {
        for(int i=0; i<3; i++)
        {
            if(i!=j)
            {
                c=mat[i][j]/mat[j][j];
                for(int k=0; k<4; k++)
                    mat[i][k]=mat[i][k]-c*mat[j][k];
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        cout<< "matriz escalonada"<<endl;
        for (int j=0;j<4;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }
    for(int i=0; i<3; i++)
        x[i]=mat[i][3]/mat[i][i];
    cout<<"a= "<<x[0]<<endl;
    cout<<"b= "<<x[1]<<endl;
    cout<<"c= "<<x[2]<<endl;
}

#endif // REGRESION_CUADRATICA_H_INCLUDED
