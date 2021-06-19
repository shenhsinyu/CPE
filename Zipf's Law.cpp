#include <string.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int Case = 0;
    int n;
    while (scanf("%d", &n) == 1)
    {
        string input;
        vector<string> word;
        while (getline(cin, input))
        {
            if (input == "EndOfText")
                break;
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (isalpha(input[i]))
                {
                    string s = "";
                    while (isalpha(input[i]))
                    {
                        //ignore Capitalization
                        if (input[i] >= 'A' && input[i] <= 'Z')
                            input[i] += 32;
                        s.insert(s.end(), input[i]);
                        i++;
                    }
                    // add word
                    word.push_back(s);
                    i--;
                }
            }
        }
        if (Case > 0)
            cout << endl;
        Case++;
        //in alphabetical order
        sort(word.begin(), word.end());
        int c = 1;
        bool flag = false;
        vector<int> index;
        for (int i = 0; i < word.size() - 1; i++)
        {
            if (word[i] == word[i + 1])
                c++;
            //count the number of duplicate word
            if ((word[i] != word[i + 1] || i + 1 == word.size() - 1) && c == n)
            {
                cout << word[i] << endl;
                flag = true;
                c = 1;
            }
            else if (word[i] != word[i + 1])
                c = 1;
        }

        if (flag == false)
            cout << "There is no such word." << endl;
    }
    return 0;
}