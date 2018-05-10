#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double eval_pol(double *pol, int degree, double point)
{
	double ans=0;
	for(int i=degree; i>=0; i--)
		ans = ans * point + pol[i];
	return ans;
}
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
void free2(double **arr, int m, int n)
{
	for(int i=0; i<m; i++)
		free(arr[i]);
	free(arr);
}
double *allocate(int n)
{
	double *p = (double*)malloc(n*sizeof(double));
	for(int i=0; i<n; i++)
		p[i] = 0;
	return p;
}
double **allocate2(int m, int n)
{
	double **arr = (double **)malloc(m*sizeof(double *));
	for(int i=0; i<m; i++)
		arr[i] = allocate(n);
	return arr;
}
int main()
{
	printf("Enter in format\nFirst line >> size\nFollowing 2 lines >> X and Y\n\n");
	int n;
	scanf("%d", &n);
	double *X = allocate(n), *Y = allocate(n), *theta = allocate(n), *coeff = allocate(n);
	double **A = allocate2(n,n), **tmp = allocate2(n,n), **d = allocate2(n,n);
	float m, prod=1, h;
	for(int i=0; i<n; i++)
		scanf("%lf", &X[i]);
	// for(int i=0; i<n; i++)
	// 	scanf("%lf", &Y[i]);
	h = X[1] - X[0];

	//Calculating equation
	// for(int j=0;j<n-1;j++)
    //     {
    //         for(int i=0;i<(n-j);i++)
    //         {
    //             if(j==0)
    //                 d[i][j]=Y[i+1]-Y[i];
    //             else
    //                 d[i][j]=d[i+1][j-1]-d[i][j-1];
    //         }
    //     }
	// theta[0] = Y[0];
	// for(int i=1; i<n; i++)
	// {   
	// 	m = fact(i);
	// 	theta[i] = d[0][i-1]/(m*pow(h,i));
	// }
	printf("\nTheta values...?\n");
	for(int i=0; i<n; i++)
		scanf("%lf", &theta[i]);
	printf("\n");

    double *f = allocate(2), *g = allocate(n+1), *c = allocate(n+1);
    g[0] = 1;
    
    for(int j=0; j<n; j++)
    {
        f[0] = -X[j]; f[1] = 1;
        double *h = allocate(n+1);
        for(int i=0; i<n; i++)
        {
            for(int ii=0; ii<2; ii++)
            {
                double a = g[i];
                h[ii+i] += g[i] * f[ii];
                // printf("h[%d] = g[%d] * f[%d].. ", ii+i, i, ii);
                // printf("%lf = %lf * %lf \n ", h[ii+i], a, f[ii]);
            }
        }
        for(int i = 0; i<n+1; i++)
            {
                g[i] = h[i];
                c[i] += g[i] * theta[j];
                // printf("%lf ", g[i]);
            }
        // printf("\n");
        // printf("Approx Pol c_: ");
        // for(int i =0; i<n+1; i++)
        //     {
        //         printf("%lf ", c[i]);
        //     }
        free(h);
        // printf("\n");
    }
    printf("Approx Pol c_: ");
    for(int i =0; i<n+1; i++)
        {
            printf("%lf ", c[i]);
        }
}