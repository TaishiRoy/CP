#include <iostream>
using namespace std;

int getTrailingZeros(int x)     // # of trailing zeros = floor(n/5) + floor(n/25) + floor(n/125) + ....
{
	int y = 5, count = 0;
	while(x/y >= 1)
	{
		count += x/y;
		y *= 5;
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	while( T-- )
	{
		int n;
		cin >> n;
		cout << getTrailingZeros(n) << endl;
	}
	
	return 0;
}
