/*
http://bailian.openjudge.cn/practice/2787/
2787:��24
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
{//������ a ��� n ���������� 24
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
			// ö�������������
			int m = 0;
			for (int k = 0; k < n; k++) // ��ʣ�� m ���� , m = n 2
			{
				if (k != i && k != j)
					b[m++] = a[k]; // ������������ b
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
	// ���ö��������a[]�е����п��ܣ����㲻��24������return true,
	// ˵�� ��ǰ��һ���������㲻��24�ģ�return false,���������Ŀ������
	return false;
}
int main()
{
	//��β�ͣ�Ķ��������4����
	int i = 0;
	while (true)
	{
		double sum = 0;

		for (i = 0; i < 4; i++)
		{
			cin >> a[i];
			sum += a[i]; // 0 0 0 0 ��ֹ�����붼��������
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