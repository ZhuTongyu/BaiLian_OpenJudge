/*
http://bailian.openjudge.cn/practice/1222
1222:EXTENDED LIGHTS OUT
level : hard
*/


#include<memory>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int GetBit(char c, int i)  // 得到某一位的值
{
	//get char c  No.i Bit 
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v) // 把某一位置成0 或 1
{
	//set char c No.i bit is v
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}

}
void Flip(char & c, int i) // 翻转某一位
{
	//char c No. i bit flip 
	c ^= (1 << i);
}

void OutputResult(int t, char result[]) // output result
{
	cout << "PAZZLE #" << t << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << GetBit(result[i], j) ;
			if (j < 5)
				cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	char oriLights[5]; // 原始输入
	char lights[5]; // 中间运算结果
	char result[5]; // 最后输出的开关操作，1代表按下开关，0代表无操作
	char switchs; // 某一行的开关信息
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(oriLights, 0, sizeof(oriLights)); // if not omit??
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				int s;
				cin >> s;
				SetBit(oriLights[i], j, s);
			}
		}

		for(int n=0 ; n<64  ;n++) //遍历首行开关的64种操作
		{
			memcpy(lights, oriLights, sizeof(oriLights));
			switchs = n; //先假定第0行的开关需要的操作方案

			for (int i = 0; i < 5; ++i)
			{
				result[i] = switchs;//保存第i行开关的操作方案
				for (int j = 0; j < 6; ++j)//根据方案修改第i行的灯
				{
					if (GetBit(switchs, j)) //switchs的第j个位等于1表示需要按下第i行第j个按钮，等于0表示不需要按下该按钮
					{
						if (j > 0)
							Flip(lights[i], j - 1);//改左灯
						Flip(lights[i], j);//改开关位置的灯
						if (j < 5)
							Flip(lights[i], j + 1);//改右灯

					}
				}
				if (i < 4)
					lights[i + 1] ^= switchs;//改下一行的灯
				switchs = lights[i];//第i+1行开关的操作方案由第i行灯的状态决定
			}
			if (lights[4] == 0)
			{
				OutputResult(t, result);
				break;
			}

		}
	}
	return 0;
}

/*
int GetBit(char c, int i)
void SetBit(char & c,  int i, int v)
void Flip(char & c, int i)
void OutputResult(int t, char result[])
char oriLights [5]; 最初灯矩阵，一个比特表示一盏灯
char lights[5];
不停变化的灯矩阵
char result[5];
结果开关矩阵
char
switchs 某一行的开关状态
memset(oriLights,0, oriLights))
*/

