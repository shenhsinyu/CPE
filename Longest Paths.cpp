#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int find(int map[105][105], int s, int n, int finish[105])
{
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (map[s][i] == 1)
        {
            int tmp = m;
            m = max(m, find(map, i, n, finish) + 1);
            if (m > tmp)
                //記錄往哪個點走
                finish[s] = i;
        }
    }
    return m;
}

//traverse整個array找到最終點
int end(int finish[105], int s)
{
    int ee = s;
    while (finish[ee] > 0)
        ee = finish[ee];
    return ee;
}
int main()
{
    int n;
    int s;
    int Case = 1;
    int map[105][105];
    int p, q;
    while (scanf("%d", &n) && n != 0)
    {
        scanf("%d", &s);
        memset(map, 0, sizeof(map));
        while (scanf("%d %d", &p, &q) && p + q != 0)
            map[p][q] = 1;

        int finish[105];
        memset(finish, 0, sizeof(finish));
        int length = find(map, s, n, finish);
        int e = end(finish, s);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
               Case++, s, length, e);
    }
}