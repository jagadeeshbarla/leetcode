class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& gr) {
        vector<long long int>temp(gr[0].size(),0);
        vector<vector<long long int>> g(gr.size(),temp);
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(gr[i][j]==1)
                {
                    g[i][j]=0;
                }
                else
                {
                    g[i][j]=1;
                }
            }
        }
       
        
        int flag =0;
        for(int i=g.size()-1;i>=0;i--)
        {
            if(g[i][g[0].size()-1]==0)
            {
                flag =1;
            }
            if(flag==1)
            {
              g[i][g[0].size()-1]=0;  
            }
        }
        flag =0;
        for(int i=g[0].size()-1;i>=0;i--)
        {
           if(g[g.size()-1][i]==0)
           {
               flag =1;
           }
            if(flag==1)
            {
              g[g.size()-1][i]=0; 
            }
        }
        
        for(int i = g.size()-2;i>=0;i--)
        {
            for(int j = g[0].size()-2;j>=0;j--)
            {
                if(g[i][j]!=0)
                {
                    g[i][j] =( (g[i+1][j])%2000000000+(g[i][j+1])%2000000000 )%2000000000;
                }
            }
        }
        
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
               cout<<g[i][j]<<"  ";
            }
            cout<<endl;
        }
        
        return g[0][0];
        
    }
};