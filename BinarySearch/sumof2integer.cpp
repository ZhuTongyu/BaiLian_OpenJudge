/*
http://bailian.openjudge.cn/practice/4143/
4143:��Ϊ������
*/
#include<iostream>
#include<algorithm>
using namespace std;

int a[100006];
int output[100006];
/*
����1�� ���ֲ���
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
	����2�������ö��ֲ����ˣ�ֱ�Ӽ�һ�¾ͺ��ˣ���ʡ������
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
���ҵ�ʱ�������������� i �� j��i ��ֵ��0��j ��ֵ�� n-1��
�� a[i]+a[j]��������� m������ j ��1�����С�� m������ i ��1��
ֱ�� a[i]+a[j]=m
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

	sort(a, a + size ); //���������ݴ�С��������

	//bool res = func(a, sum, size, output);
	bool res = func2(a, sum, size, output);
	if (res == true)
		cout << output[0] << " "<<output[1] << endl;
	else
		cout << "No";
	return 0;
}