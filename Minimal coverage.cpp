#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, M;
int function(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}
bool find(vector<vector<int>> &line, int start, vector<vector<int>> &ans)
{
    int next;
    int right = 0;
    int flag = 0;
    for (int i = start + 1; i < line.size(); i++)
    {
        /*the line's left point must smaller than the last line's right point
          and if the line's right point larger than the target segment 
          it means that we find the answer*/
        if (line[i][0] <= line[start][1] && line[i][1] >= M)
        {
            ans.push_back(line[i]);
            return true;
        }
        /*find the longest line that cover some part of target segment*/
        if (line[i][0] <= line[start][1] && line[i][1] < M)
        {
            if (line[i][1] > right)
            {
                next = i;
                right = line[i][1];
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {
        ans.push_back(line[next]);
        return find(line, next, ans);
    }
    return false;
}
int main()
{
    cin >> n;
    int Case = 0;
    while (n--)
    {
        if (Case > 0)
            cout << endl;
        Case++;
        cin >> M;
        int L, R;
        vector<vector<int>> line;
        vector<int> tmp;
        while (cin >> L >> R)
        {
            if (L == 0 && R == 0)
                break;
            tmp.push_back(L);
            tmp.push_back(R);
            line.push_back(tmp);
            tmp.clear();
        }
        sort(line.begin(), line.end(), function);

        int right = 0;
        int start;
        int flag = 0;
        /*find the first line */
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i][0] <= 0 && line[i][1] >= 0)
            {
                if (line[i][1] > right)
                {
                    start = i;
                    right = line[i][1];
                    flag = 1;
                }
            }
        }
        /*if find the first line, then continue find the second*/
        if (flag == 1)
        {
            /*the first line cover the target segment*/
            if (line[start][1] >= M)
            {
                cout << 1 << endl;
                cout << line[start][0] << " " << line[start][1] << endl;
            }
            else
            {
                vector<vector<int>> ans;
                ans.push_back(line[start]);
                /*continue finding*/
                bool a = find(line, start, ans);

                if (a == false)
                    cout << 0 << endl;
                if (a == true)
                {
                    cout << ans.size() << endl;
                    for (int i = 0; i < ans.size(); i++)
                        cout << ans[i][0] << " " << ans[i][1] << endl;
                }
            }
        }
        /*if can't find the fisrt line, it failed*/
        else
            cout << 0 << endl;
    }
    return 0;
}