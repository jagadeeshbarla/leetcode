class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        for(int i= grid.size()-2;i>=0;i--)
        {
            grid[i][grid[0].size()-1]+=grid[i+1][grid[0].size()-1];
        }
        for(int i= grid[0].size()-2;i>=0;i--)
        {
            grid[grid.size()-1][i]+=grid[grid.size()-1][i+1];
        }
        
        for(int i=grid.size()-2;i>=0;i--)
        {
            for(int j=grid[0].size()-2;j>=0;j--)
            {
                grid[i][j] += min(grid[i+1][j],grid[i][j+1]);
            }
            //cout<<endl;
        }
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                cout<<grid[i][j]<<"  ";
            }
            cout<<endl;
        }
        return grid[0][0];
        
    }
};