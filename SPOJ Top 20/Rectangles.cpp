#include <iostream>
using namespace std;


int main() {
	int n;
	while(cin >> n)
	{
		long int count =0;
		for(int row=1; row*row <= n; row++)
		{
			for(int col=row; col*row <=n; col++)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
