#include <iostream>
using namespace std;

int getMoves(int* arr, int size)
{
	int sum = 0, moves = 0;
	for(int i=0; i<size; i++)
	{
		sum += arr[i];
	}
	if(sum%size !=0)	return -1;
	for(int i=0; i<size; i++)
	{
		if(arr[i] < (sum/size))
		{
			moves += (sum/size) - arr[i];
		}
	}
	return moves;
}



int main() {
	int n;
	cin >> n;
	while(n!=-1)
	{
		int* pac = new int[n]{0};
		for(int i =0; i<n; i++)
		{
			cin >> pac[i];
		}
		
		cout << getMoves(pac, n) << endl;
		cin >> n;
	}
	return 0;
}
