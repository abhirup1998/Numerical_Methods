
#include<stdio.h>
#include<math.h>
#define EPSILON 0.000001
#define delta 0.0000001
#define ZERO 0.0000000000000000001
double *allocate(int n)
{
	double *p = (double*)malloc(n*sizeof(double));int i=0;
	for(i=0; i<n; i++)
		p[i] = 0;
	return p;
}
int n;
double *c, *e;
double function(double x)
{
	int i; double r=0.0;
	for(i=0; i<n; i++)
		r = r + c[i]*pow(x,e[i]);
	return r;
}
void bisection(double a, double b)
{
    if(function(a)*function(b) >= 0)
    {
        printf("Incorrect a and b.\n");
        return;
    }
    double c = a;
    while((b-a) >= EPSILON)
    {
        // printf("range @ ( %lf, %lf )", a, b);
        c = (a+b)/2;
        double fc = function(c);
        // printf("\tfc = %lf\n", fc);
        if(fabs(fc) < ZERO)
            // {   printf("Brk Point.\n");
                break;
            // }
        else if(fc * function(a) < 0)
            b = c;
        else a = c;
        }
    printf("Root @ %lf", c);
}
int main()
{
	// int n;
	printf("Enter in format\nFirst line >> No of terms\nFollowing n lines >> The coeff. and expon. of each term\nNext line >> Two value range\n");
	scanf("%d", &n);
    int i = 0;
    c = allocate(n); e = allocate(n);
    for(i=0; i<n; i++)
        scanf("%lf %lf", &c[i], &e[i]);
    double x0, x1;
    scanf("%lf %lf", &x0, &x1);
    bisection(x0, x1);
	free(c); free(e);
    return 0;
}
