class Solution {
    vector<vector<int>>ans;
    int s;
public:
    void fun(vector<int>curr,vector<int>rest)
    {
        if(curr.size()==s)
        {
            ans.emplace_back(curr);
            return;
        }
        for(int i = 0;i<rest.size();i++)
        {
            curr.emplace_back(rest[i]);
            vector<int>curr_rest(rest.begin(),rest.end());
            auto it = curr_rest.begin();
            curr_rest.erase(it+i);
            fun(curr,curr_rest);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        s=nums.size();
        fun(temp,nums);
        //return ans;
        set<vector<int>>s(ans.begin(),ans.end());
        vector<vector<int>>tem(s.begin(),s.end());
        return tem;
    }
};