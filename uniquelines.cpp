#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int case_number;
	scanf("%d", &case_number);
	while (case_number--)
	{
		int n;
		scanf("%d", &n);
		vector<int> x;
		vector<int> y;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			x.push_back(a);
			y.push_back(b);
		}
		vector<float> slope;
		vector<float> y_intercept;
		vector<int> x_intercept;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				float s;
				if (x[j] - x[i] == 0)
					x_intercept.push_back(x[j]);
				else
				{
					float line;
					s = (float)(y[j] - y[i]) / (x[j] - x[i]);
					if (s == 0)
						line = y[j];
					else
						line = y[j] - s * x[j];
					slope.push_back(s);
					y_intercept.push_back(line);
				}
			}
		}

		sort(x_intercept.begin(), x_intercept.end());
		int length = unique(x_intercept.begin(), x_intercept.end()) - x_intercept.begin();

		if (y_intercept.size() == 0)
			cout << length << endl;
		else
		{
			vector<float> result, result1;
			result.push_back(slope[0]);
			result1.push_back(y_intercept[0]);

			for (int i = 1; i < slope.size(); i++)
			{
				int flag = 0;
				for (int j = 0; j < result.size(); j++)
				{
					if (slope[i] != result[j] || (slope[i] == result[j] && y_intercept[i] != result1[j]))
					{
						flag = flag + 0;
					}
					else
						flag++;
				}
				if (flag == 0)
				{
					result.push_back(slope[i]);
					result1.push_back(y_intercept[i]);
				}
			}
			cout << length + result.size() << endl;
		}
	}
	return 0;
}
