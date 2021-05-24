#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int sum(int x, int n)
{
    int a, b;
    int t = pow(10, n / 2);
    a = x % t;
    b = x / pow(10, n / 2);
    int ans = (a + b) * (a + b);
    return ans;
}
int main()
{
    int n;
    vector<int> square;
    for (int i = 0; i <= 10000; i++)
        square.push_back(i * i);

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; square[i] < pow(10, n); i++)
        {
            if (square[i] == sum(square[i], n))
            {
                if (n == 2)
                    printf("%02d\n", square[i]);
                if (n == 4)
                    printf("%04d\n", square[i]);
                if (n == 6)
                    printf("%06d\n", square[i]);
                if (n == 8)
                {
                    int t = pow(10, 7);
                    if (square[i] % t != 0 || square[i] == 0)
                        printf("%08d\n", square[i]);
                    else
                        printf("%d\n", square[i]);
                }
            }
        }
    }
    return 0;
}