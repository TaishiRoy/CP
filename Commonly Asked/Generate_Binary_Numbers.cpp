// function to print all binary numbers upto n
// O(n) time complexity

vector<string> generate(ll n)
{
	vector<string> res;
	queue<string> q;
	q.push("1");
	res.push_back("1");
	n--;
	while(n>0)
	{
	    string last=q.front();
	    q.pop();
	    q.push(last+"0");
	    res.push_back(last+"0");
	    n--;
	    if(n>0)
	    {
	        q.push(last+"1");
	        res.push_back(last+"1");
	        n--;
	    }
	}
	return res;
}
