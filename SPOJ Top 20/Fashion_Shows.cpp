#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int N;
		cin >> N;
		int* male = new int[N]{0};
		int* female = new int[N]{0};
		for(int i=0; i<N; i++)
		{
			cin >> male[i];
		}
		for(int i=0; i<N; i++)
		{
			cin >> female[i];
		}
		sort(male, male+N);
		sort(female, female+N);
		int sum = 0;
		for(int i=0; i<N; i++)
		{
			sum += male[i]*female[i];
		}
		cout << sum << endl;
	}
	return 0;
}
