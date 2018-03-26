#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    printf("Enter in format\nFirst line >> size\nFollowing n+1 lines >> matrix and constants\nNext line >> Epsilon & No of Max Iterations\n\n");
    int n;
    scanf("%d", &n);
    float **arr = (float **)malloc(n*sizeof(float *)), **new = (float **)malloc(n*sizeof(float *));
    float *co = (float *)malloc(n*sizeof(float)), *con = (float *)malloc(n*sizeof(float)), *a = (float *)malloc(n * sizeof(float));
    int *avr = (int *)malloc(n*sizeof(int)), *perm = (int *)malloc(n*sizeof(int));
    float ae, t, s, e=0;
    int mxit=0, flag=1;
    for(int i=0; i<n; i++)
        {
            arr[i] = (float *)malloc(n*sizeof(float));
            new[i] = (float *)malloc(n*sizeof(float));
        }
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)
            scanf("%f", &arr[i][j]);//elements
	for(int i=0; i<n; i++)
		scanf("%f", &co[i]);//constants    
    scanf("%f%d", &ae, &mxit);


    for(int i=0; i<n; i++)
        {
            avr[i] = 1;
            perm[i] = i;
            a[i]=0;
        }
    for(int i=0; i<n; i++)
    {
        int max=0; float sum=0;
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
    printf("\nIteration\tSolutions\n");

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
            printf("%.7f\t",a[i]);
        printf("\n");
        if(e < ae)
        {
            printf("\nConverges in %3d iterations\n", r);
            for(int i=0;i<n;i++)
            printf("a[%d] = %7.7f\n", i+1, a[i]);
            return 0;
        }
    }
}
// OUPUT...

// Enter in format
// First line >> size
// Following n+1 lines >> matrix and constants
// Next line >> Epsilon & No of Max Iterations

// 3
// 3 2 1
// 4 6 20
// 4 9 1
// 2 5 6
// 0.00001 20

// Iteration       Solutions
//         1       0.6666667       0.3703704       0.0055556
//         2       0.4179012       0.4803155       0.0223251
//         3       0.3390146       0.5135129       0.0281432
//         4       0.3149437       0.5235646       0.0299419
//         5       0.3076429       0.5266096       0.0304885
//         6       0.3054308       0.5275320       0.0306542
//         7       0.3047606       0.5278115       0.0307044
//         8       0.3045575       0.5278962       0.0307196
//         9       0.3044960       0.5279218       0.0307243

// Converges in   9 iterations
// a[1] = 0.3044960
// a[2] = 0.5279218
// a[3] = 0.0307243