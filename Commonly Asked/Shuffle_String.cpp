

// Shuffle String
// Given a string s and an integer array indices of the same length.
// The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
// Return the shuffled string.
// more at https://leetcode.com/problems/shuffle-string/



class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int id=0, curr=0;
        while(id<s.length())
        {
            if(indices[id]==id)
            {
                id++;
                continue;
            }
            swap(s[id], s[indices[id]]);
            swap(indices[id], indices[indices[id]]);
            int curr = indices[id];
            while(curr != indices[curr])
            {
                swap(s[curr], s[indices[curr]]);
                swap(indices[curr], indices[indices[curr]]);
                curr=indices[curr];
            }
        }
        
        return s;
    }
};
