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
     printf("Enter n.");
     scanf("%d", &n);
     printf("Enter Xs in n folowing lines:");
     double *x = allocate(n), *y = allocate(n);
/*     for(int i=0;i<n;i++) { y[i] = func(x[i]);}*/
     double sum1=0, sum2=0;
     for(i=0; i<n; i++)
     {
          scanf("%lf", &x[i]);
          y[i] = func(x[i]);
          if(i==0 || i==n-1)
               sum1 +=y[i];
          else sum2 += y[i];
     }

     double h = x[1]-x[0];
     double res = h/2.0*(sum1 + 2*sum2);
     printf("\n%lf + 2(%lf) = %lf", sum1, sum2, res);
     
}
