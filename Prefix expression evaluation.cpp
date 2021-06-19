/*
- * + 23 % 45 10 6 / 77 12
= ((23+(45%10))*6)-(77/12)

+ * 234 56
illegal
*/
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

bool evaluatePrefix(string input, stack<int> &Stack)
{
    vector<int> tmp;
    int flag = 0;
    for (int j = input.size() - 1; j >= 0; j--)
    {
        if (isdigit(input[j]))
        {
            tmp.push_back(input[j] - '0');
            flag = 1;
        }
        //遇到空格且已讀到數字
        else if (isspace(input[j]) && flag == 1)
        {
            int value = tmp[tmp.size() - 1];
            if (tmp.size() > 1)
            {
                for (int i = tmp.size() - 2; i >= 0; i--)
                    value = 10 * value + tmp[i];
            }
            //把讀到的數字放入stack
            Stack.push(value);
            tmp.clear();
            flag = 0;
        }
        //遇到空格略過
        else if (isspace(input[j]))
            continue;
        //遇到Operator時，如果stack中沒有兩個operand可以運算就代表是錯誤的輸入
        //如果有兩個operand，就按照+-*/%運算，將結果放入stack中
        else
        {
            if (Stack.size() <= 1)
                return false;
            else if (Stack.size() > 1)
            {
                int o1 = Stack.top();
                Stack.pop();
                int o2 = Stack.top();
                Stack.pop();

                switch (input[j])
                {
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
                case '%':
                    Stack.push(o1 % o2);
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{
    string input;
    stack<int> Stack;
    while (getline(cin, input) && input[0] != '.')
    {
        if (evaluatePrefix(input, Stack) == true)
            printf("%d\n", Stack.top());
        else
            printf("illegal\n");
        while (!Stack.empty())
            Stack.pop();
    }
    return 0;
}