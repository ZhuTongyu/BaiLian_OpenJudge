/*
快速排序，分治思想，把一个问题拆分成若干子问题
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
	
	if (s >= e)/*边界条件？*/
		return;
	int k = a[s];
	int i = s, j = e;
	while (i < j)
	{
		while (i<j && a[j] >= k)
		{
			j--;
		}
		swap(a[i], a[j]); /* 如果到了最后的元素，i=j,swap(a[i], a[j])相当于什么都没做 */

		while (i < j && a[i] <= k)
		{
			i++;
		}
		swap(a[i], a[j]);
	} // 处理完后， a[i] = k
	QuickSort(a, s, i - 1);
	QuickSort(a, i + 1, e);
}
//int a[] = { 93,27,30,2,8,12,2,8,30,89 }; 