// function to generate all valid parenthesis formations given the number of parenthesis
// more at https://www.interviewbit.com/problems/generate-all-parentheses-ii/
// O(2^n) time complexity 


void util(int A, vector<string> &res, string str, int open)
{
    if(str.length()==2*A)
    {
        res.push_back(str);
        return;
    }
    if(open<A)
    {
        util(A, res, str+'(', open+1);
    }
    if(str.length()-open<open)
    {
        util(A, res, str+')', open);
    }
    return;
}



vector<string> generateParenthesis(int A) {
    vector<string> res;
    string str;
    util(A, res, str, 0);
    return res;
}

