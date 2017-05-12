#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED

#include <vector>
using namespace std;

class tabla
{
public:
	tabla(int);
	vector <float> x;
	vector <float> y;
	void crear_tabla(int);

};


tabla:: tabla(int n)
{
	float var;
	for (int i = 0; i < n; i++)
	{
		cout<<"\tx_"<<i<<": ";
		cin>>var;
		x.push_back(var);
		cout<<"\ty_"<<i<<": ";
		cin>>var;
		y.push_back(var);
	}
}

void tabla::crear_tabla(int n)
{
    float var;
    vector <float> ax;
    vector <float> ay;

	for (int i = 0; i < n; i++)
	{
		cout<<"\tx_"<<i<<": ";
		cin>>var;
		ax.push_back(var);
		cout<<"\ty_"<<i<<": ";
		cin>>var;
		ay.push_back(var);
	}
	x=ax;
	y=ay;
}
#endif 
