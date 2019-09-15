/*
http://bailian.openjudge.cn/practice/2456/
2456:Aggressive cows
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100006];
int N, C;
bool func(int x)
{
	int temp = a[0];
	int cnt = 1;
	for (int i = 1; i < N; i++)
	{
		//ͳ�����趨����£�����4����ţ���λ���Ƿ�ŵ���Cͷţ
		if (a[i] - temp >= x)
		{
			cnt++;
			temp = a[i];
		}
		if (cnt == C)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int i;
	cin >> N; // room number for cows
	cin >> C; // cows number
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + N);

	int  left, right, mid;
	left = 0;
	right = a[N - 1]-a[0];
	//mid = left + (right - left) / 2;
	while (left <= right)
	{// 5��ţ���λ�á�1�� 2�� 4�� 8�� 9����������� 8�����п��ܼ��ȡֵ�ǡ�0~8�������ֲ�������
		mid = left + (right - left) / 2;//��һ�Ѽ����4��ʧ�ܣ���Ҫ��С���
		if ((func(mid)))  // ������ڵļ���������Cͷţ����Ҫ��һ�Լ��������
		{ // �����α��
			left = mid + 1; /* left = 5 ,[0~4]delete,  [5~8]select*/
		}
		else
		{// �����С
			right = mid - 1; /*right = 3, [3~8]delete,  [0~3]select */
		}
	}
	// �����=3ʱ���������������return true, ��ʱ��left=3+1=4, while(4<=3)�˳���ʵ�ʼ��4-1=3
	printf("%d\n",left-1);

	return 0;
}