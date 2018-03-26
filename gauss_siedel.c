#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    printf("Enter in format\nFirst line >> size\nFollowing n+1 lines >> matrix and constants\nNext line >> Epsilon & No of Max Iterations\n\n");
    int n;
    scanf("%d", &n);
    double **arr = allocate2(n,n), **new = allocate2(n,n);
    double *co = allocate(n), *con = allocate(n), *a = allocate(n);
    int *avr = (int *)malloc(n*sizeof(int)), *perm = (int *)malloc(n*sizeof(int));
    double ae, t, s, e=0;
    int mxit=0, flag=1;
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)
            scanf("%lf", &arr[i][j]);//elements
	for(int i=0; i<n; i++)
		scanf("%lf", &co[i]);//constants    
    scanf("%lf%d", &ae, &mxit);

    for(int i=0; i<n; i++)
        {
            avr[i] = 1;
            perm[i] = i;
            a[i]=0;
        }
    for(int i=0; i<n; i++)
    {
        int max=0; double sum=0;
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] > arr[i][max])
                max = j;
            sum += arr[i][j];
        }
        if(arr[i][max] >= sum - arr[i][max])
        {
            if(max == i || avr[max])
            {    
                if(max != i)
                    {
                        perm[i] = max;
                        perm[max] = i;
                    }
                avr[max] = 0;
            }   
            else {flag=0; break;}
        }
        else {flag=0; break;}
    }
    if(flag == 0)
        {
            printf("\nNot diagonally dominant. Solution not found!");
            return 0;
        }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            new[i][j] = arr[perm[i]][j];
            con[i]=co[perm[i]];    
        }
    free2(arr,n,n); free(co); free(perm); free(avr);
    printf("\nIterations\t\tX\t\tY\t\tZ\n");

    for(int r=1; r<=mxit; r++)
    {
        for(int i=0; i<n; i++)
        {
            s=0;
            for(int j=0; j<n; j++)
            if(j!=i) 
                s += new[i][j] * a[j];
            t = (con[i]-s)/new[i][i];
            e = fabs(a[i]-t);
            a[i] = t;
        }
        printf("%9d\t",r);
        for(int i=0;i<n;i++)
            printf("%7.7f\t",a[i]);
        printf("\n");
        if(e < ae)
        {
            printf("Solution:\n");
            for(int i=0;i<n;i++)
            printf("%7.7f\t", a[i]);
            return 0;
        }
    }
    free2(new,n,n); free(con); free(a);
}
// OUPUT...

// Enter in format
// First line >> size
// Following n+1 lines >> matrix and constants
// Next line >> Epsilon & No of Max Iterations

// 3
// 3 2 1
// 4 6 20
// 2 7 2
// 2 4 1
// 0.000001 20

// Iterations              X               Y               Z
//         1       0.6666667       -0.0476191      0.0809524
//         2       0.6714286       -0.0721089      0.0873469
//         3       0.6856236       -0.0779916      0.0862728
//         4       0.6899035       -0.0789075      0.0856915
//         5       0.6907079       -0.0789713      0.0855498
//         6       0.6907976       -0.0789564      0.0855274
//         7       0.6907951       -0.0789493      0.0855258
//         8       0.6907910       -0.0789476      0.0855261
// Solution:
// 0.6907910       -0.0789476      0.0855261