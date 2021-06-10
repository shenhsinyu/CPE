#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int main()
{
    char input[10000];
    int num;
    while (scanf("%s %d", input, &num) != EOF)
    {
        vector<long long int> digit;
        vector<long long int> op;
        long long int tmp = 0;
        int neg = 1;
        for (int i = 0; input[i] != ']'; i++)
        {
            if (input[i] == '+')
                op.push_back(0);
            if (input[i] == '*')
                op.push_back(1);
            if (input[i] == '-')
                neg = -1;
            if (isdigit(input[i]))
            {
                tmp = tmp + (input[i] - '0');
                if (isdigit(input[i + 1]))
                    tmp *= 10;
                if (!isdigit(input[i + 1]))
                {
                    digit.push_back(neg * tmp);
                    tmp = 0;
                    neg = 1;
                }
            }
        }

        long long int v[num];
        long long int s[num];
        for (int i = 0; i < num; i++)
            s[i] = digit[digit.size() - 1];

        for (int j = op.size() - 1; j >= 0; j--)
        {
            if (op[j] == 0)
            {
                v[0] = digit[j];
                for (int k = 1; k < num; k++)
                {
                    v[k] = v[k - 1] + s[k - 1];
                }
            }
            if (op[j] == 1)
            {
                v[0] = digit[j] * s[0];
                for (int k = 1; k < num; k++)
                    v[k] = v[k - 1] * s[k];
            }
            for (int i = 0; i < num; i++)
                s[i] = v[i];
        }
        for (int i = 0; i < num - 1; i++)
            cout << s[i] << " ";
        cout << s[num - 1] << endl;
        memset(input, 0, sizeof(input));
    }
}