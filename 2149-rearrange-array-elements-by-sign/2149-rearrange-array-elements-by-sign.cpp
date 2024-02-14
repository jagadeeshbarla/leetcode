class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pv,nv;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] < 0)
            {
                nv.emplace_back(nums[i]);
            }
            else
            {
                pv.emplace_back(nums[i]);
            }
        }
        int c = 0;
        for(int i = 0 ; i < nums.size() ; i += 2)
        {
            nums[i] = pv[c];
            nums[i+1] = nv[c++];
        }
        return nums;
    }
};