#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> prime;

//建質數表
void cal_prime()
{
    int *table = new int[100000];
    for (int i = 0; i < 100000; i++)
        table[i] = 1;
    for (int i = 2; i < 100000; i++)
    {
        if (table[i] == 1)
        {
            prime.push_back(i);
            for (int j = i; j < 100000; j = j + i)
                table[j] = 0;
        }
    }
    delete[] table;
}

//計算一個數每個位數的總和
int cal_sum(int num)
{
    int sum = 0;
    while (num >= 10)
    {
        sum += num % 10;
        num /= 10;
    }
    if (num < 10)
        sum += num;
    return sum;
}

//把n做因式分解，且計算因式的總和
int factorize(int n)
{
    int tmp = n;
    int sum_f = 0;
    int flag = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        //排除本身就是質數的可能
        if (tmp == prime[i])
            continue;

        while (n % prime[i] == 0)
        {
            flag = 1;
            sum_f += cal_sum(prime[i]);
            n = n / prime[i];
        }
        if (n == 1)
            break;
    }
    //如果因數分解分到最後還有剩，代表有一個因數是大於pow(10,5),要特別加上去
    if (n > 1 && flag == 1)
        sum_f += cal_sum(n);

    return sum_f;
}

int main()
{
    cal_prime();
    int t;
    while (scanf("%d", &t) != EOF)
    {
        while (t--)
        {
            int n;
            scanf("%d", &n);
            for (int i = n + 1; i <= pow(10, 10); i++)
            {
                int sum_n = cal_sum(i);
                int sum_f = factorize(i);
                if (sum_n == sum_f)
                {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}