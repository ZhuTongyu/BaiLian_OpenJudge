/*
http://bailian.openjudge.cn/practice/4017/
4017:��¥��
������������У�ÿ�а���һ��������N������¥�ݼ�����1 <= N <= 30
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