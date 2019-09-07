/*
http://bailian.openjudge.cn/practice/2787/
2787:算24
*/
#include<iostream>
#include<cmath>
using namespace std;

#define EPS 1e-6

double a[5];

bool IsZero(double x)
{
	//if (fabs(x) < EPS)
	//	return true;
	//else
	//	return false;
	return fabs(x) <= EPS;
}

bool count24(double a[],int n )
{//用数组 a 里的 n 个数，计算 24
	if (1 == n)
	{
		if (IsZero(a[0] - 24))
			return true;
		else
			return false;
	}
	double b[5];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// 枚举两个数的组合
			int m = 0;
			for (int k = 0; k < n; k++) // 还剩下 m 个数 , m = n 2
			{
				if (k != i && k != j)
					b[m++] = a[k]; // 把其余数放入 b
			}
			b[m] = a[i] + a[j];
			/* pay attention at here */
			if (count24(b, m + 1))
				return true;
			b[m] = a[i] - a[j];
			if (count24(b, m + 1))
				return true;
			b[m] = a[j] - a[i];
			if (count24(b, m + 1))
				return true;
			b[m] = a[i] * a[j];
			if (count24(b, m + 1))
				return true;
			// a[i] != 0 can divide
			if (!IsZero(a[i]))
				b[m] = a[j] / a[i];
				if (count24(b, m + 1))
					return true;
			if (!IsZero(a[j]))
				b[m] = a[i] / a[j];
				if (count24(b, m + 1))
					return true;
				
		}
	}
	// can not omit
	// !!! pay attention
	// 如果枚举了数组a[]中的所有可能，都算不出24，不能return true,
	// 说明 当前这一组数，是算不出24的，return false,尝试其他的可能组合
	return false;
}
int main()
{
	//如何不停的读入输入的4个数
	int i = 0;
	while (true)
	{
		double sum = 0;

		for (i = 0; i < 4; i++)
		{
			cin >> a[i];
			sum += a[i]; // 0 0 0 0 终止，输入都是正整数
		}
		if (IsZero(sum))
			break;
		bool result = count24(a, 4);
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;

}