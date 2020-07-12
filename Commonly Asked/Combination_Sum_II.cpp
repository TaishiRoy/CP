// function to find a combination of integers from an array which adds up to a given target
// repitition not allowed
// more details at https://www.interviewbit.com/problems/combination-sum-ii/


void combSumUtil(vector<int> &A, int B, vector<vector<int>> &out, vector<int> &currSeq, int index)
{
    
    if(B<0) return;
    if(B==0)
    {
        out.push_back(currSeq);
        return;
    }
    if(index>=A.size()) return;
    currSeq.push_back(A[index]);
    combSumUtil(A, B-A[index], out, currSeq, index+1);
    while(A[index] == A[index+1])
    {
        index++;
    }
    currSeq.pop_back();
    combSumUtil(A, B, out, currSeq, index+1);
    return;
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> out;
    vector<int> currSeq;
    combSumUtil(A, B, out, currSeq, 0);
    return out;
}

