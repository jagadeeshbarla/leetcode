class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans += 1;
                    grid[i][j] = '0';
                    queue<vector<int>>q;

                    q.push({i,j});
                    while(!q.empty())
                    {
                        vector<int>t = q.front();
                        q.pop();
                        if(grid.size() > t[0]+1  && grid[t[0]+1] [t[1]] == '1')
                        {
                            q.push({t[0]+1,t[1]});
                            grid[t[0]+1] [t[1]] = '0';
                        }
                        if(t[0]-1 >= 0 && grid[t[0]-1] [t[1]] == '1')
                        {
                            q.push({t[0]-1,t[1]});
                            grid[t[0]-1] [t[1]] = '0';
                        }
                        if(grid[0].size() > t[1]+1   && grid[t[0]] [t[1]+1] == '1')
                        {
                            q.push({t[0],t[1]+1});
                            grid[t[0]] [t[1]+1] = '0';
                        }
                        if(t[1]-1 >= 0 && grid[t[0]] [t[1]-1] == '1')
                        {
                            q.push({t[0],t[1]-1});
                            grid[t[0]] [t[1]-1] = '0';
                        }
                        
                    }
                    
                    // for(int nam = 0 ; nam < grid.size() ; nam++)
                    // {
                    // for (int jam = 0 ; jam < grid[0].size() ; jam++)
                    // {
                    //     cout<<grid[nam][jam]<<" ";
                    // }
                    // cout<<endl;
                    // }
                    // cout<<endl;
                    // return ans;
                }
                
                
            }
        }
        return ans;
    }
};