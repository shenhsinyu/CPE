#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int start[10000];
    start[0] = 1;
    for (int i = 1; start[i] < 100000; i++)
    {
        start[i] = start[i - 1] + i * 6; // 1 7 19 37 ...
    }
    while (scanf("%d", &n) != EOF)
    {
        int s, r;
        for (int i = 1; i < 6877; i++)
        {
            if (n > start[i - 1] && start[i] >= n)
            {
                s = start[i - 1];
                r = i;
                break;
            }
        }

        // 1st: 1 2nd: 2-7 3rd: 8-19 .... 把它分成6條線
        if (n == 1)
            printf("0 0\n");
        else
        {
            int x = 0, y = 0;
            if ((n - s) / r == 1)
            {
                y = y + r;            //每條線的公式
                if ((n - s) % r != 0) //介在區域一到區域二之間
                    x = x - (n - s) % r;
            }

            if ((n - s) / r == 2)
            {
                x -= r;
                y += r;
                if ((n - s) % r != 0)
                    y = y - (n - s) % r;
            }
            if ((n - s) / r == 3)
            {
                x -= r;
                if ((n - s) % r != 0)
                {
                    y = y - (n - s) % r;
                    x = x + (n - s) % r;
                }
            }
            if ((n - s) / r == 4)
            {
                y -= r;
                if ((n - s) % r != 0)
                    x = x + (n - s) % r;
            }
            if ((n - s) / r == 5)
            {
                x += r;
                y -= r;
                if ((n - s) % r != 0)
                    y = y + (n - s) % r;
            }
            if ((n - s) / r == 6)
            {
                x += r;
            }
            if ((n - s) / r == 0)
            {
                y += r;
                if ((n - s) % r != 0)
                {
                    x = x + (r - (n - s) % r);
                    y = y - (r - (n - s) % r);
                }
            }
            printf("%d %d\n", x, y);
        }
    }
}