#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int G, M;
		cin >> G >> M;
		ll* glist = new ll[G];
		ll* mlist = new ll[M];
		for(ll i=0; i<G; i++)
		{
			cin >> glist[i];
		}
		for(ll i=0; i<M; i++)
		{
			cin >> mlist[i];
		}
		
		sort(glist, glist+G, greater<ll>());
		sort(mlist, mlist+M, greater<ll>()); 
		if(glist[0] >= mlist[0])	cout << "Godzilla" << endl;
		else if(glist[0] < mlist[0]) cout << "MechaGodzilla" << endl;
		
	}
	return 0;
}
