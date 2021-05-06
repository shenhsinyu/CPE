#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
/*
(A*b)%C = (A%C)*(B%C)
A%C=X -> (A-B)%C = (X-B)%C
(5-3)%3 = 2 = (2-3)%3
(A*A-B)%C = ((A%C)*(A%C)-B)%C
*/
long long int function(long long int n)
{
    long long int ans;
    long long int mod = pow(10, 9) + 9;

    if (n <= 17)
        ans = pow(3, n);
    else
    {
        long long int tmp = function(n / 2);
        if (n % 2 == 1)
            ans = (tmp * tmp * 3) % mod;
        else
            ans = (tmp * tmp) % mod;
    }

    return ans;
}
int main()
{
    long long int n;
    while (scanf("%lld", &n) != EOF)
    {
        long long int a;
        long long int mod = pow(10, 9) + 9;
        if (n <= 17)
        {
            a = pow(3, n) - 2;
            printf("%lld\n", a);
        }
        else
        {
            a = (function(n) - 2) % mod;
            printf("%lld\n", a);
        }
    }
    return 0;
}