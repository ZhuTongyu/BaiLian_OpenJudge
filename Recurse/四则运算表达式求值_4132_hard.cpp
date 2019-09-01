/*
递归
四则运算表达式求值
百练：4132
输入没有空格
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip> // setprecision()

using namespace std;
double factor_value();
double term_value();
double expression_value();

int main()
{
	double ans = expression_value();
	cout << fixed<<setprecision(2)<<ans << endl;
	return 0;
}

double expression_value() // term add minus
{
	// should have while loop, term add minus many times
	// (a+b+c+d)*b + c+ d 
	double result = term_value();// 求第一项的值

	bool more = true;
	while (more)
	{
		char c = cin.peek();  //看一个字符 不取走
		if (c == '+' || c == '-')
		{
			char op = cin.get();
			double value = term_value();
			if (op == '+')
				result += value;
			else
				result -= value;
		}
		else
		{
			more = false;
		}
	}
	return result;
}

double term_value() // factor / *
{
	double result = factor_value();
	while (true) // why here is  while loop ? eg: a*b*c*d + a*b*c
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			double value = factor_value();
			if (op == '*')
				result *= value;
			else
				result /= value;
		}
		else
			break;

	}
	return result;

}

double factor_value()
{
	double result = 0;
	char c = cin.peek();
	if (c == '(')
	{
		cin.get();
		result = expression_value();
		cin.get();
	}
	else
	{
		while (isdigit(c))
		{
			result = result * 10 + c - '0';
			cin.get();
			c = cin.peek();
		}
		double tmp = 0;
		if (c == '.')
		{
			double base = 0.1;
			
			cin.get();
			char ch = cin.peek();
			while (isdigit(ch))
			{
				tmp = (ch-'0')*base + tmp;
				base = 0.1*base;
				cin.get();
				ch = cin.peek();
			}

		}
		result += tmp ;
	}
	return result;
}