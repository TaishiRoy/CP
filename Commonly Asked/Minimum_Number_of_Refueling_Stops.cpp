

// Minimum Number of Refueling Stops
// more at https://leetcode.com/problems/minimum-number-of-refueling-stops/submissions/


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        
        int res=0, tank=startFuel, last=0;
        for(int i=0; i<stations.size(); i++)
        {
            tank-=stations[i][0] - last;
            while(!pq.empty() && tank<0)
            {
                tank+= pq.top();
                pq.pop();
                res++;
            }
            if(tank<0)  
            {
                return -1;
            }
            last = stations[i][0];
            pq.push(stations[i][1]);
        }
        
        tank-=target - last;
            while(!pq.empty() && tank<0)
            {
                tank+= pq.top();
                pq.pop();
                res++;
            }
            if(tank<0)  
            {
                return -1;
            }
        
        return res;
    }
};
