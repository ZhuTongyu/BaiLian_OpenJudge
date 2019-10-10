/*
Dynamic Planning
http://bailian.openjudge.cn/practice/2757
2757:最长上升子序列
思路：找子问题
1. “求序列的前n 个元素的最长上升子序列的长度 是个子问题，但这样分解子问题，不具有“无后效性”
2. “求以ak（ k=1, 2, 3…N ）为终点的最长上升子序列的长度”
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
int a[MAXN];
int maxLen[MAXN];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		maxLen[i] = 1;
		for (int i = 2; i <= N; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (a[i] > a[j])
				{/*要遍历子问题的最长子序列，j=1,2,3..., 有可能j=2  > j=3, 所以要记录j=2时的最大值
				 ，防止j=3时，刷掉上一个实际的最优解 */
					maxLen[i] = max(maxLen[i], maxLen[j] + 1);
				}
			}
		}
	}
	/* STL 函数*/
	cout << *max_element(maxLen + 1, maxLen + N + 1);
	return 0;
}