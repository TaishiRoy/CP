#include <iostream>
#include <algorithm>
using namespace std;

string klaudiaHas( string sum, string diff)		//(sum+diff)/2
{
	string temp = "", out = "";
	int carry = 0;
	reverse(sum.begin(), sum.end());
	reverse(diff.begin(), diff.end());
	for(int i=0; i<sum.length(); i++)
	{
		if(i >= diff.length())
		{
			if( (int(sum[i])-48) + carry > 9 )
			{
				temp+= char((((int(sum[i])-48) + carry)%10)+48);
				carry = 1;
				continue;
			}
			temp+= char(((int(sum[i])-48) + carry)+48);
			carry = 0;
			continue;
		}
		if((int(sum[i])-48) + (int(diff[i])-48) + carry > 9)
		{
			temp+= char((((int(sum[i])-48) + (int(diff[i])-48) + carry)%10)+48);
			carry = 1;
			continue;
		}
		temp+= char(((int(sum[i])-48) + (int(diff[i])-48) + carry) + 48);
		carry = 0;
	}
	if(carry == 1)	temp+= char(49);
	reverse(temp.begin(), temp.end());
	carry = 0;
	for(int i=0; i<temp.length(); i++)
	{
		out+= char(( (int(temp[i])-48 + carry) /2)+48);
		carry = ((int(temp[i])-48)%2)*10;
	}
	int i=0;
	while(out[i] == '0')	i++;
	if(i!=out.length())	out.erase(0,i);
	else	return "0";
	return out;
}



string nataliaHas( string sum, string diff)		//(sum-diff)/2
{
	string temp = "", out = "";
	int borrow = 0;
	reverse(sum.begin(), sum.end());
	reverse(diff.begin(), diff.end());
	for(int i=0; i<sum.length(); i++)
	{
		if(i >= diff.length())
		{
			if( (int(sum[i])-48) - borrow < 0 )
			{
				temp+= "9";
				borrow = 1;
				continue;
			}
			temp+= char(((int(sum[i])-48) - borrow)+48);
			borrow = 0;
			continue;
		}
		if((int(sum[i])-48) - (int(diff[i])-48) - borrow < 0)
		{
			temp+= char((((int(sum[i])-48) - (int(diff[i])-48) - borrow + 10)%10)+48);
			borrow = 1;
			continue;
		}
		temp+= char(((int(sum[i])-48) - (int(diff[i])-48) - borrow) + 48);
		borrow = 0;
	}
	reverse(temp.begin(), temp.end());
	borrow = 0;
	for(int i=0; i<temp.length(); i++)
	{
		out+= char(( (int(temp[i])-48 + borrow) /2)+48);
		borrow = ((int(temp[i])-48)%2)*10;
	}
	int i=0;
	while(out[i] == '0')	i++;
	if(i!=out.length())	out.erase(0,i);
	else	return "0";
	return out;
}

int main() {
	int t=10;				/////////////////////////////////////
	while(t--)
	{
		string sum = "", diff = "";
		cin >> sum >> diff;
		cout << klaudiaHas(sum, diff) << endl;
		cout << nataliaHas(sum, diff) << endl;
	}
	return 0;
}
