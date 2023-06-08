class Solution {
    bool flag = true;
     vector<int>global;
     vector<int>curr;
    vector<vector<int>>mat;
public:
    bool canFinish(int n, vector<vector<int>>& arr)
    {
        vector<int>k(n,-1);
        vector<vector<int>>matt(n,k);
        vector<int>kk(n,0);
        
        mat = matt;
        global = kk;
        curr =kk;

        for(int i=0;i<arr.size();i++)
        {
           int cou = arr[i][0];
           int pre = arr[i][1];
           mat[cou][pre]=1;
           if(mat[pre][cou]==1)
           {
               return false;
           }
        }

        for(int i=0;i<mat.size()  && flag ;i++)
        {
            for(int j=0;j<mat[0].size() && flag ;j++)
            {
                    global[i]=1;
                    if(global[j]==1)
                    {
                        continue;
                    }
                    if(curr[i]==1)
                    {
                        flag = false;
                        break;
                    }
                if(mat[i][j]==1)
                {
                    curr[i]=1;
                    
                    dfs(j);
                    curr[i]=0;
                }
            }
        }
        return flag;
    }
    
    void dfs(int k)
    {
        global[k]=1;
        for(int j=0;j<mat[0].size() && flag ;j++)
            {
                if(mat[k][j]==1)
                {
                    
                    if(curr[j]==1)
                    {
                        flag = false;
                        return ;
                    }
                    if(global[j]==1)
                    {
                        return;
                    }
                    curr[j]=1;
                    dfs(j);
                    curr[j]=0;
                }
            }
        
    }

};