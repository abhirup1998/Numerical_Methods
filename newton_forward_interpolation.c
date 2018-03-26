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
void free2(double **arr, int m, int n)
{
	for(int i=0; i<m; i++)
		free(arr[i]);
	free(arr);
}
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
	printf("Enter in format\nFirst line >> size\nFollowing 2 lines >> X and Y\n\n");
	int n;
	scanf("%d", &n);
	double *X = (double*)malloc(n*sizeof(double));
	double *Y = (double*)malloc(n*sizeof(double));
	double *theta = (double*)malloc(n*sizeof(double)), *coeff=(double*)malloc(n*sizeof(double));
	double **A = (double **)malloc(n*sizeof(double *)), **tmp = (double **)malloc(n*sizeof(double *)), **d = (double **)malloc(n*sizeof(double *));
	for(int i=0; i<n; i++)
	{
		A[i] = (double *)malloc(n*sizeof(double));
		tmp[i] = (double *)malloc(n*sizeof(double));
		d[i] = (double *)malloc(n*sizeof(double));
		for(int j=0; j<n; j++)
			d[i][j] = 0;
	}
	float m, prod=1, h;
	for(int i=0; i<n; i++)
		scanf("%lf", &X[i]);
	for(int i=0; i<n; i++)
		scanf("%lf", &Y[i]);
	h = X[1] - X[0];

	//Calculating equation
	for(int j=0;j<n-1;j++)
        {
            for(int i=0;i<(n-j);i++)
            {
                if(j==0)
                    d[i][j]=Y[i+1]-Y[i];
                else
                    d[i][j]=d[i+1][j-1]-d[i][j-1];
            }
        }
	theta[0] = Y[0];
	for(int i=1; i<n; i++)
	{   
		m = fact(i);
		theta[i] = d[0][i-1]/(m*pow(h,i));
	}
	printf("\nTheta values...\n");
	for(int i=0; i<n; i++)
		printf("%7.7lf ", theta[i]);
	printf("\n");

	//Calculating approximated polynomial
	for(int i=0; i<n; i++)
		if(i==0)
			A[0][i]=1;
		else
			A[0][i]=-X[i-1];
	for(int i=0; i<n; i++)
		if(i==0)
			A[1][i]=0;
		else
			A[1][i]=1;
	for(int i=2; i<n; i++)
		for(int j=0; j<n; j++)
			A[i][j]=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			tmp[i][j]=A[i][j];
	for(int i=1; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			double *t_tmp=(double *)malloc((2+i)*sizeof(double));
			for(int k=0; k<2+i; k++)
			{
				t_tmp[k]=tmp[k][j];
				tmp[k][j]=0;
			}
			for(int l=0; l<=1; l++)
				for(int k=0; k+l<2+i; k++)
					tmp[k+l][j] += A[l][i]*t_tmp[k];
			free(t_tmp);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		coeff[i]=0;
		for(int j=i; j<n; j++)
			coeff[i] = coeff[i] + theta[j]*tmp[i][j];
	}
	printf("\nRequired coefficients are...\n");
	for(int i=0; i<n; i++)
		printf("x^%d ... %lf\n", i, coeff[i]);
	printf("\nComparing given values and computed values...\n");
	printf("Given_X\t\tGiven_Y\t\tComputed_Y\n");
	for(int i=0; i<n; i++)
		printf("| %lf\t| %lf\t| %lf\n", X[i], Y[i], eval_pol(coeff, n-1, X[i]));
	
	free(Y); free(theta);
	free2(A, n, n); free2(tmp, n, n);free2(d, n, n);
	double x = 0;
	printf("\nEnter X values to be interpolated. Keep within valid range(%lf to %lf).", X[0], X[n-1]);
	while(1)
	{	printf("\n\nX ? ");
		scanf("%lf", &x);
		printf("Y = %7.7lf", eval_pol(coeff, n-1, x));
	}
	free(X); free(coeff);
}
// OUTPUT...

// Enter in format
// First line >> size
// Following 2 lines >> X and Y

// 5
// 1891 1901 1911 1921 1931
// 46 66 81 93 101

// Theta values...
// 46.0000000 2.0000000 -0.0250000 0.0003333 -0.0000125

// Required coefficients are...
// x^0 ... -167340852.636012
// x^1 ... 349907.925967
// x^2 ... -274.385575
// x^3 ... 0.095633
// x^4 ... -0.000013

// Comparing given values and computed values...
// Given_X         Given_Y         Computed_Y
// | 1891.000000   | 46.000000     | 46.000000
// | 1901.000000   | 66.000000     | 66.000000
// | 1911.000000   | 81.000000     | 81.000000
// | 1921.000000   | 93.000000     | 93.000000
// | 1931.000000   | 101.000000    | 101.000000

// Enter X values to be interpolated. Keep within valid range(1891.000000 to 1931.000000).

// X ? 1899
// Y = 62.5168001

// X ? 1922
// Y = 94.0224875

// X ? ^C