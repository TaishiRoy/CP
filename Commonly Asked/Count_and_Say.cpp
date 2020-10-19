

// solution to count and say problem

#define ll long long
string Solution::countAndSay(int A) {
    if(A==1)    return "1";
    if(A==2)    return "11";
    string store = "11";
    for(ll i=3; i<=A; i++ )
    {
        string out;
        ll count=1;
        store+= '$';
        ll slen = store.length();
        for(ll j=1; j<slen; j++)
        {
            if(store[j] == store[j-1])
            {
                count++;
            }
            else
            {
                out+= count + '0';
                out+= store[j-1];
                count=1;
            }
        }
        store = out;
    }
    return store;
}

