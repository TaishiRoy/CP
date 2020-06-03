#include <iostream>
using namespace std;

int main() {
	long long int n;
	while( cin >> n)
	{
		cout << (n && (!(n&(n-1))) ? "TAK" : "NIE") << endl;
	}
	return 0;
}
