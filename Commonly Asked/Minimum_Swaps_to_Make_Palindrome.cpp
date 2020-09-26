#include <iostream>
#include <unordered_map>
using namespace std;


// program to compute the number of times you need to swap to transform the string into a palindrome.
// more at https://www.codechef.com/problems/ENCD12


bool check(string s)
{
    unordered_map<char, int> mp;
    for(int i=0; i<s.length(); i++)
    {
        mp[s[i]]++;
    }
    int one=0;
    for(auto it: mp)
    {
        if(it.second%2==1)  one++;
        if(one > 1) return false;
    }
    return true;
}

int main() {
	string str;
	while(cin >> str)
	{
	    if(str=="0")    break;
	    
	    if(!check(str))
	    {
	        cout << "Impossible" << endl;
	        continue;
	    }
	    
	    int front=0, rear=str.length()-1, count=0;
	    while(front<rear && (front<str.length()/2))
	    {
	        while(str[front]!=str[rear])
	        {
	            rear--;
	        }
	        if(front==rear) 
	        {
	            swap(str[front], str[front+1]);
	            rear = str.length()-1-front;
	            continue;
	        }
	        while(str[front]!=str[str.length()-1-front])
	        {
	            swap(str[rear], str[rear+1]);
	            rear++;
	            count++;
	        }
	        rear--;
	        front++;
	    }
	    cout << count << endl;
	}
	return 0;
}
