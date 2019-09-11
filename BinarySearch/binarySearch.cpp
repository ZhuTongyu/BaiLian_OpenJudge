/*
http://bailian.openjudge.cn/practice/4142/
4142:二分法求函数的零点
*/
#include<cstdio>
#include<cmath>
using namespace std;

#define EPS 1e-6
double f(double x)
{
	return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * pow(x, 2) + 274 * x - 121;
}
int main()
{
	double root, left = 1.5, right = 2.4, y;
	int times = 1;
	root = left + (right - left) / 2;
	y = f(root);
	while (fabs(y) > EPS)
	{
		if (y > 0)
		{
			left = root;
		}
		else
		{
			right = root;
		}
		root = left + (right - left) / 2;
		y = f(root);
		times++;
	}
	printf("%.6f\n", root);
	//printf("%d\n", times);
}