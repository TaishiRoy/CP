// function to generate all possible palindrome partitioning of string (i.e. such that every string of the partition is a palindrome)
// more at https://www.interviewbit.com/problems/palindrome-partitioning/

void util(vector<vector<string>> &res, vector<string> &curr, string A, int low)
{
    if(low==A.length())
    {
        res.push_back(curr);
        return;
    }
    
    for(int i=low; i<A.length(); i++)
    {
        string check=A.substr(low, i-low+1);
        string rev=check;
        reverse(check.begin(), check.end());
        if(rev==check)
        {
            curr.push_back(check);
            util(res, curr, A, i+1);
            curr.pop_back();
        }
    }
    return;
    
}



vector<vector<string> > partition(string A) {

    vector<vector<string>> res;
    vector<string> curr;
    util(res, curr, A, 0);
    return res;
}
