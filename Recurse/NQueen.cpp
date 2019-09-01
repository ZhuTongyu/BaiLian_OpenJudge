/*
Recurse
N Queens problem
*/
#include<iostream>
#include<cmath>
using namespace std;

void NQueen(int k);
int N;
//用来存放算好的皇后位置。最左上角是(0,0)
int queenPos[100];

int main()
{
	cin >> N;
	NQueen(0); //从第 0 行开始摆皇后

	return 0;
}
// 在 0~k 1 行皇后已经摆好的情况下，摆第 k 行及其后的皇后
void NQueen(int k)
{
	
	int i;
	if (k == N) // N 个皇后已经摆好
	{
		for (i = 0; i < N; i++)
		{
			cout << queenPos[i] + 1<<" ";
		}
		cout << endl;
		return;
		
	}
	// 逐尝试第 k 个皇后的位置
	// 0~N 列遍历 ，第K行皇后应该放在第几列
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < k; j++)
		{
			
			// 和已经摆好的 k 个皇后的位置比较，看是否冲突
			// 1. 不能在同一列
			// 2. 不能在对角线上，即 行间距  ！= 列间距 
			if (queenPos[j] == i || abs(k - j) == abs(i - queenPos[j]))
			{
				break; //冲突，则试下一个位置
			}
		}
		if (j == k) // 当前选的位置 i 不冲突
		{
			queenPos[k] = i; //将第 k 个皇后摆放在位置 i
			NQueen(k + 1);
		}
	}
}