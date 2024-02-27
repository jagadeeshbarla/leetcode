class Solution {
public:
    
    int getnumber(vector<int>o)
    {
        int flag = 1;
        for(int i = 0 ; i < o.size();i++)
        {
            if(o[i] == 1)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            return 1;
        }
        
        flag = 1;
        for(int i = 0 ; i < o.size();i++)
        {
            if(o[i] == 2)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            return 2;
        }
        
        flag = 1;
        for(int i = 0 ; i < o.size();i++)
        {
            if(o[i] == 3)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            return 3;
        }
        
        return 4;      
    }
    
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& path) {
        
        vector<int> vis(n,-1);
        vector<int> ans(n,1);
        map<int,vector<int>>m;
        for(int i = 0 ; i < path.size() ;i++)
        {
            m[path[i][0]].emplace_back(path[i][1]);
            m[path[i][1]].emplace_back(path[i][0]);
        }
        map<int,vector<int>>occupied;
        for(int i = 1 ; i <= n ; i++)
        {
            if(vis[i-1] == -1)
            {
                vis[i-1] = 1;
                queue<int>q;
                for(int j = 0 ; j < m[i].size() ; j++)
                {
                    occupied[m[i][j]].emplace_back(ans[i-1]);
                    if(vis[m[i][j]-1] == -1)
                    {
                        q.push(m[i][j]);
                        vis[m[i][j]-1] = 1;
                    }
                }
                while(!q.empty())
                {
                    int x = q.front();
                    ans[x-1] = getnumber(occupied[x]);
                    
                    for(int j = 0 ; j < m[x].size() ; j++)
                    {
                        occupied[m[x][j]].emplace_back(ans[x-1]);
                        if(vis[m[x][j]-1] == -1)
                        {
                            q.push(m[x][j]);
                            vis[m[x][j]-1] = 1;
                        }
                    }
                    q.pop();                    
                }
            }
        }
        return ans;
    }
}; 


