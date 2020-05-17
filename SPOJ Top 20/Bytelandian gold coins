#include <iostream>
using namespace std;

long long int getMaxCoins(long long int x, long long int* mem)
{
	// Base case
	if(x <= 10)		return x;
	
	// memoization
	if(x < 1000000)
	{
		if(mem[x]!=0)
		{
			return mem[x];
		}
		long long int split = getMaxCoins(x/2, mem) + getMaxCoins(x/3, mem) + getMaxCoins(x/4, mem);
		mem[x] = split > x ? split : x;
		return mem[x];
	}
	
	// for large x optimise storage with part recursion
	long long int split = getMaxCoins(x/2, mem) + getMaxCoins(x/3, mem) + getMaxCoins(x/4, mem);
	return (split>x?split:x);
}

int main() {
	long long int n;
	while(cin >> n)
	{
		long long int* memo;
		if(n < 1000000)
			memo = new long long int[n+1]{0};
		else
			memo = new long long int[1000000]{0};
		cout << getMaxCoins(n, memo) << endl;
	}
	return 0;
}
