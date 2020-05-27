#include <iostream>
#include <algorithm>
using namespace std;

bool validate(long long* stall, long long N, long long C, long long mid)
{
	long long last = 0;
	for(int i=0; i<N; i++)
	{
		if( (stall[i] - stall[last]) >= mid )
		{
			C--;
			if(C==1)	return true;
			last = i;
		}
	}
	return false;
}

long long findMinDist(long long* stall, long long N, long long C)
{
	long long start = stall[0], stop = stall[N-1], mid;
	long long dist = -1;
	
	while( start <= stop )
	{
		mid = ( start + stop )/2;
		if( (mid <= ((stall[N-1] - stall[0])/(C-1))) && validate(stall, N, C, mid))
		{
			dist = mid;
			start = mid+1;
		}
		else
		{
			stop = mid-1;
		}
	}
	
	return dist;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		long long N, C;
		cin >> N >> C;
		long long * stall = new long long[N];
		for(int i=0; i<N; i++)
		{
			cin >> stall[i];
		}
		
		sort(stall, stall+N);
		cout << findMinDist(stall, N, C) << endl;
	}
	return 0;
}
