#include <stdio.h>
void disp(int n, double a[][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
}
void uppper_triangular(int n, double a[][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j)
            {
                double p = a[i][j] / a[j][j];
                // printf("Pivot: (%lf / %lf) = %lf\n", a[i][j], a[j][j], p);
                for(int k=0; k<n; k++)
                {
                    a[i][k] -= p*a[j][k];
                }
            }
        }
        printf("\n");
        disp(n,a);
    }
}
void inverse(int n, double a[][n], double b[n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>j && a[j][j] != 0)
            {
                double p = a[i][j] / a[j][j];
                // printf("Pivot: (%lf / %lf) = %lf\n", a[i][j], a[j][j], p);
                b[i] -= p*b[j];
                for(int k=0; k<n; k++)
                    a[i][k] -= p*a[j][k];
            }
        }
    }
    disp(n, a);
    printf("\n\n");
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i<j && a[j][j] != 0)
            {
                double p = a[i][j] / a[j][j];
                // printf("Pivot: (%lf / %lf) = %lf\n", a[i][j], a[j][j], p);
                b[i] -= p*b[j];
                // for(int k=0; k<n; k++)
                //     a[i][k] -= p*a[j][k];
                a[i][j] = 0;
            }
        }
    }
    disp(n, a);
}
double determinant(int m, double a[][m])
{
	int i=0, j=0;
	if(m == 2)
		return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    if(m == 1)
        return a[0][0];
	int det = 0;
	for(j=0; j<m; j++)
	{
	        int b[m-1][m-1], jj=0, ii=0, f=0;
	        for(jj=0; jj < m; jj++)
	        {
	        	if(jj == j){f++;continue;}
	        	for(ii=0; ii < m-1; ii++)
	        		b[ii][jj-f] = a[ii+1][jj];
	        }
	        int sgn = j%2 == 1? -1:1;
	        det += sgn * a[0][j] * determinant(m-1, b);
	}
	return det;               
}

int main()
{
  int i,j,m;
  
//   printf("\n\nEnter order of matrix : ");
  scanf("%d",&m);
  double a[m][m], b[m];
//   printf("\nEnter the elements of matrix\n");
  for(i=0;i<m;i++)
  {
   for(j=0;j<m;j++)
   {
    //  printf("a[%d][%d] = ",i,j);
     scanf("%lf",&a[i][j]);
   }
  }
//   printf("\nEnter the elements of const\n");
    
    for(j=0;j<m;j++)
    {
    //  printf("a[%d][%d] = ",i,j);
        scanf("%lf",&b[j]);
    }
  
  //m=4;
  //int a[4][4] = {{1,2,3,4}, {1,2,3,4},  {4,5,6,1}, {7,8,9,1}};
  printf("\n\n---------- Matrix A is --------------\n");    
  for(i=0;i<m;i++)
     {
          printf("\n");
          for(j=0;j<m;j++)
          {     
               printf("\t%lf \t",a[i][j]);
          }
     }
  printf("\n \n");
//   printf("\n Determinant of Matrix A is %d .",determinant(m,a));
    // uppper_triangular(m, a);
    // inverse(m, a, b);
  //getch();
}