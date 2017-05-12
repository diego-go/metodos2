#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "simpson13.h"
#include "tabla.h"
#include "regresion_cuadratica.h"
#include "regresion_lineal.h"

#define z 10
#define T 20
#define m 13
#define e exp(1)
using namespace std;

int factorial (int num)
{
	int x,fact=1;
	for (x=num;x>=1;--x)
	{
		fact*= x;
	}
	return (fact);
}
void Newton (int tope)
{
    int i,j;
    float x, fx,p,K,h;
    float mat[T][T]={0};
    printf("\tIngresa los valores de x\n");
    for(i=0; i<tope; i++)
    {
        printf("\tX%i: ",i+1);
        scanf("%f",&mat[i][0]);
    }
	printf("\n\tIngresa los valores de f(x)\n");
    for(i=0; i<tope; i++)
    {
        printf("\tf(X%i): ",i+1);
        scanf("%f",&mat[i][1]);
    }
	system("cls");
    for(j=1; j<=(tope-1); j++)
    {
        for(i=0; i<(tope-j); i++)
        {
            mat[i][j+1]=(mat[i+1][j]-mat[i][j]);
	    }
   	}
    printf("\t\t TABLA DE DIFERENCIAS \n\n");
	for(j=0; j<tope; j++)
    {
       for(i=0;i<(tope+1); i++)
       {
       		if (mat[j][i]!=0)
       			printf("  %.6f  ",mat[j][i]);
	   }
        printf("\n");
    }
    printf("\n\tIngrese un valor para interpolar: ");
    scanf("%f", &x);
    h=abs((mat[1][0]-mat[0][0]));
	K=(x-mat[0][0])/h;
    p=1;
    fx=mat[0][1];
    for(i=0;i<(tope-1);i++)
    {
        p*=(K-i);
        fx+=(p*mat[0][i+2])/(factorial(i+1));
    }
    printf("\n\tH= %.6f \n\tValor de K= %.6f \n",h,K);
    printf("\n\tEl valor aproximado de %.6f es: %.6f\n", x,fx);
    system ("pause");
}
void CreaMemo (float **ap,int n)
{
	*ap=(float *)malloc(sizeof(float)*n);
}

void No_Lineal (int n)
{
	float *x,*fx,arre[4]={0},a,b, inter,y;
	CreaMemo (&x,n);
	CreaMemo (&fx,n);
	int i=0,de;
	putchar ('\n');
	for (i=0;i<n;++i)	{
		printf ("\tX%d: ",i);
		scanf ("%f",(x+i));
		printf ("\tf(X%d): ",i);
		scanf ("%f",(fx+i));
		arre[0]+=log(*(x+i));//suma xi
		arre[1]+=log(*(fx+i));//suma yi
		arre[2]+=(log(*(x+i)))*(log(*(fx+i)));//suma xi*yi
		arre[3]+=pow(log(*(x+i)),2);//suma xi^2	
	}
	printf ("\t    x        f(x)        ~Xi        ~Yi        XiYi      ~Xi^2\n")	;
	for (i=0;i<n;++i)
	{
		printf ("\t%0.6f   ",*(x+i));
		printf ("%0.6f   ",*(fx+i));
		printf ("%0.6f   ",log(*(x+i)));
		printf ("%0.6f   ",log(*(fx+i)));
		printf ("%0.6f   ",(log(*(x+i)))*(log(*(fx+i))));
		printf ("%0.6f   ",pow(log(*(x+i)),2));
		putchar ('\n');
	}
	printf ("\t%30.6f   ",arre[0]);
	for (i=1;i<4;++i)
	{
		printf ("%0.6f   ",arre[i]);
	}
	putchar ('\n');
	a=((n*arre[2])-(arre[0]*arre[1]))/((n*arre[3])-(pow(arre[0],2)));
	b=((arre[1])-(a*arre[0]))/(n);
	printf ("\n\ta: %0.6f\tb: %0.6f\n",a,b);
	printf ("\tPor lo tanto: \n");
	b=pow(e,b);	
	printf ("\talfa: %0.6f\n",b);
	printf ("\tbeta: %0.6f\n",a);
	printf ("\tAsi la funcion es: \n");
	printf ("\ty~= %0.6fx^%0.6f",b,a);
	printf("\n\t Quiere interpolar un valor Si=1 o No=2?  ");
    scanf("%d",&de);
    while(de==1)
    {
        printf("\n\t Ingrese el valor a interpolar: ");
        scanf("%f",&inter);
        y=b*(pow(inter,a));
        printf("\n\t El valor es: %f\n",y);
        printf("\n\tQuiere interpolar otro valor Si=1 o No=2?  ");
        scanf("%d",&de);
    }

}

void tabula1(double a[z][z+1],int xs)
{
    int i;
    for(i=0;i<xs;i++)
    {
         do
         {
             printf("\tx%i = ",i);
             scanf("%lg",&a[i][0]);
         }while(a[i][0]<=a[i-1][0]&&i!=0);
        printf("\ty%i = ",i);
        scanf("%lg",&a[i][1]);
    }
}
void Diferencias(double a[z][z+1],int xs)
{
    int i,j,k=0;
    for(i=1;i<xs;i++)
    {
        for(j=0;j<xs-i;j++)
        {
            a[j][i+1]=(a[j+1][i]-a[j][i])/(a[j+i][0]-a[j][0]);
        }
    }
    printf("\n\n");
    for(i=0;i<xs;i++)
    {
                     for(j=0;j<(xs+1)-k;j++)
                                          printf("%lg\t",a[i][j]);
                     printf("\n");
                     k++;
    }

}
double Divididas(double a[z][z+1],int xs,double val)
{
    double res;
    int i,j,t;
    for(i=0;i<xs-1;i++)
    {
        if(val>a[i][0]&&val<a[i+1][0])
        {
            t=i;
            i=xs;
        }
    }
    if(t<xs/2)
    {
        res=a[t][xs-t];
        cout<<"\n\tPolinomio: ";
        for(i=xs-t;i>1;i--)
        {
            printf("\n\n%lg * (%lg - %lg) + %lg = ",res,val,a[i+t-2][0],a[t][i-1]);
            res=res*(val-a[i+t-2][0])+a[t][i-1];
            printf("%lg",res);
        }
    }
    else
    {
        res=a[0][2+t];
        cout<<"\n\tPolinomio: ";
        for(i=t+2,j=0;j<t+1;i--,j++)
        {
            printf("\n\n%lg * (%lg - %lg) + %lg = ",res,val,a[j+1][0],a[j+1][i-1]);
            res=res*(val-a[j+1][0])+a[j+1][i-1];
            printf("%lg",res);
        }
    }
    return res;
}

void salida()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDesarrollo:\nDiego Hernández Landeros\nAna Karen Murillo Aceves");
	printf ("\nMaria Fernanda Ibarra Navarro\nDaniel Martínez Escalante\n");
	getch();
	exit(1);
}

int main()
{
 	setlocale(LC_CTYPE, "Spanish");
    int filas, n,op;
    system("color 3F");

    cout<<"\n\n\t\t\t+-------------------------------+"<<endl;
    cout<<"\t\t\t|      Metodos Numéricos II     |"<<endl;
    cout<<"\t\t\t|                               |"<<endl;
    cout<<"\t\t\t+-------------------------------+"<<endl;
    cout<<"\t\t\t|         INTEGRANTES           |"<<endl;
    cout<<"\t\t\t|                               |"<<endl;
    cout<<"\t\t\t|     Diego Hernández Landeros  |"<<endl;
    cout<<"\t\t\t|    Ana Karen Murillo Aceves   |"<<endl;
    cout<<"\t\t\t| Maria Fernanda Ibarra Navarro |"<<endl;
    cout<<"\t\t\t|   Daniel Martínez Escalante   |"<<endl;
    cout<<"\t\t\t+-------------------------------+"<<endl;
    cout<<"\t\t\t|          Grupo 2402           |"<<endl;
    cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\n\t\t\t";
	system("pause");
    system("cls");
    cout<<"\n\tSeleccione una opcion: "<<endl;
    cout<<"\n\t1)Integracion Simpson 1/3"<<endl;
    cout<<"\n\t2)Regresion cuadratica"<<endl;
    cout<<"\n\t3)Regresion lineal"<<endl;
    cout<<"\n\t4)Diferencias Divididas"<<endl;
    cout<<"\n\t5)Diferencias Finitas"<<endl;
    cout<<"\n\t6)Salir"<<endl;
    cout<<"\n\n\t";
    cout<<"\n\t\t)Ingresa una opción: ";
	
	while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
            	system ("color 4F");
            	system("cls");
            	printf("\n\t\tSIMPSON 1/3\n");
            	cout<<"\n\tIngrese los valores de la tabla con la que se va a trabajar:"<<endl;
    			cout<<"\n\tNumero de Filas: ";
    			cin>>filas;
    			tabla t(filas);
                cout<<"\n\tIngrese el valor de 'n': ";

                while(cin>>n && n%2!=0)
                {
                    cout<<"\n\tError,'n' debe ser par, ingrese un numero par: ";
                }
                _simpson13 s(t,n);
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
            	system ("color 4F");
            	system("cls");
            	printf("\n\t\tREGRESIÓN CUADRÁTICA\n");
            	cout<<"\n\tIngrese los valores de la tabla con la que se va a trabajar:"<<endl;
    			cout<<"\n\tNumero de Filas: ";
    			cin>>filas;
    			tabla t(filas);
                _regresioncuadratica r(t);
                r.resuelve_sistema();
                system("pause");
                system("cls");
            }
            break;
            case 3:
            {
            	system ("color 4F");
            	system("cls");
            	printf("\n\t\tREGRESIÓN LINEAL\n");
            	cout<<"\n\tIngrese los valores de la tabla con la que se va a trabajar:"<<endl;
    			cout<<"\n\tNumero de Filas: ";
    			cin>>filas;
    			tabla t(filas);
                regresion_lineal(t);

            }
            break;
			case 4:
            	system ("color 4F");
            	system("cls");
            	printf("\n\t\tDIFERENCIAS DIVIDIDAS\n");
            	{
				double datos[z][z+1],rest,x;
            	int no,i,j;
            	do
            	{
                	cout<<"\n\tIngrese los valores de la tabla con la que va a trabajar:"<<endl;
                	cout<<"\n\n\tNumero de filas: ";
	                scanf("%i",&no);
	            }
				while(no<3||no>10);
            	tabula1(datos,no);
            	cout<<"\n\tTabla de diferencias: "<<endl;
            	cout<<"\n\nX\ty\ty1\ty2\ty3\ty4"<<endl;
            	Diferencias(datos,no);
            	do
            	{
                	printf("\n\nIngrese el valor a interpolar: ");
                	scanf("%lg",&rest);
            	}
				while(rest<datos[0][0]||rest>datos[no-1][0]);
            	x=Divididas(datos,no,rest);
            	printf("\n\n\nResultado:   %lg\n\n",x);
            	getch();
				}
            break;
			case 5:
			{
				system ("color 4F");
				system("cls");
				int n=0;
				printf("\n\t\tDIFERENCIAS FINITAS\n");
    			cout<<"\n\tIngrese los valores de la tabla con la que se va a trabajar:"<<endl;
    			printf("\n\tDatos a trabajar: ");
    			scanf ("%d",&n);
    			Newton (n);					
			}
			break;
			case 6:
			{
				system ("color 1A");
				system ("cls");
				salida ();
			}	
			break;	

            default:
            	system("cls");
                cout<<"\n\tOpcion invalida. Intentalo de nuevo..."<<endl;
                system("pause");
             break;

        }
        system ("color 3F");
        system("cls");
		cout<<"\n\tSeleccione una opcion: "<<endl;
	    cout<<"\n\t1)Integracion Simpson 1/3"<<endl;
	    cout<<"\n\t2)Regresion cuadratica"<<endl;
	    cout<<"\n\t3)Regresion lineal"<<endl;
	    cout<<"\n\t4)Diferencias Divididas"<<endl;
	    cout<<"\n\t5)Diferencias Finitas"<<endl;
	    cout<<"\n\t6)Salir"<<endl;
	    cout<<"\n\n\t";
	    cout<<"\n\t\t)Ingresa una opción: ";


    }

    return 0;
}


