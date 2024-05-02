class Solution {
public:
    int jump(vector<int>& nums) {
        
        int count = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(i >= nums.size()-1){
                return count;
            }
            
            int curr_cap = nums[i];
            int max_cap = 0;
            int temp = i;
            int temp_1 = i + curr_cap;
            count++;
            if(temp_1 >= nums.size()-1)
            {
                return count;
            }
            
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
                    return count;
                }
                curr_cap--;
            }
            i = temp;
        }
        return count;
        
    }
};