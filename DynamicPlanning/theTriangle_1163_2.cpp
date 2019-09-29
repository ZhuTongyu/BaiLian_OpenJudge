/*
http://bailian.openjudge.cn/practice/1163/
1163:The Triangle
�ݹ�ⷨ2�����������εļ���ݹ��Ͷ������
*/
#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int sum[MAX][MAX];
int n;
int MaxSum(int i, int j)
{
	if (sum[i][j] != -1)/*˵�����·���������Ѿ������*/
	{
		return sum[i][j];
	}
	if (i == n)
	{
		sum[i][j] = D[i][j];
	}
	else
	{
		int x = MaxSum(i + 1, j);
		int y = MaxSum(i + 1, j + 1);
		sum[i][j] = max(x, y) + D[i][j];
	}
	return sum[i][j];
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cin >> D[i][j];
			sum[i][j] = -1;
		}
	}
	cout << MaxSum(0, 0) << endl;
	return 0;

}