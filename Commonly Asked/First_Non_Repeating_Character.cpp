
// function to find the first non-repeating character in a stream of characters
// more at https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
// O(n) time complexity O(n) auxillary space (queue)

string solve(string A) {
    queue<char> q;
    string out;
    unordered_map<char, int> mp;
    for(int i=0; i<A.length(); i++)
    {
        if(mp.find(A[i])==mp.end())    q.push(A[i]);
        mp[A[i]]++;
        while(mp[q.front()]>=2 && !q.empty())
        {
            q.pop();
        }
        if(q.empty())
        {
            out+='#';
        }
        else
            out+=q.front();
    }
    
    return out;
}
