/*
http://bailian.openjudge.cn/practice/1664/
1664�� ��ƻ��
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
	if (m == 0)  /*�߽���������������ֹ���ܵ�ס*/
		return 1;
	// (n <= 0)
	if (n == 0) /*�߽���������������ֹ���ܵ�ס  n<=0���Ǳ����*/
		return 0;
	return f(m, n - 1) + f(m - n, n);
	/*
	�ܷŷ� = ������Ϊ�յķŷ� + û����Ϊ�յķŷ�
	f(m, n - 1) �ȿ�һ������
	f(m - n, n)  �ȸ�n������ÿ����һ��ƻ����������û������Ϊ�գ�ʣ�µ�ƻ�����š�
	*/
}

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		cin >> m >> n; /*ÿ������ƻ���� �� ������*/
		cout << f(m, n) << endl;
	}
	return 0;
}