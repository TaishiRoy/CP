#include <iostream>
using namespace std;

int reverse(int x)
{
	int y =0;
	while(x!=0)
	{
		y*=10;
		y+= x%10;
		x/=10;
	}
	return y;
}



int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		
		a = reverse(a);
		b = reverse(b);
		
		cout << reverse(a+b) << endl;
	}
	return 0;
}
