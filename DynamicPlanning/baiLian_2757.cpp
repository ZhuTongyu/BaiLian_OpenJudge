/*
Dynamic Planning
http://bailian.openjudge.cn/practice/2757
2757:�����������
˼·����������
1. �������е�ǰn ��Ԫ�ص�����������еĳ��� �Ǹ������⣬�������ֽ������⣬�����С��޺�Ч�ԡ�
2. ������ak�� k=1, 2, 3��N ��Ϊ�յ������������еĳ��ȡ�
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
int a[MAXN];
int maxLen[MAXN];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		maxLen[i] = 1;
		for (int i = 2; i <= N; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (a[i] > a[j])
				{/*Ҫ�����������������У�j=1,2,3..., �п���j=2  > j=3, ����Ҫ��¼j=2ʱ�����ֵ
				 ����ֹj=3ʱ��ˢ����һ��ʵ�ʵ����Ž� */
					maxLen[i] = max(maxLen[i], maxLen[j] + 1);
				}
			}
		}
	}
	/* STL ����*/
	cout << *max_element(maxLen + 1, maxLen + N + 1);
	return 0;
}