class Solution {
    vector<vector<int>>ans;
    map<vector<int>,int>m;
public:
    
    void fun(vector<int>&nums,vector<int>curr,int i)
    {
        if(i == nums.size())
        {
            return;
        }
        
        curr.emplace_back(nums[i]);
        vector<int>k(curr.begin(),curr.end());
        sort(k.begin(),k.end());
        if(m.count(k) == 0)
        {
            m.insert({k,1});
            ans.emplace_back(k);
        }
        fun(nums,curr,i+1);
        curr.pop_back();
        
        vector<int>k1(curr.begin(),curr.end());
        sort(k1.begin(),k1.end());
        if(m.count(k1) == 0)
        {
            m.insert({k1,1});
            ans.emplace_back(k1);
        }
        fun(nums,curr,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        fun(nums,curr,0);
        return ans;
    }
};