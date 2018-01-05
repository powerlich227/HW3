//solution of d2x/dt2=-k2x by runga_kutta method
//
#include <stdio.h>
#include <math.h>
#include "runga_kutta.h"

#define PI 3.141592653

FILE *ostream;
double a,l,g;

int main()
{
	double ti,tf,xi,x,xtrue,dxdti;
	long int nsteps,i;
	double xa[101],ta[101];

	l=1;
	a=0.2;
	ti=0;
	tf=10;
	xi=PI/120;
	dxdti=0;//define initial conditions

	runga_kutta(ti,tf,nsteps,xi,dxdti,&ta[0],&xa[0]);
	ostream=fopen("hmwk3b.dat","w");

	for(i=1;i<=100;i++)
	{
		fprintf(ostream,"time=%f calculated angle=%f\n",ta[i],xa[i]);
	}//write out data of step=101
	
	fclose(ostream);
}
double function_2(double t, double x, double dxdt)
{
	double d2xdt2;
	d2xdt2=-(a/l)*dxdt-(g/l)sin(x);
	return d2xdt2;
}
