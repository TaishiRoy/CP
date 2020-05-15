#include <iostream>
#include<string>
using namespace std;

string getRPN(string x)
{ 
	
	int i=0;
	string out="", stack = "";
	while( i < x.length() )
	{
		
		if( x[i] == '(')
		{
			i++;
			continue;
		}
		if( (x[i] == '+') || (x[i] == '-') || (x[i] == '*') || (x[i] == '/') || (x[i] == '^') )
		{
			stack+= x[i];
			i++;
			continue;
		}
		if( x[i] == ')')
		{
			out += stack[stack.length()-1];
			stack.resize(stack.length() -1 );
			i++;
			continue;
		}
		out += x[i++];
	}
	if( stack.length() != 0)
	{
		out += stack[stack.length()-1];
	}
	return out;
}

int main() {
	int T;
	cin >> T;
	while(T--)
	{
		string inp = "", rpn = "";
		cin >> inp;
		rpn = getRPN(inp);
		cout << rpn << endl;
	}
	return 0;
}
