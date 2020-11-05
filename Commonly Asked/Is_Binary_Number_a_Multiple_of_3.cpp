
// Is Binary Number Multiple of 3
// more at https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-30654/1

// User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
	    long long int a=0, b=0;
	    for(int i=0; i<s.length(); i++)
	    {
	        if(i%2==0 && s[i]=='1')  a++;
	        else if(i%2==1 && s[i]=='1')    b++;
	    }
	    if((b-a)%3==0)    return 1;
	    else return 0;
	}

};
