

// Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/


class Solution {
public:
    string removeOuterParentheses(string S) {
        
        stack<int> stk;
        string res;
        for(int i=0; i<S.length(); i++)
        {
            if(S[i]=='(')
            {
                stk.push(i);
            }
            else if(S[i]==')')
            {
                int id= stk.top();
                stk.pop();
                if(stk.size()==0)
                {
                    res += S.substr(id+1, i-id-1);
                }
            }
        }
        return res;
    }
};

