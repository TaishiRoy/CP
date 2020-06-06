#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll frndCount(ll* frnd, ll N, ll need)
{
	sort(frnd, frnd+N, greater<ll>());
	ll count = 0;
	ll i=0;
	for(i=0; i<N; i++)
	{
		count+= frnd[i];
		if(count>=need)	break;
	}
	if(count<need)	return -1;
	return i+1;
	
}

int main() {
	int t;
	cin >> t;
	int T=1;
	while(t--)
	{
		ll need, N;
		cin >> need >> N;
		ll* frnd = new ll[N];
		for(ll i=0; i<N; i++)
		{
			cin >> frnd[i];
		}
		cout << "Scenario #" << T++ << ":" << endl;
		ll out = frndCount(frnd, N, need);
		if(out==-1)	cout << "impossible" << endl;
		else	cout << out << endl;
		cout << endl;
	}
	return 0;
}
