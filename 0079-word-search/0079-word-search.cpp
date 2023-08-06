class Solution {
    bool flag = false;
public:
    void dfs(int i,int j,vector<vector<char>>& b, string w,int index)
    {
      if(i<0 || j<0 || i==b.size() || j==b[0].size())
      {
          return ;
      }
      if(b[i][j] == w[index])
      {
          
          if( index== (w.length()-1))
          {
              flag = true;
              return ;
          }
          char temp=b[i][j];
          b[i][j]='0';
          dfs(i+1,j,b,w,index+1);
          dfs(i,j+1,b,w,index+1);
          dfs(i-1,j,b,w,index+1);
          dfs(i,j-1,b,w,index+1);
          b[i][j]=temp;
      }
      else
      {
          return;
      }
        
    }
    bool exist(vector<vector<char>>& b, string w) {
        
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                if(b[i][j] == w[0])
                {
                    bool f=false;
                    dfs(i,j,b,w,0);
                    if(f)
                    {
                        return true;
                    }
                }
            }
        }
        return flag;
    }
};