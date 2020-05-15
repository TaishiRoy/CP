#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while(N--)
	{
		int a, b;
		cin >> a >> b;
		if(a == b)
		{
			cout << ((int(a/2))*4) + a%2 << endl;
			continue;
		}
		if(a - b == 2)
		{
			// cout << (int(b/2))*4 << endl;
			cout << ((int(b/2))*4) + 2 + (b%2) << endl;
			continue;
		}
		cout << "No Number" << endl;
	}
	return 0;
}
