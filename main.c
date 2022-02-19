#include <stdio.h>
#include <math.h>

/* Function declarations*/

double func(double x);
int fib(int n);
void method(double a, double b, double eps);

int main()
{

}

/* Function definitions*/

//Function to solve
double func(double x)
{
    return pow(x,3)/3 - pow(x,2)/2 -x-1;
}

//Fibonacci number generator
int fib(int n)
{
    if ( n <= 1 )
        return 1;
    else
        return ( fib(n-1) + fib(n-2) );
}

//Function that implements fibonacci line search
void method(double a, double b, double eps)
{
    int n=0;
    double c,d,fc,fd;

    /* Calculating the number of iterations needed.
       This is found by solving for the smallest value of n that makes the condition below true */
    for(int i=2; i<2222; i++)
    {
        n=i;
        if ( fib(i) > (b-a)/eps )
        {
            break;
        }
    }

    printf("\n(i)     ( c )      ( d )     ( fc )     ( fd )    (Length)       Interval\n");

    c = a+((double)fib(n-2)/(double)fib(n))*(b-a);
    d = a+((double)fib(n-1)/(double)fib(n))*(b-a);

    fc = func(c);
    fd = func(d);
    printf(" 0 %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf    [%.4lf , %.4lf]\n",c,d,fc,fd,b-a,a,b);

    for (int i=1 ; i<n ; i++)
    {
        if(fc<fd)
        {
            b = d;
            d = c;
            fd = fc;
            c = a+((double)fib(n-2)/(double)fib(n))*(b-a);
            fc = func(c);
        }
        else
        {
            a = c;
            c = d;
            fc = fd;
            d = a+((double)fib(n-1)/(double)fib(n))*(b-a);
            fd = func(d);
        }
        printf("%2d %10.4lf %10.4lf %10.4lf %10.4lf %10.4lf    [%.4lf , %.4lf]\n",i,c,d,fc,fd,b-a,a,b);
    }
    printf("\n------------------------------------------\n");
    printf("Midpoint of the final interval: %.4lf\n",(a+b)/2);
    printf("Length of the interval: %.4lf\n",b-a);
    printf("Number of iterations: %d",n);
    printf("\n------------------------------------------\n");
}
