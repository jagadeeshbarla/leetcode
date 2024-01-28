class Solution {
    
public:
    
    void create(vector<vector<int>>&score_map,int i,int j)
    {
        if(i < 0 || j < 0 || i >= score_map.size() || j >= score_map[0].size() || score_map[i][j] > -1)
        {
            return ;
        }
        
        int score = 0;
        if(i-1 < 0)   
        {
            score+=1;
        }
        if(j-1 < 0)   
        {
            score+=1;
            
        }
        if(i+1 >= score_map.size())   
        {
            score+=1;
        }
        if(j+1 >= score_map[0].size())   
        {
            score+=1;
        }
        score_map[i][j] = score;
        create(score_map,i+1,j);
        create(score_map,i-1,j);
        create(score_map,i,j+1);
        create(score_map,i,j-1); 
    }
    
    int fun(vector<vector<int>>&score_map,int i,int j,int max_moves,map<vector<int>,int> &m)
    {
        if(max_moves == 0)
        {
            return 0;
        }
        
        if(i < 0 || j < 0 || i >= score_map.size() || j >= score_map[0].size() )
        {
            return 0;
        }
        
        if(m.count({i,j,max_moves}) == 1)
        {
            return m[{i,j,max_moves}]; 
        }
        max_moves -= 1;
        long long int b = fun(score_map,i+1,j,max_moves,m)% 1000000007;
        long long int r = fun(score_map,i,j+1,max_moves,m)% 1000000007;
        long long int l = fun(score_map,i,j-1,max_moves,m)% 1000000007;
        long long int t = fun(score_map,i-1,j,max_moves,m)% 1000000007;
        
        max_moves += 1;
        long long int nam = ((b+r+l+t+score_map[i][j])% 1000000007);
        m.insert({{i,j,max_moves},nam});
        return m[{i,j,max_moves}];
    }
    int findPaths(int m, int n, int moves, int sr, int sc) {
        
        vector<int>temp(n,-1);
        vector<vector<int>>score_map(m,temp);
        create(score_map,0,0);
        
        map<vector<int>,int> ma;
        fun(score_map,sr,sc,moves,ma);
        
        
        map<vector<int>,int>::iterator itr;
        // for(itr = ma.begin(); itr != ma.end() ; itr++)
        // {
        //     for(int i = 0 ; i < itr->first.size() ;i++)
        //     {
        //         cout<<itr->first[i]<<" ";
        //     }
        //     cout<<":"<<itr->second<<endl;
        // }
        return ma[{sr,sc,moves}] % 1000000007;
    }
};



// for(int i = 0 ; i < score_map.size() ; i++)
        // {
        //     for(int j = 0 ; j < score_map[0].size() ;j++ )
        //     {
        //         cout<<score_map[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        