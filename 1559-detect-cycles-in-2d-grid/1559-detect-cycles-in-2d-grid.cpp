class Solution {
    bool flag = false;
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size() && !flag;j++)
            {
                if(grid[i][j]>=97 && grid[i][j]<=122)
                {
                    char temp=grid[i][j];
                    
                    //cout<<grid[i][j]<<endl;
                    grid[i][j]-=32;
                    trav_u(i-1,j,grid,temp);
                    trav_d(i+1,j,grid,temp);
                    trav_l(i,j-1,grid,temp);
                    trav_r(i,j+1,grid,temp);
                    
                }
            }
        }
        return flag;        
    }
    
    
    void trav_u(int i,int j,vector<vector<char>>& grid,char temp)
    {
        if(i<0 )
        {
            return ;
        }
        if(grid[i][j] == temp-32)
        {
            //cout<<grid[i][j] <<"  "<< target-32<<endl;
            flag = true;
            return ;
        }
        if(grid[i][j]==temp)
        {
            grid[i][j]-=32;
            trav_u(i-1,j,grid,temp);
            trav_l(i,j-1,grid,temp);
            trav_r(i,j+1,grid,temp);
        }  
     }
    
      void trav_d(int i,int j,vector<vector<char>>& grid,char temp)
      {
        if(i>=grid.size() )
        {
            return ;
        }
        if(grid[i][j] == temp-32)
        {
            //cout<<grid[i][j] <<"  "<< target-32<<endl;
            flag = true;
            return ;
        }
        if(grid[i][j]==temp)
        {
            grid[i][j]-=32;
            trav_d(i+1,j,grid,temp);
            trav_l(i,j-1,grid,temp);
            trav_r(i,j+1,grid,temp);
        }  
     }
     void trav_l(int i,int j,vector<vector<char>>& grid,char temp)
    {
        if(j<0 )
        {
            return ;
        }
        if(grid[i][j] == temp-32)
        {
            //cout<<grid[i][j] <<"  "<< target-32<<endl;
            flag = true;
            return ;
        }
        if(grid[i][j]==temp)
        {
            grid[i][j]-=32;
            trav_u(i-1,j,grid,temp);
            trav_d(i+1,j,grid,temp);
            trav_l(i,j-1,grid,temp);
           
        }  
     }
    
      void trav_r(int i,int j,vector<vector<char>>& grid,char temp)
      {
        if(j>=grid[0].size() )
        {
            return ;
        }
        if(grid[i][j] == temp-32)
        {
            //cout<<grid[i][j] <<"  "<< target-32<<endl;
            flag = true;
            return ;
        }
        if(grid[i][j]==temp)
        {
            grid[i][j]-=32;
            trav_u(i-1,j,grid,temp);
            trav_d(i+1,j,grid,temp);
            trav_r(i,j+1,grid,temp);
            
        }  
     }
    
    
};