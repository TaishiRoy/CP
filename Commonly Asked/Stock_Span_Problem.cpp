// Stock span problem
// more at https://practice.geeksforgeeks.org/problems/stock-span-problem/0

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int T;
	cin >> T;
	while(T--)
	{
	    int N;
	    cin >> N;
	    int arr[N];
	    for(int i=0; i<N; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    stack<pair<int, int>> stk;
	    
	    for(int i=0; i<N; i++)
	    {
	        if(stk.empty())
	        {
	            stk.push({arr[i], 1});
	            arr[i] = 1;
	        }
	        else
	        {
	            int curr=0;
	            while(!stk.empty() && stk.top().first<=arr[i])
	            {
	                curr+=stk.top().second;
	                stk.pop();
	            }
	            stk.push({arr[i], curr+1});
	            arr[i] = curr+1;
	        }
	    }
	    
	    for(int i=0; i<N; i++)
	    {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
