#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	double *X = allocate(n), *Y = allocate(n), *theta = allocate(n), val=0.0;
	double **grad = allocate2(n,n);
	float m, prod=1, h;
	for(int i=0; i<n; i++)
		scanf("%lf", &X[i]);
	for(int i=0; i<n; i++)
		scanf("%lf", &Y[i]);

     
	//Calculating equation
	for(int j=0;j<n-1;j++)
        {
            for(int i=0;i<(n-j-1);i++)
            {
                if(j==0)
                    grad[i][j]=(Y[i+1]-Y[i])/(X[i+1]- X[i]);
                else
                    grad[i][j]=(grad[i+1][j-1]-grad[i][j-1])/(X[i+j+1] - X[i]);
            }
        }
     printf("\nGradient Table...\n");
     for(int i=0; i<n; i++)
     {
          for(int j=0; j<n; j++)
               printf("%lf\t", grad[i][j]);
          printf("\n");
     }
     printf("\nCoeffs are...\n");
	printf("%lf\t", Y[0]);
	for(int i=0; i<n-1; i++)  
	     printf("%lf\t", grad[0][i]);
     printf("\n");
     printf("\nEnter target X?");
     scanf("%lf", &val);
     double ans = Y[0], p=1.0;
     for(int i=1; i<n-1; i++)
     {
          p *= (val - X[i-1]);
          ans += grad[0][i-1]*p;
     }
     printf("computed Y = %lf\n", ans);
}
/*Enter in format*/
/*First line >> size*/
/*Following 2 lines >> X and Y*/

/*4*/
/*2 4 7 9*/
/*10 26 65 101*/

/*Gradient Table...*/
/*8.000000	1.000000	0.000000	0.000000	*/
/*13.000000	1.000000	0.000000	0.000000	*/
/*18.000000	0.000000	0.000000	0.000000	*/
/*0.000000	0.000000	0.000000	0.000000	*/

/*Coeffs are...*/
/*10.000000	8.000000	1.000000	0.000000	*/

/*Enter target X?5*/
/*computed Y = 37.000000*/

