#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string decode(string s, int n)
{
	string out = "";
	
	// batchwise revarsal
	for(int i=n; i<s.length(); i+=2*n)
	{
		if(i+n <= s.length())
			reverse(s.begin()+i, s.begin()+i+n);
	}
	for(int i=0; i<n; i++)
	{
		for( int j=0; j<s.length(); j++)
		{
			if( j%n == i)
			{
				out+=s[j];
			}
		}
		
	}
	return out;
}


int main() {
	int n;
	cin >> n;
	while(n!=0)
	{
		string s = "";
		cin >> s;
		cout << decode(s, n) << endl;
		cin >> n;
	}
	return 0;
}
