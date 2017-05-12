#ifndef SIMPSON13_H_INCLUDED
#define SIMPSON13_H_INCLUDED

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include "tabla.h"

using namespace std;


class _simpson13
{

private:
	float integral;
    float a;
	float b;
	float h;

public:
	_simpson13(tabla,int);
};

_simpson13::_simpson13(tabla ot,int on)
{
    float sum2=0,sum4=0;
	a=ot.x[0];
	cout<<"\n\tLimite inferior= "<<a<<endl;
	b=ot.x[ot.x.size()-1];
	cout<<"\n\tLimite superior= "<<b<<endl;
	h=(b-a)/on;
	cout<<"\n\th= "<<h<<endl;
    for(unsigned int i=0; i<ot.x.size();i++)
    {
        if(i%2==0 && ot.x[i]!=b && ot.x[i]!=a)
            sum2+=ot.y[i];
        else if(i%2!=0 && ot.x[i]!=b && ot.x[i]!=a)
        	sum4+=ot.y[i];
    }
        integral=(h/3)*(ot.y[0]+ot.y[ot.x.size()-1]+2*sum2+4*sum4);
    	cout<<"\n\tResultado de la integral: "<<setprecision(16)<<integral<<endl;
}

#endif
