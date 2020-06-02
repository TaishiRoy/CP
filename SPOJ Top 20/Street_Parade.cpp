#include <iostream>
#include <stack>
using namespace std;

bool possible(int* seq, int n)
{
	// take a counter to denote the number till which sequence is possible

	int curr = 1, i = 0;
	stack<int> s;
	while(i<n)
	{
		while(!s.empty())
		{
			if( s.top() == curr)
			{
				curr++;
				s.pop();
			}
			else
			{
				break;
			}
		}
		if( seq[i] == curr)
		{
			curr++;
		}
		else if( seq[i] > curr)
		{
			s.push(seq[i]);
		}
		i++;
		
	}
	while(!s.empty())
	{
		if(s.top() == curr)
		{
			curr++;
			s.pop();
		}
		else
		break;
	}
	if(curr == n+1)	return true;
	return false;
}

int main() {
	int n;
	cin >> n;
	while(n != 0)
	{
		int* seq = new int[n];
		for(int i=0; i<n; i++)
		{
			cin >> seq[i];
		}
		string res = possible(seq, n) ? "yes" : "no";
		cout << res << endl;
		cin >> n;
	}
	return 0;
}
