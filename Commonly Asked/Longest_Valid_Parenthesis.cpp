
// Longest valid Parentheses
// more at https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
// Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring. 
// O(n) time complexity O(1) auxiliary space

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--)
	{
	    string s;
	    cin >> s;
	    
	    
	    int res=0;
	    stack<int> stk;
	    stk.push(-1);
	    for(int i=0; i<s.length(); i++)
	    {
	        if(s[i]=='(')   stk.push(i);
	        else
	        {
	            stk.pop();
	            if(!stk.empty())
	            {
	                res = max(res, i-stk.top());
	            }
	            else
	            {
	                stk.push(i);
	            }
	        }
	    }
	    cout << res << endl;
	}
	return 0;
}
