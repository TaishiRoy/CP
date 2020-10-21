
// Two City Scheduling problem
// more at https://leetcode.com/problems/two-city-scheduling/
// O(nlogn) time complexity using Greedy



class Solution {
public:
    static bool mycomp(vector<int> a, vector<int> b)
    {
        return (abs(a[0]-a[1]) > abs(b[0]-b[1]));
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), mycomp);
        
        int numa=costs.size()/2, numb=costs.size()/2, res=0;
        for(int i=0; i<costs.size(); i++)
        {
            if((costs[i][0]<costs[i][1] && numa>0) || numb<=0)
            {
                res+= costs[i][0];
                numa--;
            }
            else
            {
                res+= costs[i][1];
                numb--;
            }
        }
        
        return res;
    }
};
