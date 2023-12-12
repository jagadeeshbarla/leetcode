class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        
        if( nums.size() == 1)
        {
                
            return nums[0];
        }
      // int x =0;
        while( i <= j)
        {
            int mid = (i+j)/2;
            
            //cout<<nums[mid]<<" ";
            if(mid == 0 || mid == nums.size()-1)
            {
                if( nums[nums.size()-1] < nums[0] )
                {
                    //cout<<"ghjk";
                    int n = nums.size()-1;
                    while(nums[n] > nums[n-1])
                    {
                        n--;
                    }
                    return nums[n];
                }
                return nums[mid];
            }
            else if( nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])
            {
                return nums[mid];
            }
            else if( nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
            {
                j = mid - 1;
            }
            else if( nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1])
            {
                i = mid + 1;
            }
            
            
            else if( nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
            {
                return nums[mid+1];
            }
            // x+=1;
            // if(x==10)
            // {
            //     break;
            // }
        }
        return 0;
    }
};