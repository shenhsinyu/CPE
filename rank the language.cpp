#include <iostream>
#include <stdio.h>
using namespace std;

char map[1000][1000];
int visit[1000][1000];

void DFS(int x, int y)
{
    visit[x][y] = 1;
    if (map[x + 1][y] == map[x][y] && visit[x + 1][y] == 0)
        DFS(x + 1, y);
    if (map[x - 1][y] == map[x][y] && visit[x - 1][y] == 0)
        DFS(x - 1, y);
    if (map[x][y + 1] == map[x][y] && visit[x][y + 1] == 0)
        DFS(x, y + 1);
    if (map[x][y - 1] == map[x][y] && visit[x][y - 1] == 0)
        DFS(x, y - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    int letter[26];

    for (int num = 1; num <= n; num++)
    {
        int m, n;
        int maxarea = 0;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", &map[i]);
        for (int i = 0; i < 26; i++)
            letter[i] = 0;
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
                visit[i][j] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit[i][j] == 0)
                {
                    letter[map[i][j] - 'a'] += 1;
                    maxarea = max(letter[map[i][j] - 'a'], maxarea);
                    DFS(i, j);
                }
            }
        }
        printf("World #%d\n", num);
        for (int v = maxarea; v > 0; v--)
        {
            for (int i = 0; i < 26; i++)
            {
                if (letter[i] == v)
                    printf("%c: %d\n", i + 'a', v);
            }
        }
    }
}