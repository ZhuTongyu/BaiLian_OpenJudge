/*
http://bailian.openjudge.cn/practice/1163/
1163:The Triangle
递归解法1：有大量重复计算
*/
#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int MaxSum(int i, int j)
{
	if (i == n)
		return D[i][j];
	int x = MaxSum(i + 1, j);
	int y = MaxSum(i + 1, j + 1);/*只要i不是最后一行，肯定存在j+1*/
	return max(x, y) + D[i][j];
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			cin >> D[i][j];
	cout << MaxSum(0, 0) << endl;
	return 0;

}