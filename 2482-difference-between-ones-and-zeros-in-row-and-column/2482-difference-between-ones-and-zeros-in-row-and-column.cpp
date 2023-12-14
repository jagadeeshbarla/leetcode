class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>row(grid.size(),0);
        vector<int>col(grid[0].size(),0);
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                col[j] += grid[i][j];
                row[i] += grid[i][j];
            }
        }
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                grid[i][j] = col[j] + row[i] - (grid[0].size() + grid.size() - col[j] - row[i]) ;
            }
        }
        
        
//         for(int i = 0 ; i < col.size() ; i++)
//         {
//             cout<<col[i];
//         }
        
//         cout<<endl;
//         for(int i = 0 ; i < row.size() ; i++)
//         {
//             cout<<row[i];
//         }
        return grid;
    }
};