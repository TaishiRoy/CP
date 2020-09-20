

// function to search in a row-column sorted Matrix (where every row and column is sorted in increasing order) and a number x.
// O(n) time complexity

bool search(vector<vector<int> > matrix, int n, int m, int x) 
{
    int r=0, c=m-1;
    while(r>=0 && r<n && c>=0 && c<m)
    {
        if(x==matrix[r][c]) return 1;
        if(x<matrix[r][c])  c--;
        if(x>matrix[r][c])  r++;
    }
    
    return 0;
}
