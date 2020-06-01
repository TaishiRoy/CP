#include <iostream>
using namespace std;

int main() {
	while(1)
	{
		float len;
		cin >> len;
		if(len == 0.00)	break;
		int k = 2;
		float sum = 0.00;
		while( sum < len)
		{
			sum+= (1/(k*1.00));
			k++;
		}
		cout << k-2 << " card(s)" << endl;
		
	}
	return 0;
}
