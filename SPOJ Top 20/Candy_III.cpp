#include <iostream>
using namespace std;

void decide(long long* arr, long long n)
{
	long long sum = 0;
	for(int i=0; i<n; i++)
	{
		sum+= arr[i]%n;
		sum%= n;
	}
	if( sum%n == 0)	cout << "YES" << endl;
	else	cout << "NO" << endl;
	return;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		long long* candy = new long long[n]{0};
		for(int i=0; i<n; i++)
		{
			cin >> candy[i];
		}
		decide(candy, n);
	}
	return 0;
}
