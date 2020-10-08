#include <iostream>
#include <climits>
using namespace std;



// egg dropping problem 
int main() {
	int T;
	cin >> T;
	while(T--)
	{
	    int e , f;
	    cin >> e >> f;
	    int dp[f+1][e+1];
	    
	    for(int i=0; i<=e; i++)
	    {
	        dp[0][i]=0;
	        dp[1][i]=1;
	    }
	    
	    for(int i=0; i<=f; i++)
	    {
	        dp[i][1]=i;
	    }
	    
	    for(int i=2; i<=f; i++)
	    {
	        for(int j=2; j<=e; j++)
	        {
	            dp[i][j]= INT_MAX;
	            for(int k=1; k<=i; k++)
	            {
	                dp[i][j] = min( dp[i][j], max(dp[k-1][j-1], dp[i-k][j])+1);
	            }
	            
	        }
	    }
	    cout << dp[f][e] << endl;
	}
	return 0;
}
