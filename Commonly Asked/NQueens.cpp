// function to find all possible valid n-queens configuration in an n*n chessboard using backtracking
// O(N^N) time complexity


void nqueensUtil(int q, int row, vector<int> &colm, vector<vector<int>> &res)
{
    if(q==row)    // all queens safely placed in separate rows
    {
        res.push_back(colm);
        return;
    }
    
    
    // search for a safe position for each column
    for(int col=0; col<q; col++)
    {
        bool isSafe=true;
        
        // check which row of this column is safe
        for(int curr=0; curr<row; curr++)
        {
            if(colm[curr] == col || curr+colm[curr] == row+col || curr-colm[curr] == row-col)   // column preoccupied or major & minor diagonals preoccupied
            {
                isSafe=false;
                break;
            }
        }
        
        
        if(isSafe)
        {
            colm[row] = col;
            // recurr to place next queen if safe position found
            nqueensUtil(q, row+1, colm, res);
        }
    }
    return;
}


vector<vector<string> > Solution::solveNQueens(int A) {

    vector<int> pos(A);
    vector<vector<int>> res;
    vector<vector<string>> res2;
    nqueensUtil(A, 0, pos, res);
    
    // operation to convert valid solutions to chessboard configurations
    for(int i=0; i<res.size(); i++)
    {
        vector<string> temp;
        for(int j=0; j<A; j++)
        {
            string out;
            for(int k=0; k<A; k++)
            {
                if(res[i][j] == k)
                {
                    out+='Q';
                }
                else
                {
                    out+='.';
                }
            }
            temp.push_back(out);
        }
        res2.push_back(temp);
    }
    return res2;
    
}
