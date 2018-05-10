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
double determinant(int n, double **a)
{
    double det=0;
    if(n == 1)
    {
        return a[0][0];
    }
    for(int j=0;j <n; j++)
    {
        double **b = allocate2(n-1,n-1);
        int jj=0, ix=0;
        for(int ii=1; ii<n; ii++)
            for(jj=0; jj<n; jj++)
            {
                if(jj == j)continue;
                b[ix/(n-1)][ix%(n-1)] = a[ii][jj];
                ix++;
            }
        int sgn = j&1? -1:1;
        det += sgn * a[0][j] * determinant(n-1, b);
    }
    return det;
}
double** inverse(int n, double **a)
{
    double **adj = allocate2(n,n), **inv;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double **b = allocate2(n-1,n-1);
            int ii=0, jj=0, ix=0;
            for(ii=0; ii<n; ii++)
            {
                if(ii == i)continue;
                for(jj=0; jj<n; jj++)
                {
                    if(jj == j)continue;
                    b[ix/(n-1)][ix%(n-1)] = a[ii][jj];
                    ix++;
                }
            }
            int sgn = (i+j)&1? -1:1;
            adj[i][j] = sgn*determinant(n-1, b);
        }
    }
    printf("Adjoint:\n");
    disp(n, adj);
    double Det = determinant(n,a);
    inv = allocate2(n,n);
    for(int i=0; i<n*n; i++)
    {
        inv[i/n][i%n] = adj[i%n][i/n];
        inv[i/n][i%n] /= Det;
    }
    return inv;
}

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
    double **m = allocate2(n,n), **inv = allocate2(n,n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        scanf("%lf", &m[i][j]);
    }
    printf("Mat:\n");
    disp(n, m);
    inv = inverse(n, m);
    printf("Inv:\n");
    disp(n, inv);
    printf("Multiplying:\n");
    mul(n, m, inv);
    printf("det : %lf", determinant(n, m));

}