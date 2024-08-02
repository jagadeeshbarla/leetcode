class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int one_count = 0;
        for(int i = 0 ;  i < nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                one_count += 1;
            }
        }
        if(one_count == 0 || one_count == nums.size())
        {
            return 0;
        }
    
        
        int i = 0 ;
        int curr_count = 0;
        
        while(i < one_count)
        {
            if(nums[i] == 1)
            {
                curr_count++;
            }
            i++;
        }
        
        //cout<<one_count<<" "<<curr_count<<endl;
        i = 1;
        int max_count = curr_count;
        int j = one_count;
        int temp = 0;
        do
        {
            if(j == nums.size())
            {
                j = 0;
            }
            if(i == nums.size())
            {
                i = 0;
            }
            if(nums[j] == 1)
            {
                curr_count++;
            }
            if(i == 0)
            {
                if(nums[nums.size()-1] == 1)
                {
                    curr_count--;
                }
            }
            else
            {
                if(nums[i-1] == 1)
                {
                    curr_count--;
                }
            }
            max_count = max(max_count,curr_count);
            j++;
            i++;
            temp++;
        }while(temp != nums.size());
        
        return one_count-max_count;        
    }
};