
// Find Common Characters
// more at https://leetcode.com/problems/find-common-characters/

//Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  
// For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> mp, temp;
        
        for(int j=0; j<A[0].length(); j++)
        {
            mp[A[0][j]]++;
        }
       
        temp = mp;
        for(int i=1; i<A.size(); i++)
        {
            mp = temp;
            for(int j=0; j<A[i].length(); j++)
            {
                if(temp[A[i][j]]>0)
                {
                    temp[A[i][j]]--;
                }
            }
            
            for(auto it:temp)
            {
                if(temp[it.first]<mp[it.first])
                {
                    temp[it.first] = mp[it.first] - temp[it.first];
                }
                else
                {
                    temp[it.first]=0;
                }
            }
        }
        
        vector<string> out;
        
        for(auto it: temp)
        {
            while(it.second!=0)
            {
                string curr;
                curr+= it.first;
                out.push_back(curr);
                it.second--;
            }
        }
        
        return out;
    }
};

