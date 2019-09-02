/*
http://bailian.openjudge.cn/practice/4017/
4017:爬楼梯
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30
*/
#include<iostream>

using namespace std;

int N;

int Stairs(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	return Stairs(n - 1) + Stairs(n - 2);
}

int main()
{
	while (cin >> N)
	{
		cout << Stairs(N) << endl;
	}
	return 0;
}