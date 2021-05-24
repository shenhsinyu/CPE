#include <stdio.h>
#include <string.h>
int sum_of_number(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a = a / 10;
    }
    return sum;
}
int main()
{
    int *prime = new int[1000000];
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < 1000000; i++)
        prime[i] = 1;
    for (int i = 2; i < 1000000; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i + i; j < 1000000; j += i)
                prime[j] = 0;
        }
    }
    int n;
    int t1, t2;
    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            int ans = 0;
            scanf("%d %d", &t1, &t2);
            for (int i = t1; i <= t2; i++)
            {
                if (prime[i] == 1 && prime[sum_of_number(i)] == 1)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    delete[] prime;
}