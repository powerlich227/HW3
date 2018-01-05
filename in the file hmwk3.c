#include <stdio.h>
#include <math.h>
#include "runga_kutta.h"

#define MAX_STEPS 101

FILE *ostream;
double k;

int main()
{
	double ti,tf,xi,x,xtrue,dxdti,error,stepsize;
	long int nsteps,i;
	double ta[MAX_STEPS],xa[MAX_STEPS];

	k=1;
	ti=0;
	tf=5;
	xi=0;
	dxdti=k;//define initial conditions

	for(nsteps=10;nsteps<=MAX_STEPS;nsteps++)
	{
		x=runga_kutta(ti,tf,nsteps,xi,dxdti,&ta[0],&xa[0]);
		xtrue=sin(k*tf);
		error=fabs((x-xtrue)/xtrue)*100;
		stepsize=(tf-ti)/nsteps;
		printf("step size=%f numerical=%e analytic=%e relative error=%e\n",stepsize,x,xtrue,error);
	}//evaluate the accuracy

	ostream=fopen("hmwk3a.dat","w");

	for(i=1;i<=100;i++)
	{
		xtrue=sin(k*ta[i]);
		fprintf(ostream,"time=%f calculated displacement=%f true displacement=%f\n",ta[i],xa[i],xtrue);
	}//write out data of step=101
	
	fclose(ostream);
}
