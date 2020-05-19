#include <iostream>
using namespace std;

int getLastDgt(int x, long long y)
{
	if(y==0)
		return 1;
	// lookup for last digit of x
	int modulo[10] = { 1, 1, 4, 4, 2, 1, 1, 4, 4, 2 };
	x = x%10;
	y--;
	y = y%modulo[x];
	int dgt = x;
	while(y>0)
	{
		dgt*= x;
		dgt%= 10;
		y--;
	}
	return dgt;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		long long b;
		cin >> a >> b;
		cout << getLastDgt(a,b) << endl;
	}
	return 0;
}
