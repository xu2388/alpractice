#include"iostream"
#include"Windows.h"
#include"conio.h"
#include"string"
using namespace std;
int a[101] = { 0 };
int b[101] = { 0 };
int c[101] = { 0 };
void strtoint(string scr, int des[])
{
	for (int i = 0; i < scr.size(); i++)
	{
		des[scr.size() - i] = scr[i] - '0';
	}
}
int main()
{
	string s1 = { 0 };
	string s2 = { 0 };
	cin >> s1 >> s2;
	strtoint(s1, a);
	strtoint(s2, b);
	//a和b 是两个即将被用于计算但是先要被反转的两个数字
	int la = s1.size();
	int lb = s2.size();
	/*for (int i = 1; i <= s1.size(); i++)
	{
		cout << a[i];
	}
	cout << endl;
	for (int i = 1; i <= s2.size(); i++)
	{
		cout << b[i];
	}*/
	int lc = max(la, lb) + 1;
	//计算的具体实现
	//123
	//965
	//321
	//569
	//8810
	
	for (int i = 1; i <=lc; i++)
	{
		c[i] = a[i] + b[i] + c[i];//进位
		c[i + 1] = (a[i] + b[i]) / 10;//进位
		c[i] %= 10;//保留个位
	}

	//去除0
	while (c[lc] == 0 && lc > 1)
	{
		lc--;
	}

	cout << "结果为 ： " << " ";

	for (int i = lc; i >= 1; i--)
	{
		cout << c[i];
	}
	



	int waitkey = _getch();
}