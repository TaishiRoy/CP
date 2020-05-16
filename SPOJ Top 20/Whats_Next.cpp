#include <iostream>
using namespace std;

int isAP( int x, int y, int z)
{
	int next;
	if ((y-x) == (z-y))
	{
		next = z + (z-y);
		return next;
	}
	return -99999;
}

int isGP(int x, int y, int z)
{
	int next;
	if ((y/x) == (z/y))
	{
		next = z*(z/y);
		return next;
	}
	return -99999;
}

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	while( (a!=0) || (b!=0) || (c!=0))
	{
		if( isAP(a,b,c) != -99999 )
		{
			cout << "AP " << isAP(a,b,c) << endl;
			cin >> a >> b >> c;
			continue;
		}
		if( isGP(a,b,c) != -99999 )
		{
			cout << "GP " << isGP(a,b,c) << endl;
		}
		cin >> a >> b >> c;
	}
	return 0;
}
