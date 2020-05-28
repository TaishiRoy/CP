#include <iostream>
using namespace std;

string mirror(string s)
{
	for(int i= s.length()/2 -1; i>=0; i--)
	{
		string s2 = "";
		s2 = s[i];
		s.replace(s.length() -1 -i, 1, s2);
	}
	return s;
}

string incrementMid(string s, int pos)
{
	string s2 = "";
	int carr = 1;
	for(int i=pos; i>=0; i--)
	{
		if(carr == 0)	break;
		if(s[i] == '9')
		{
			s2+= '0';
			s.replace( i, 1, s2);
			s2="";
			continue;
		}
		else
		{
			s2+= char(int(s[i]) + 1);
			s.replace( i, 1, s2);
			carr = 0;
			break;
		}
	}
	
	return s; // returns a string with left half rectified
}


string allNine(string s)
{
	string out = "";
	out+= '1';
	for( int i=0; i<s.length()-1; i++)
	{
		out+= '0';
	}
	out+= '1';
	return out;
}


string isPal(string s)
{
	if(s.length()%2 == 0)
	{
		string s2 = incrementMid(s, s.length()/2-1);
		return mirror(s2);
	}
	else
	{
		string s2 = incrementMid(s, s.length()/2);
		return mirror(s2);
	}
}


string notPal(string s)
{
	for(int i=s.length()/2 -1; i>=0; i--)
	{
		if(s[i] == s[s.length() -1 -i])	continue;
		if(int(s[i]) > int(s[s.length() -1 -i]))
		{
			break;
		}
		if(int(s[i]) < int(s[s.length() -1 -i]))
		{
			return isPal(s);
		}
	}
	return mirror(s);
}



string toPalindrome(string s)
{
	// all 9
	bool nine = true;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] != '9')
		{
			nine = false;
			break;
		}
	}
	if(nine)	return allNine(s);
	
	// palindrome
	bool pal = true;
	for(int i=0; i<s.length()/2; i++)
	{
		if(s[i] != s[s.length()-1 -i])
		{
			pal = false;
			break;
		}
	}
	
	if(pal)		return isPal(s);
	
	
	
	// not a palindrome
	return notPal(s);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << toPalindrome(s) <<endl;
	}
	return 0;
}
