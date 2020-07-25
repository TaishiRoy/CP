
// function to starting indices of substring(s) in S that is a concatenation of each word in L 
// more at https://www.interviewbit.com/problems/substring-concatenation/

vector<int> findSubstring(string A, const vector<string> &B) {
    
    unordered_map<string, pair<int, int>> mp;
    vector<int> res;
    int len = B[0].length();
    if(A.length() < B.size()*len)   return res;
    for(int i=0; i<B.size(); i++)
    {
        mp[B[i]].first++;
        mp[B[i]].second=0;
    }
    int count=0, start=0, flag=0;
    for(int k=0; k<=A.length()-len; k++)
    {
        count = 0;
        for(int j=0; j<B.size(); j++)
        {
            mp[B[j]].second=0;
        }
        for(int i=k; i<k+(len*B.size()); i++)
        {
            if(mp[A.substr(i, len)].first - mp[A.substr(i, len)].second > 0)
            {
                count++;
                mp[A.substr(i, len)].second++;
                if(count==B.size())
                {
                    res.push_back(k);
                    count = 0;
                    start=k;
                    break;
                }
                
                i+=len-1;
            }
            else
            {
                break;
            }
        }
    }
    
    return res;
    
}

