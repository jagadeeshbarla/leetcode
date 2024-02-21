class Solution {
public:
    
    void fun(int curr_i , vector<vector<int>>& graph , vector<vector<int>>& ans , vector<int> curr_v)
    {
        curr_v.emplace_back(curr_i);
        if(curr_i == graph.size()-1)
        {
            ans.emplace_back(curr_v);
            return ;
        }
        for(int i = 0 ; i < graph[curr_i].size() ; i++)
        {
            fun(graph[curr_i][i],graph,ans,curr_v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int>curr_v;
        fun(0,graph,ans,curr_v);
        return ans;
    }
};