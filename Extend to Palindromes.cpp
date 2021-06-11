#include <stdio.h>
#include <string.h>

/*
old: amanaplanacanal 
rev: lanacanalpanama
找出old 中 i-n 與 rev 中 0-(n-i) 一樣的部分
-> lanacanal這段一樣 然後將old後面補上rev剩餘的部分
-> amanaplanacanal + panama
-> amanaplanacanalpanama
*/
int main()
{
    char input[100000];
    while (scanf("%s", input) != EOF)
    {
        int n = strlen(input);
        char reverse[100000];
        for (int i = 0; i < n; i++)
            reverse[i] = input[n - 1 - i];

        int s = 0;
        for (int i = 0; i < n; i++)
        {
            int k = i;
            int c = 0;
            for (int j = 0; j < n - i; j++)
            {
                if (reverse[j] == input[k++])
                    c++;
                else
                    break;
            }
            if (c == n - i)
            {
                s = i;
                break;
            }
        }

        printf("%s", input);
        if (s == n - 1)
        {
            for (int i = 1; i < n; i++)
                printf("%c", reverse[i]);
        }
        else if (s != n - 1 && s != 0)
        {
            for (int i = n - s; i < n; i++)
                printf("%c", reverse[i]);
        }
        printf("\n");
    }
}