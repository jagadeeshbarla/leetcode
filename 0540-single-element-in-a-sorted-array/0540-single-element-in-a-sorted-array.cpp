class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
 
        
        while(i <= j)
        {
            //cout<<i<<"  "<<j<<endl;
            int mid = (i+j)/2;
            if(i == j)
            {
                return nums[mid];
            }
            
            if(nums[mid-1] != nums[mid]  && nums[mid+1] != nums[mid])
            {
                return nums[mid];
            }
            
            if(nums[mid] == nums[mid+1])
            {
                 if( (j - mid)%2==0)
                 {
                    i = mid ; 
                 }
                 else
                 {
                    j = mid - 1;
                 }
            }
            
            else if(nums[mid-1] == nums[mid])
            {
                if( (mid - i)%2==0)
                 {
                    j = mid ; 
                 }
                 else
                 {
                    i = mid + 1;
                 }
            }
        }
        return 0;
    }
};