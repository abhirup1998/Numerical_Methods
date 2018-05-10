
#include<stdio.h>
#include<math.h>
#define EPSILON 0.001
#define delta 0.0000001
double *allocate(int n)
{
	double *p = (double*)malloc(n*sizeof(double));int i=0;
	for(i=0; i<n; i++)
		p[i] = 0;
	return p;
}
double function(int n, double x, double *c, double *e)
{
	int i; double r=0.0;
	for(i=0; i<n; i++)
		r = r + c[i]*pow(x,e[i]);
	return r;
}
double derivative(int n, double x0, double *c, double *e)
{
	double y1, y2, x1, x2;
	x1 = x0 + delta;
	x2 = x0 - delta;
	y1 = function(n, x1, c, e);
	y2 = function(n, x2, c, e);
	return (double)(y2 - y1)/(x2 - x1);
}
double newtonRaphson(int n, double x, double *c, double *e)
{
    double h = function(n, x, c, e) / derivative(n, x, c, e);
	printf("Newton-Raphson...\n");
    while (1)
    {
        h = function(n, x, c ,e)/derivative(n, x, c, e);  
		printf("... %lf - (%lf)\n", x, h);
        x = x - h;
		if(fabs(h) < EPSILON) break;
    }
	return x;
}
int main()
{
	int n;
	printf("Enter in format\nFirst line >> No of terms\nFollowing n lines >> The coeff. and expon. of each term\nNext line >> Two value range\n");
	scanf("%d", &n);
	double *c = allocate(n), *e = allocate(n);
	int i = 0;
	for(i=0; i<n; i++)
		scanf("%lf %lf", &c[i], &e[i]);
    double x0, x1;
    scanf("%lf %lf", &x0, &x1);
    double m = (x0 + x1)/2.0;
	printf("Assumed root at %lf\n", m);
    printf("Root at %lf", newtonRaphson(n, m, c, e));
	free(c); free(e);
    return 0;
}
