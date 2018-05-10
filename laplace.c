#include <stdio.h>
double determinant(int m, double a[][m])
{
	int i=0, j=0;
	if(m == 2)
	{
		return a[0][0]*a[1][1] - a[0][1]*a[1][0];
	}
  if(m == 1)
  {
    return a[0][0];
  }
	double det = 0;
	for(j=0; j<m; j++)
	{
	        double b[m-1][m-1]; int jj=0, ii=0, f=0;
	        for(jj=0; jj < m; jj++)
	        {
	        	if(jj == j){f++;continue;}
	        	for(ii=0; ii < m-1; ii++)
	        		b[ii][jj-f] = a[ii+1][jj];
	        }
	        int sgn = j%2 == 1? -1:1;
	        det += sgn * a[0][j] * determinant(m-1, b);
	        //for(ii=0; ii<m-1; ii++)
	        //{
	        //	for(jj=0; jj<m-1; jj++)
	        //	printf("%d ", b[ii][jj]);
	        //	printf("\n");
	        //}
	        //printf("\n\n\n");
	}
	return det;	                
}
int main()
{
  int i,j,m;
  
  printf("\n\nEnter order of matrix : ");
  scanf("%d",&m);
  double a[m][m];
  printf("\nEnter the elements of matrix\n");
  for(i=0;i<m;i++)
  {
   for(j=0;j<m;j++)
   {
    //  printf("a[%d][%d] = ",i,j);
     scanf("%ld",&a[i][j]);
   }
  }
  //m=4;
  //int a[4][4] = {{1,2,3,4}, {1,2,3,4},  {4,5,6,1}, {7,8,9,1}};
  printf("\n\n---------- Matrix A is --------------\n");    
  for(i=0;i<m;i++)
     {
          printf("\n");
          for(j=0;j<m;j++)
          {     
               printf("\t%d \t",a[i][j]);
          }
     }
  printf("\n \n");
  printf("\n Determinant of Matrix A is %lf .",determinant(m,a));
  //getch();
}
