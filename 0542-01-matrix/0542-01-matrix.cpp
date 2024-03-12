class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
        queue<vector<int>>q;
        for(int i=0;i<mat.size();i++)
        {
           for(int j=0;j<mat[0].size();j++)
           {
               if(mat[i][j]==0)
               {
                   ans[i][j]=0;
                   q.push({i+1,j,1});q.push({i-1,j,1});
                   q.push({i,j+1,1});q.push({i,j-1,1});
               }
           }
        }
        while(!q.empty())
        {
            vector<int>temp1 = q.front();
            q.pop();
            if(temp1[0] < 0  || temp1[0] >= mat.size() || temp1[1] < 0 ||  temp1[1] >= mat[0].size())
            {
                continue;
            }
            else if(ans[temp1[0]][temp1[1]] == -1 && mat[temp1[0]][temp1[1]] == 1)
            {
                ans[temp1[0]][temp1[1]] = temp1[2];
                q.push({temp1[0]-1,temp1[1],temp1[2]+1});
                q.push({temp1[0]+1,temp1[1],temp1[2]+1});
                q.push({temp1[0],temp1[1]-1,temp1[2]+1});
                q.push({temp1[0],temp1[1]+1,temp1[2]+1});                                                 
            }
            else if( mat[temp1[0]][temp1[1]] == 1 && ans[temp1[0]][temp1[1]]   > temp1[2]) 
                                 //[[0,1,1,1,1,1,1,0]]
            {
                ans[temp1[0]][temp1[1]] = temp1[2];
                q.push({temp1[0]-1,temp1[1],temp1[2]+1});
                q.push({temp1[0]+1,temp1[1],temp1[2]+1});
                q.push({temp1[0],temp1[1]-1,temp1[2]+1});
                q.push({temp1[0],temp1[1]+1,temp1[2]+1});
            }
            else if(ans[temp1[0]][temp1[1]] == -1 && mat[temp1[0]][temp1[1]] == 0)
            {
                ans[temp1[0]][temp1[1]] = 0;
                q.push({temp1[0]-1,temp1[1],1});
                q.push({temp1[0]+1,temp1[1],1});
                q.push({temp1[0],temp1[1]-1,1});
                q.push({temp1[0],temp1[1]+1,1});                                                 
            }
        } 
        return ans;
    }
};