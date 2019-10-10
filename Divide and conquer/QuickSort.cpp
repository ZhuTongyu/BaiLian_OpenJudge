/*
�������򣬷���˼�룬��һ�������ֳ�����������
*/
#include<iostream>
using namespace std;

int a[] = { 93,27,30,2,8,12,2,8,30,89 };
void QuickSort(int a[], int s, int e);
void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int size = sizeof(a) / sizeof(int);
	QuickSort(a, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << a[i] << ",";
	cout << endl;
	return 0;
}
void QuickSort(int a[], int s, int e)
{
	
	if (s >= e)/*�߽�������*/
		return;
	int k = a[s];
	int i = s, j = e;
	while (i < j)
	{
		while (i<j && a[j] >= k)
		{
			j--;
		}
		swap(a[i], a[j]); /* �����������Ԫ�أ�i=j,swap(a[i], a[j])�൱��ʲô��û�� */

		while (i < j && a[i] <= k)
		{
			i++;
		}
		swap(a[i], a[j]);
	} // ������� a[i] = k
	QuickSort(a, s, i - 1);
	QuickSort(a, i + 1, e);
}
//int a[] = { 93,27,30,2,8,12,2,8,30,89 }; 