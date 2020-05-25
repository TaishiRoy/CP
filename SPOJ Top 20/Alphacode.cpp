#include <iostream>
using namespace std;

long long int decoding( string s, long long int* dp)
{
	// the table dp stores the no of decodings possible for a substring (0->i)
	
	// base cases
	if( int(s[0])-48 == 0 )	return 0;
	else
	{
		dp[0] = 1;
	}
	
	if(	s.length() >= 2	)
	{
		if(   (((10*(int(s[0])-48)) + (int(s[1])-48)) <= 26) && (((10*(int(s[0])-48)) + (int(s[1])-48)) >= 10)) 
		{
			if( int(s[1])-48 == 0 )
			{
				dp[1] = 1;
			}
			else
				dp[1] = 2;
		}
		else if((10*(int(s[0])-48)) + (int(s[1])-48) == 0)	return 0;
		else
		{
			if(	(int(s[1])-48) == 0)
			{
				return 0;
			}
			dp[1] = 1;
		}
	}
	
	for( int i=2; i<s.length(); i++)
	{
		
		if(   (((10*(int(s[i-1])-48)) + (int(s[i])-48)) <= 26) && (((10*(int(s[i-1])-48)) + (int(s[i])-48)) >= 10))
		{
			if(	(int(s[i])-48) == 0)
			{
				dp[i-1] = dp[i-2];
				dp[i] = dp[i-1];
			}
			else
				dp[i] = dp[i-1] + dp[i-2];
		}
		else if((10*(int(s[i-1])-48)) + (int(s[i])-48) == 0)	return 0;
		else
		{
			if(	(int(s[i])-48) == 0)
			{
				return 0;
			}
			dp[i] = dp[i-1];
		} 
	}

	return dp[s.length()-1];
}


int main() {
	string encrypt = "";
	cin >> encrypt;
	while( (encrypt[0] != '0') || (encrypt.length() != 1))
	{
		long long int* dp = new long long int[encrypt.length()];
		
		cout << decoding(encrypt, dp) << endl;
		cin >> encrypt;
	}
	return 0;
}
