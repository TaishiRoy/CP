
// Maximize Distance to Closest Person
// more at https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int begn=0, end=0, curr=0, res=0;
        
        for(int i=0; i<seats.size(); i++)
        {
            if(seats[i]==0)
            {
                begn++;
            }
            else   break;
        }
        
        for(int i=seats.size()-1; i>=0; i--)
        {
            if(seats[i]==0)
            {
                end++;
            }
            else    break;
        }
        
        for(int i=begn; i<seats.size()-end; i++)
        {
            if(seats[i]==0)
            {
                curr++;
                res = max(res, curr);
            }
            else
            {
                curr=0;
            }
        }
        res = (floor((res-1)/2)+1);
        return max(res, (max(begn, end)));
    }
};
