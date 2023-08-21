class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        map<int,int>m;
        for(int i = 0 ;i  < nums.size(); i++)
        {
            m[nums[i]]+=1;
        }
        vector<int>ans;
        
        map<int,int>::iterator itr;
       for(itr = m.begin(); itr != m.end();itr++)
        {
            if(itr->second != 1)
            {
                ans.emplace_back(itr->first);
            }
        }
        return ans;
    }
};