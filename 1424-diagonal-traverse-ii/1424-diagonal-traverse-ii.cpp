class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
         map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[i+j].emplace_back(nums[i][j]);
            }
        }

        vector<int>ans;
        map<int,vector<int>>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            reverse(itr->second.begin(),itr->second.end());
            for(int i=0;i<itr->second.size();i++)
            {
                ans.emplace_back(itr->second[i]);
            }

        }
        return ans;
    }
};