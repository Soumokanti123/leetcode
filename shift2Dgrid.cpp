// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
{
    int n = grid.size();
    int m = grid[0].size();
        
    while(k > 0)
    {
        auto temp = grid;
            
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m - 1; ++j)
            {
                temp[i][j + 1] = grid[i][j];
            }
        }
            
        for(int i = 0; i < n - 1; ++i)
        {
            temp[i + 1][0] = grid[i][m - 1];
        }
            
        temp[0][0] = grid[n - 1][m - 1];
            
        grid = temp;
            
        --k;
    }
        
    return grid;
}
