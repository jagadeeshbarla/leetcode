class Solution {
    int final_ans = 0;
    int fun(int curr_node , map<int,vector<int>>& m,vector<int>&his)
    {
        his[curr_node] = 1;
        vector<int>temp = m[curr_node];
        int ans = 0;
        set<int>s;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(his[temp[i]] == 1)
            {
                continue;
            }
            int x = fun(temp[i],m,his);
            s.insert(x);
            ans+= x;
        }
        if(s.size() <= 1 )
        {
            final_ans+=1;
        }
        return ans+1;
        
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int ans = 0;
        map<int,vector<int>>m;
        int max_num = 0;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            m[edges[i][0]].emplace_back(edges[i][1]);
            m[edges[i][1]].emplace_back(edges[i][0]);
            max_num = max(max_num,max(edges[i][0],edges[i][1]));
        }
        vector<int>his(max_num+1,0);
        fun(0,m,his);
        return final_ans;
        
    }
};