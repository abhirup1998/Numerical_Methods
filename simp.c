#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double *allocate(int n)
{
	double *p = (double*)malloc(n*sizeof(double));int i=0;
	for(i=0; i<n; i++)
		p[i] = 0;
	return p;
}
double func(double x){ return x/(1+x); }
int main()
{
     int n, i=0;
     scanf("%d", &n);
     printf("Enter Xs and Ys in n folowing lines:");
     double *x = allocate(n), *y = allocate(n);
     double sum1=0, sum2=0, sum3=0;
     for(i=0; i<n; i++)
     {
          scanf("%lf", &x[i]);
          y[i] = func(x[i]);
          if(i==0 || i==n-1)
               sum1 +=y[i];
          else if(i % 2 == 0) sum2 += y[i];
          else if(i % 2 == 1) sum3 += y[i];
     }
     double h = x[1]-x[0];
     double res = h/3.0*(sum1 + 2*sum2 + 4*sum3);
     printf("\n%lf + 2(%lf) + 4(%lf) = %lf", sum1, sum2, sum3, res);
     
}
