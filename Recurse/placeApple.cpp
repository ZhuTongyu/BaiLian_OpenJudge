/*
http://bailian.openjudge.cn/practice/1664/
1664： 放苹果
*/
#include<iostream>
using namespace std;
/*
m   Apple
n   Plate
*/
int f(int m, int n)
{
	if (m < n)
	{
		return f(m, m);
	}
	if (m == 0)  /*边界条件，必须能终止，能挡住*/
		return 1;
	// (n <= 0)
	if (n == 0) /*边界条件，必须能终止，能挡住  n<=0不是必须的*/
		return 0;
	return f(m, n - 1) + f(m - n, n);
	/*
	总放法 = 有盘子为空的放法 + 没盘子为空的放法
	f(m, n - 1) 先空一个盘子
	f(m - n, n)  先给n个盘子每个放一个苹果，这样就没有盘子为空，剩下的苹果随便放。
	*/
}

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		cin >> m >> n; /*每次输入苹果数 和 盘子数*/
		cout << f(m, n) << endl;
	}
	return 0;
}