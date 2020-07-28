// function to find two numbers in array such that they add up to the target, where index1 < index2.
// more at https://www.interviewbit.com/problems/2-sum/
// O(n) time complexity O(n) space complexity

vector<int> twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i=0; i<A.size(); i++)
    {
        if(mp.find(B-A[i]) != mp.end())
        {
            res.push_back(mp[B-A[i]]);
            res.push_back(i+1);
            return res;
        }
        else if(mp.find(A[i])==mp.end())
        {
            mp[A[i]]=i+1;
        }
    }
    return res;
}
