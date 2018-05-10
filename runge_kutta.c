#include<stdio.h>
 
// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
    return((x - y)/2);
}
 
// Finds value of y for a given x using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0, float x, float h)
{
    int n = (x-x0)/h;
    double k1,k2,k3,k4;
    float y = y0;
    for(int i=0;i <n; i++)
    {
        k1 = h*dydx(x0, y);
        k2 = h*dydx(x0+h/2, y+k1/2);
        k3 = h*dydx(x0+h/2, y+k2/2);
        k4 = h*dydx(x0+h, y+k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 += h;
        printf("%lf %lf %lf %lf\n", k1, k2, k3, k4);
    }
    return y;
}
 
// Driver method
int main()
{
    float x0 = 0, y = 1, x = 2, h = 0.2;
    printf("\nThe value of y at x is : %f", rungeKutta(x0, y, x, h));
    return 0;
}
