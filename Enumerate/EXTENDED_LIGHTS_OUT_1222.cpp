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
int GetBit(char c, int i)  // �õ�ĳһλ��ֵ
{
	//get char c  No.i Bit 
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v) // ��ĳһλ�ó�0 �� 1
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
void Flip(char & c, int i) // ��תĳһλ
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
	char oriLights[5]; // ԭʼ����
	char lights[5]; // �м�������
	char result[5]; // �������Ŀ��ز�����1�����¿��أ�0�����޲���
	char switchs; // ĳһ�еĿ�����Ϣ
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

		for(int n=0 ; n<64  ;n++) //�������п��ص�64�ֲ���
		{
			memcpy(lights, oriLights, sizeof(oriLights));
			switchs = n; //�ȼٶ���0�еĿ�����Ҫ�Ĳ�������

			for (int i = 0; i < 5; ++i)
			{
				result[i] = switchs;//�����i�п��صĲ�������
				for (int j = 0; j < 6; ++j)//���ݷ����޸ĵ�i�еĵ�
				{
					if (GetBit(switchs, j)) //switchs�ĵ�j��λ����1��ʾ��Ҫ���µ�i�е�j����ť������0��ʾ����Ҫ���¸ð�ť
					{
						if (j > 0)
							Flip(lights[i], j - 1);//�����
						Flip(lights[i], j);//�Ŀ���λ�õĵ�
						if (j < 5)
							Flip(lights[i], j + 1);//���ҵ�

					}
				}
				if (i < 4)
					lights[i + 1] ^= switchs;//����һ�еĵ�
				switchs = lights[i];//��i+1�п��صĲ��������ɵ�i�еƵ�״̬����
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
char oriLights [5]; ����ƾ���һ�����ر�ʾһյ��
char lights[5];
��ͣ�仯�ĵƾ���
char result[5];
������ؾ���
char
switchs ĳһ�еĿ���״̬
memset(oriLights,0, oriLights))
*/

