
// Remove K digits problem
// more at https://leetcode.com/problems/remove-k-digits/submissions/
// O(nk) time complexity O(1) auxiliary space


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0";
        while(k>0)
        {
            if(num.length()==k) return "0";
            for(int i=0; i<num.length()-1; i++)
            {
                if(num[i]>num[i+1])
                {
                    num.erase(num.begin()+i);
                    k--;
                    break;
                }
                if(i==num.length()-2)
                {
                    num.erase(num.end()-1);
                    k--;
                    break;
                }
            }
        }
        
        while(num[0]=='0')
        {
            num.erase(num.begin());
        }
        if(num.length()==0) num="0";
        
        return num;
    }
};

