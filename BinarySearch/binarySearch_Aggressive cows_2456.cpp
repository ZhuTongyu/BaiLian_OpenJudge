/*
http://bailian.openjudge.cn/practice/2456/
2456:Aggressive cows
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100006];
int N, C;
bool func(int x)
{
	int temp = a[0];
	int cnt = 1;
	for (int i = 1; i < N; i++)
	{
		//统计在设定间距下（比如4），牛舍的位置是否放的下C头牛
		if (a[i] - temp >= x)
		{
			cnt++;
			temp = a[i];
		}
		if (cnt == C)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int i;
	cin >> N; // room number for cows
	cin >> C; // cows number
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + N);

	int  left, right, mid;
	left = 0;
	right = a[N - 1]-a[0];
	//mid = left + (right - left) / 2;
	while (left <= right)
	{// 5个牛舍的位置【1， 2， 4， 8， 9】，最大间距是 8，所有可能间距取值是【0~8】，二分查找问题
		mid = left + (right - left) / 2;//第一把间距是4，失败，需要缩小间距
		if ((func(mid)))  // 如果现在的间距满足放下C头牛，那要试一试间距变大的情况
		{ // 间距如何变大？
			left = mid + 1; /* left = 5 ,[0~4]delete,  [5~8]select*/
		}
		else
		{// 间距缩小
			right = mid - 1; /*right = 3, [3~8]delete,  [0~3]select */
		}
	}
	// 当间距=3时，满足成立条件，return true, 此时，left=3+1=4, while(4<=3)退出，实际间距4-1=3
	printf("%d\n",left-1);

	return 0;
}