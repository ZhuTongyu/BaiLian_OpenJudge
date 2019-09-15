/*
MergeSort
�鲢����
���Ӷȣ� n*log(n)
*/
#include<iostream>
using namespace std;
void MergeSort(int a[], int s, int e, int tmp[]);
void Merge(int a[], int s, int m, int e, int tmp[]);
int a[10] = { 13,27,19,2,8,12,2,8,30,89 };
int b[10];

int main()
{
	int size = sizeof(a) / sizeof(int);
	MergeSort(a, 0, size - 1, b);
	for (int k = 0; k < size; k++)
		cout << a[k] << " ";
	cout << "\n" << endl;
	return 0;
}
/*�鲢���� s �����鿪ʼ e �������β*/
// ������ a �ľֲ� a[s, m] �� a[m + 1, e] �ϲ��� tmp, ����֤ tmp ����Ȼ���ٿ����� a[s, m]
// �鲢����ʱ�临�Ӷȣ� O (e-m+1), �� O (n)

void MergeSort(int a[], int s, int e, int tmp[])
{
	if (s < e) /*��ֻ��һ��Ԫ��ʱ���ݹ���ֹ��ֱ�ӵ���merge�������Ƚ� 13��27��С���������*/
	{
		int m;// cut array into half
		m = s + (e - s) / 2;
		MergeSort(a, s, m, tmp);/* �ź�������� ��ʱ������� */
		MergeSort(a, m + 1, e, tmp);
		Merge(a, s, m, e, tmp);
	}

}
void Merge(int a[],int s, int m, int e, int tmp[])
{
	int i = 0;
	int p1 = s;
	int p2 = m + 1;
	while (p1 <= m && p2 <= e)
	{
		if (a[p1] < a[p2])
		{
			tmp[i++] = a[p1++];
		}
		else
		{
			tmp[i++] = a[p2++];
		}
	}
	while (p1 <= m)
		tmp[i++] = a[p1++];
	while (p2 <= e)
		tmp[i++] = a[p2++];
	for (int j = 0; j < e - s + 1; j++)
	{
		a[s + j] = tmp[j];
	}

}
/*
s    e    m
0    9    4
0    4    2
0    2    1
0    1    0
first:
MergeSort(a, 0, 9, tmp)
13,27,19,2,8
12,2,8,30,89 
MergeSort(a, 0, 4, tmp) 13,27,19,2,8
MergeSort(a, 5, 9, tmp) 12,2,8,30,89 
second:
MergeSort(a, 0, 4, tmp)
13,27,19
2,8
MergeSort(a, 0, 2, tmp) 13,27,19
MergeSort(a, 3, 4, tmp) 2,8
third:
MergeSort(a, 0, 2, tmp)
13,27
19
MergeSort(a, 0, 1, tmp)  13,27
MergeSort(a, 2, 2, tmp)  19
fourth:
MergeSort(a, 0, 1, tmp)  
MergeSort(a, 0, 0, tmp)   13
MergeSort(a, 1, 1, tmp)   27

Merge(a,0,0,1,tmp)
s m e
0 0 1
p1   p2
0    1
1
a[] = {13,27}
assume return to the first cut half , the two half array are sorted
MergeSort(a, 0, 4, tmp)    2,8,13,19,27
MergeSort(a, 5, 9, tmp)   2,8,12,30,89
Merge(a,0,4,9,tmp)
s m e
0 4 9
*/