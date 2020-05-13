#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	 while(t--)
	 {
	 	long long int a , b;
	 	cin >> a >> b;
	 	
	 	for(long long int i = a; i<=b; i++)
	 	{
	 		if( i == 2)
	 		{
	 			cout << 2 << endl;
	 			continue;
	 		}
	 		if( i == 3)
	 		{
	 			cout << 3 << endl;
	 			continue;
	 		}
	 		if( (i%6 == 1) || (i%6 == 5))       // (6k +/- 1) rule for finding primes
	 		{
	 			for( long long int j=2; j*j<=(i+1); j++ )
	 			{
	 				if(i%j == 0)
	 				{
	 					break;
	 				}
	 				
	 				if((j+1)*(j+1) >= (i+1))
	 				{
	 					cout << i << endl;
	 				}
	 			}
	 		}
	 		
	 	}
	 	cout << endl;
	 }
	return 0;
}
