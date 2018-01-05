// Routine to solve a 2nd ODE
// x''=func(t,x,x') where x'=dx/dt & x''=dx'/dt
// by Runga Kutta method
#include<stdio.h>
#include"runga_kutta.h"

double ronga_kutta(double t_initial, double t_final, long int nsteps, double x_initial, double dxdt_initial, double ta[],double xa[])
{
	double dt,t,x,dxdt,xlast;
        double k1,k2,k3,k4,j1,j2,j3,j4;
        int i;

	dt=(t_final-t_initial)/nsteps;
	t=t_initial;
	x=x_initial;
        dxdt=dxdt_initial;

	for(i=0;i<=nsteps;i++)
	{
		ta[i]=t;
		xa[i]=x;
		xlast=x;
        	k1=func_1(t,xlast,dxdt);
		j1=func_2(t,xlast,dxdt);
		k2=func_1(t+(dt/2),xlast+(k1*dt/2),dxdt+(j1*dt)/2);
		j2=func_2(t+(dt/2),xlast+(k1*dt/2),dxdt+(j1*dt)/2);
		k3=func_1(t+(dt/2),xlast+(k2*dt/2),dxdt+(j2*dt)/2);
		j3=func_2(t+(dt/2),xlast+(k2*dt/2),dxdt+(j2*dt)/2);
		k4=func_1(t+dt,xlast+k3*dt,dxdt+j3*dt);
		j4=func_2(t+dt,xlast+k3*dt,dxdt+j3*dt);
		x=xlast+dt*(k1+2*k2+2*k3+k4)/6;
		dxdt=dxdt+dt*(j1+2*j2+2*j3+j4)/6;
		t=t+dt;
	}
	return x;
}
