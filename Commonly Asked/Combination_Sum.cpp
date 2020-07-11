// function to find a combination of integers from an array which adds up to a given target
// repitition allowed
// more details at https://www.interviewbit.com/problems/combination-sum/



void combinationSumUtil(vector<int> &A, int B, vector<vector<int>> &C, vector<int> &aux, int i)
{
    if(B==0)
    {
        sort(aux.begin(), aux.end());
        C.push_back(aux);
        return;
    }
    if(B<0) return;
    if(i>=A.size()) return;
    aux.push_back(A[i]);
    combinationSumUtil(A, B-A[i], C, aux, i);
    aux.pop_back();
    combinationSumUtil(A, B, C, aux, i+1);
    return;
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> C;
    vector<int> D;
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(), A.end()), A.end()); 
    combinationSumUtil(A, B, C, D, 0);
    return C;
}

