class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int>tns(graph.size(),0);
        vector<int>sns(graph.size(),0);
        vector<int>ans;
        
        
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].size()==0)
            {
                tns[i]=1;
                ans.emplace_back(i);
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            int flag = 0;
            for(int j=0;j<graph[i].size();j++)
            {
                if(tns[graph[i][j]]==0)
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                ans.emplace_back(i);
                sns[i]=1;
            }
        }
        while(1)
        {
            int w_flag = 0;
            for(int i=0;i<graph.size();i++)
            {
                if(sns[i]==1)
                {
                    continue;
                }
                int flag = 0;
                for(int j=0;j<graph[i].size();j++)
                {
                    if(sns[graph[i][j]]==0)
                    {
                        flag = 1;
                    }
                }
                if(flag==0)
                {
                    sns[i]=1;
                    ans.emplace_back(i);
                    w_flag = 1;
                }
            }
            
            if(w_flag == 0)
            {
                break;
            }
        }
        
        
        set<int>k(ans.begin(),ans.end());
        vector<int>temp(k.begin(),k.end());
        return temp;
        
    }
};