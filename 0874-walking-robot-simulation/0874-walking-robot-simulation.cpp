class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        int x = 0;
        int y = 0;
        
        // map<int,int>row;
        // map<int,int>col;        
        map<pair<int,int>,int>m;
        for(int i = 0 ; i < obs.size() ; i++){
            // row[obs[i][0]]=1;
            // col[obs[i][1]]=1;
            m.insert({make_pair(obs[i][0],obs[i][1]),1});
        }
        
        int dir = 1;    // directions  1->+y   2->-x  3->-y  4->+x

        int ans = 0;
        for(int i = 0 ; i < com.size() ; i++)
        {
            if(com[i] < 0)
            {
                if(com[i] == -1)
                {
                    if(dir == 1)
                    {
                        dir = 4;
                    }
                    else
                    {
                        dir -= 1;
                    }
                }
                else
                {
                    dir += 1;
                    if(dir == 5)
                    {
                        dir = 1;
                    }
                }
            }
            else
            {
               if(dir == 1) // moving in +y direction || x is constant || check y is present in col
               {
                   if(true)
                   //if(row.find(x) != row.end())
                   {
                       while(com[i] > 0)
                       {
                           if(m.find(make_pair(x,y+1)) != m.end())
                           {
                               break;
                           }
                           y+=1;
                           com[i]--; 
                       }   
                   }
                   else
                   {
                       y += com[i];
                   }
               }
               else if(dir == 2) // moving in -x direction || y is constant || check x is present in row
               {
                   if(true)
                   //if(col.find(y) != col.end())
                   {
                       while(com[i] > 0)
                       {
                           if(m.find(make_pair(x-1,y)) != m.end())
                           {
                               break;
                           }
                           x-=1;
                           com[i]--;
                       }
                       
                   }
                   else
                   {
                       x -= com[i];
                   }
               }
               else if(dir == 3) // moving in -y direction || x is constant || check y is present in col
               {
                   if(true)
                   //if(row.find(x) != row.end())
                   {
                       while(com[i] > 0)
                       {
                           if(m.find(make_pair(x,y-1)) != m.end())
                           {
                               break;
                           }
                           y-=1;
                           com[i]--;
                           
                       }
                   }
                   else
                   {
                       y -= com[i];
                   }                   
               }
               else
               {
                   if(true)
                   //if(col.find(y) != col.end()) // moving in +x direction || y is constant || check x is present in row
                   {
                       while(com[i] > 0)
                       {
                           if(m.find(make_pair(x+1,y)) != m.end())
                           {
                               break;
                           }
                           x+=1;
                           com[i]--;
                       }
                   }
                   else
                   {
                       x += com[i];
                   }
               }
            }
            
            ans = max(ans , (x*x + y*y) );
        }
        
        return ans;
    }
};