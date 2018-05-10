#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPSILON 0.000001
#define delta 0.0000001
#define ZERO 0.0000001
double *allocate(int n)
{
	double *p = (double*)malloc(n*sizeof(double));int i=0;
	for(i=0; i<n; i++)
		p[i] = 0;
	return p;
}
int n;
double *c, *e, *c_, *e_;
double function(double x)
{
	int i; double r=0.0;
	for(i=0; i<n; i++)
		r = r + c[i]*pow(x,e[i]);
	return r;
}
double deriv(double x)
{
    int i; double r=0.0;
	for(i=0; i<n; i++)
		r = r + c_[i]*pow(x,e_[i]);
	return r;
}
int oneroot(double a, double b)
{
    // printf("oneroot_ %.36lf %.36lf\n", a,b);
    if(function(a)*function(b) < 0)
        return 1;
    else
        return 0;
}
void bisection(double a, double b)
{
    printf("bisection_ ..\n");
    if(!oneroot(a,b))
    {
        printf("No single root in given range.\n");
        // return;
    }
    double c;
    while(b>a)
    {
        c = (a+b)/2;
        if(fabs(function(c)) < ZERO) 
            break;
        else if(oneroot(a,c)) b=c;
        else if(oneroot(c,b)) a=c;
        else 
        {
            printf("Ambig\n");
            break;
        }
    }
    printf("Root: %f\n", c);
}
void newton_raphson(double x)
{
    printf("nraphson_ ..\n ");
    double x1 = 0;
    while(1)
    {
        double c = function(x)/deriv(x);
        x1 = x - c;
        printf("%0.10lf - %0.10lf = %0.10lf\n", x, c, x1);
        if(fabs(x1-x) < ZERO)break;
        x = x1;
    }
    // return x1;
}
int main()
{
	// int n;
	printf("Enter in format\nFirst line >> No of terms\nFollowing n lines >> The coeff. and expon. of each term\nNext line >> Two value range\n");
	scanf("%d", &n);
    int i = 0;
    c = allocate(n); e = allocate(n);
    c_ = allocate(n); e_ = allocate(n);
    for(i=0; i<n; i++)
        scanf("%lf %lf", &c[i], &e[i]);
    double x0, x1;
    scanf("%lf %lf", &x0, &x1);
    printf("Function: ");
    for(int i=0; i<n; i++)
        if(c[i] != 0){
            printf("%0.1lfx^(%0.0lf) + ", c[i], e[i]);
        }
    printf("0\n");
    printf("Derivative: ");
    for(int i=0; i<n; i++)
    {
        c_[i] = c[i] * e[i];
        e_[i] = e[i] - 1;
        if(c_[i] != 0)printf("%0.1lfx^(%0.0lf) + ", c_[i], e_[i]);
    }
    printf("0\n");
    bisection(x0, x1);
    
    printf("\nDeriv @ a and b: %lf %lf\n",deriv(x0), deriv(x1));
    newton_raphson(x0);

	free(c); free(e);
    return 0;
}
