/*
http://bailian.openjudge.cn/practice/4143/
4143:和为给定数
*/
#include<iostream>
#include<algorithm>
using namespace std;

int a[100006];
int output[100006];
/*
方法1： 二分查找
*/
bool func(int a[],int sum,int size, int output[])
{
	int m,i;
	int left, right, mid;

	for (i = 0; i < size - 2; i++)
	{
		m = sum - a[i];
		left = i + 1;
		right = size - 1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (a[mid] == m)
			{
				output[0] = a[i];
				output[1] = m;
				return true;
			}
			else if (a[mid] > m)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}

		}
	}
	/*
	倒数2个数不用二分查找了，直接加一下就好了，节省计算量
	*/
	if ((a[size - 2] + a[size - 1]) == sum)
	{
		output[0] = a[size - 2];
		output[1] = a[size - 1];
		return true;
	}

	return false;

}
/*
查找的时候，设置两个变量 i 和 j，i 初值是0，j 初值是 n-1，
看 a[i]+a[j]，如果大于 m，就让 j 减1，如果小于 m，就让 i 加1，
直至 a[i]+a[j]=m
*/
bool func2(int a[], int sum, int size, int output[])
{
	int i=0, j=size-1;
	while (i < j)
	{
		if ((a[i] + a[j]) == sum)
		{
			output[0] = a[i];
			output[1] = a[j];
			return true;

		}
		else if ((a[i] + a[j]) > sum)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return false;
}

int main()
{
	int size, sum;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	cin >> sum;

	sort(a, a + size ); //将输入数据从小到大排序

	//bool res = func(a, sum, size, output);
	bool res = func2(a, sum, size, output);
	if (res == true)
		cout << output[0] << " "<<output[1] << endl;
	else
		cout << "No";
	return 0;
}