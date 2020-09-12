

// function to get a solution of a sudoku
// more at https://www.interviewbit.com/problems/sudoku/
// O(9^(n*n)) time complexity  O(n*n) auxiliary space

bool getBlankSpace(vector<vector<char>> &A, int &row, int &col)
{
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            if(A[i][j]=='.')
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}


bool isSafe(vector<vector<char>> &A, int row, int col, int num)
{
    for(int i=0; i<A.size(); i++)
    {
        if(A[i][col]==num+'0')  return false;
    }
    for(int i=0; i<A[0].size(); i++)
    {
        if(A[row][i]==num+'0')  return false;
    }
    for(int i=(row-(row%3)); i<row+(3-row%3); i++)
    {
        for(int j=(col-col%3); j<col+(3-col%3); j++)
        {
            if(A[i][j]==num+'0')    return false;
        }
    }
    return true;
}


bool util(vector<vector<char>> &A)
{
    int row=0, col=0;
    bool search = getBlankSpace(A, row, col);
    if(!search) return true;
    for(int i=1; i<10; i++)
    {
        if(isSafe(A,row,col,i))
        {
            A[row][col]=i+'0';
            if(util(A)) return true;
            A[row][col]='.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char> > &A) {
   bool res=util(A);
   return;
}
