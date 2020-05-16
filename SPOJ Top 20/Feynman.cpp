#include <iostream>
using namespace std;

long int getSq(int x)
{
	return x*(x+1)*(2*x + 1)/6;
}

int main() {
	int n;
	cin >> n;
	while(n != 0)
	{
		cout << getSq(n) << endl;
		cin >> n;
	}
	return 0;
}
