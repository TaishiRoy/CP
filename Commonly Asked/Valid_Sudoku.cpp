
// function to determine if a given sudoku board configuration is valid
// (The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.)
// O(n^2) time complexity O(1) auxiliary space



int isValidSudoku(const vector<string> &A) {
    
    unordered_set<char> st;
    
    for(int i=0; i<A.size(); i++)
    {
        st.clear();
        for(int j=0; j<A.size(); j++)
        {
            if(A[i][j]=='.')    continue;
            if(st.count(A[i][j])==1)    return false;
            st.insert(A[i][j]);
        }
    }
    
    for(int i=0; i<A.size(); i++)
    {
        st.clear();
        for(int j=0; j<A.size(); j++)
        {
            if(A[j][i]=='.')    continue;
            if(st.count(A[j][i])==1)    return false;
            st.insert(A[j][i]);
        }
    }
    int N=int(sqrt(A.size()));
    
    for(int i=0; i<A.size(); i++)
    {
        st.clear();
        for(int j=(i/N)*N; j<((i/N)*N)+N; j++)
        {
            for(int k=(i%N)*N; k<((i%N)*N)+N; k++)
            {
                if(A[j][k]=='.')    continue;
                if(st.count(A[j][k])==1)    return false;
                st.insert(A[j][k]);
            }
        }
    }
    return 1;
}

