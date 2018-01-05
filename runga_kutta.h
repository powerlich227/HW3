#ifndef runga_kutta
#define runga_kutta

double func_1(double t, double x, double dxdt);
double func_2(double t, double x, double dxdt);
double runga_kutta(double t_initial, double t_final, long int nsteps, double x_initial, double dxdt_initial, double ta[], double xa[]);

#endif
