/*
Recurse
N Queens problem
*/
#include<iostream>
#include<cmath>
using namespace std;

void NQueen(int k);
int N;
//���������õĻʺ�λ�á������Ͻ���(0,0)
int queenPos[100];

int main()
{
	cin >> N;
	NQueen(0); //�ӵ� 0 �п�ʼ�ڻʺ�

	return 0;
}
// �� 0~k 1 �лʺ��Ѿ��ںõ�����£��ڵ� k �м����Ļʺ�
void NQueen(int k)
{
	
	int i;
	if (k == N) // N ���ʺ��Ѿ��ں�
	{
		for (i = 0; i < N; i++)
		{
			cout << queenPos[i] + 1<<" ";
		}
		cout << endl;
		return;
		
	}
	// ���Ե� k ���ʺ��λ��
	// 0~N �б��� ����K�лʺ�Ӧ�÷��ڵڼ���
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < k; j++)
		{
			
			// ���Ѿ��ںõ� k ���ʺ��λ�ñȽϣ����Ƿ��ͻ
			// 1. ������ͬһ��
			// 2. �����ڶԽ����ϣ��� �м��  ��= �м�� 
			if (queenPos[j] == i || abs(k - j) == abs(i - queenPos[j]))
			{
				break; //��ͻ��������һ��λ��
			}
		}
		if (j == k) // ��ǰѡ��λ�� i ����ͻ
		{
			queenPos[k] = i; //���� k ���ʺ�ڷ���λ�� i
			NQueen(k + 1);
		}
	}
}