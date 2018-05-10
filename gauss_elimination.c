#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double *allocate(int n)
{
    double *p =  (double *)malloc(n*sizeof(double));
    for(int i=0; i<n; i++)
        p[i] = 0;
    return p;
}
double **allocate2(int m, int n)
{
    double **p = (double**)malloc(m*sizeof(double*));
    for(int i=0; i<m; i++)
        p[i] = allocate(n);
    return p;
}
double **copy(int n, double **arr)
{
    double **m = allocate2(n,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        m[i][j] = arr[i][j];
    return m;
}
void disp(int n, double **a)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%0.2lf\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// void modify(int n, double **a, double **aug)
// {
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i>j)
//             {
//                 double p = a[i][j] / a[j][j];
//                 for(int k=0; k<n; k++)
//                 {
//                     a[i][k] -= p*a[j][k];
//                     aug[i][k] -= p*a[j][k];
//                 }
//             }
//         }
//     }
//     disp(n, a); disp(n, aug);
//     for(int i=n-1; i>=0; i--)
//     {
//         for(int j=n-1; j>=0; j--)
//         {
//             if(i<j && a[j][j] != 0)
//             {
//                 double p = a[i][j] / a[j][j];
//                 for(int k=0; k<n; k++)
//                 {
//                     a[i][k] -= p*a[j][k];
//                     aug[i][k] -= p*a[j][k];
//                 }
//             }
//         }
//     }
// }
void mul(int n, double **a, double **aug)
{
    double sum = 0, **prod= allocate2(n,n);
    for (int c = 0; c < n; c++) 
      for (int d = 0; d < n; d++) 
      {
        for (int k = 0; k < n; k++) 
          sum = sum + a[c][k]*aug[k][d];
        prod[c][d] = sum;
        sum = 0;
      }
    disp(n, prod);
}
int main()
{
    int n;
    scanf("%d", &n);
    double **m = allocate2(n,n), **aug = allocate2(n,n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        scanf("%lf", &m[i][j]);
        aug[i][i] = 1;
    }
    double **cp = copy(n, m);
    modify(n, m, aug);
    printf("Mat:\n");
    disp(n, m);
    printf("Aug:\n");
    disp(n, aug);
    printf("Cp:\n");
    disp(n, cp);
    printf("Multiplying:\n");
    mul(n, cp, aug);

}