#include <stdio.h>
#include <math.h>

const float PI = 3.1415926535;
const float EPS = 0.000001;

void print_str(char* str)
{
    if(*str)
    {
        print_str(str+1);
        putchar(*str);
    }
}

double teylor_cos(double Xn, int n, double x,double sum)
{
    if (fabs(Xn)>EPS)
    {
        n++;
        Xn*=(-1)*x*x/(2*n*(2*n-1));
        sum+=Xn;
        return teylor_cos(Xn, n, x, sum);
    }
    return sum;
}

double sinx(double x,double eps)
{
    double Xn = x;
    double sum = 0.0;
    int i = 1;
    double SqrX = x*x;
    do
    {
        sum += Xn;
        Xn *= -1.0 * SqrX / ((2 * i) * (2 * i + 1));
        i++;
    } while (fabs(Xn) > eps);
    return sum;
}

int main()
{
    double x;
    scanf("%lf",&x);
    x *= PI/180.0;
    printf("sinx =%lf\tlibSin =%f\n",sin(x),sinx(x,EPS));
    printf("%.3f\n",teylor_cos(1.0,0,x,1.0));
    print_str("Hello world\n");
    return 0;
}


