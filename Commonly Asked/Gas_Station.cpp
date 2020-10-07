
// function to solve the Gas Station problem
// more at https://www.interviewbit.com/problems/gas-station/
// O(n) time complexity O(1) auxiliary space


int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    if(A.size()==1) return (A[0]-B[0]>=0?0:-1);
    int petr=A[0]-B[0];
    int start=0, end=(start+1)%A.size();
    while(start != end || petr<0)
    {
        while(petr<0 && start!=end)
        {
            petr-=A[start] - B[start];
            start = (start+1)%A.size();
            if(start==0)    return -1;
        }
        petr+=A[end]-B[end];
        end= (end+1)%A.size();
    }
    
    return start;
}
