#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

double exp()
{
	char s[20];
	cin >> s; // ���������������ַƫ��
	switch (s[0])
	{
	case '+':
		return exp() + exp();
	case '-':
		return exp() - exp();
	case '*':
		return exp() * exp();
	case '/':
		return exp() / exp();
	default:
		//return atof(s[0]);

		return atof(s);
	break;

	}
}

int main()
{
	printf("%lf", exp());
}