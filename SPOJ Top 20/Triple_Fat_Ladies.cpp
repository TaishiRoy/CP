#include <iostream>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		long int k;
		cin >> k;
		if(k==1)	cout << "192" << endl;
		else
		{
			cout << 192+(k-1)*250 << endl;
		}
	}
	return 0;
}
