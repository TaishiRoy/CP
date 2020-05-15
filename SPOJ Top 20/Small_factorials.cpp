#include <iostream>
using namespace std;

int* arrMult(int x, int* a)
{
	int carry = 0;
	for(int i=0; i<200; i++)
	{
		if(a[i] == -999)
		{
			if(carry == 0)	break;
			int j = 0;
			while( carry !=0)
			{
				a[i + j] = carry%10;
				carry /= 10;
				j++;
			}
			break;
		}
		int prod = (a[i] * x) + carry;
		a[i] = prod%10;
		carry = prod/10;
	}
	return a;
} 

int* getFact(int x, int* a)
{
	a[0] = 1;
	for(int i=2; i<=x; i++)
	{
		a = arrMult(i, a);
	}
	return a;
}

int main() {	
	int T;
	cin >> T;
	while( T-- )
	{
		int n;
		cin >> n;
		int* arr = new int[200];
		for(int i=0; i<200; i++)
		{
			arr[i] = -999;
		}
		arr = getFact(n, arr);
		for(int i=199; i>=0; i--)
		{
			if(arr[i]!=-999)	cout << arr[i];
		}
		cout << endl;
	}
	
	return 0;
}
