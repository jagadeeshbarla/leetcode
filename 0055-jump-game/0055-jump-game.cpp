class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int i = 0;
        while(i < nums.size())
        {
            if(i >= nums.size()-1){
                return true;
            }
            if(nums[i] == 0)
            {
                return false;
            }
            
            int curr_cap = nums[i];
            int max_cap = 0;
            int temp = i;
            while(curr_cap)
            {
                if(i+curr_cap < nums.size())
                {
                    if(max_cap < i+curr_cap + nums[i+curr_cap])
                    {
                        max_cap = i+curr_cap + nums[i+curr_cap];
                        temp = i+curr_cap;
                    }
                }
                else
                {
                    return true;
                }
                curr_cap--;
            }
            i = temp;
        }
        return true;
        
    }
};