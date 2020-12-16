

// K-Diff Pairs in An Array
// more at https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
// O(n) time complexity O(n) auxiliary space 

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_set<int> st;
        set<pair<int, int>> pairs;
        
        int count=0; 
        for(int i=0; i<nums.size(); i++)
        {
            if(st.count(nums[i]-k)==1 && pairs.count({nums[i]-k, nums[i]})==0)
            {
                count++;
                pairs.insert({nums[i]-k, nums[i]});
                // cout << nums[i]-k << " " << nums[i] << endl;
            }
            if( st.count(nums[i]+k)==1 && pairs.count({nums[i], nums[i]+k})==0)
            {
                count++;
                pairs.insert({nums[i], nums[i]+k});
                // cout << nums[i] << " " << nums[i]+k << endl;
            }
            st.insert(nums[i]);
        }
        
        return count;
        
    }
};
