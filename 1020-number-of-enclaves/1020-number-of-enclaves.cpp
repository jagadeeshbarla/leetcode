class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0 ||j==0 || i==(grid.size()-1) ||j==(grid[0].size()-1)     )
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j] = 0;
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=1;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        trav(grid,i-1,j);
        trav(grid,i+1,j);
        trav(grid,i,j-1);
        trav(grid,i,j+1);
    }
    void trav(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 ||j<0 || i>=grid.size() ||j>=grid[0].size())
        {
            return ;
        }
        if(grid[i][j]==1)
        {
            grid[i][j]=0;
            dfs(grid,i,j);
        }
    }
};