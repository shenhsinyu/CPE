#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
using namespace std;

long long int function(int B, int P, int M)
{
    long long int ans;
    if (P <= 1)
    {
        ans = pow(B, P);
        ans = ans % M;
    }

    else
    {
        long long int tmp = function(B, P / 2, M);
        if (P % 2 == 0)
            ans = (tmp * tmp) % M;
        else
            ans = (tmp * tmp * (B % M)) % M;
    }
    return ans;
}
int main()
{
    int B, P, M;
    while (scanf("%d %d %d", &B, &P, &M) != EOF)
    {
        long long int ans;
        ans = function(B, P, M);
        ans = ans % M;
        printf("%lld\n", ans);
    }
    return 0;
}