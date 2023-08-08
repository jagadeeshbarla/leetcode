class Solution {
public:
    
    int bs(vector<int>&nums,int i,int j,int t)
    {
        
        while(i<=j)
        {
            int mid=(i+j)/2;
           // cout<<nums[i]<<"  "<<nums[mid]<<"  "<<nums[j]<<endl;
            if(nums[mid]==t)
            {
                return mid;
            }
            else if(nums[mid]>t)
            {
                j = mid-1;
            }
            else if(nums[mid]<t)
            {
                i = mid+1;
            }
            
        }
        return -1;
        
    }
    int search(vector<int>& nums, int t) 
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                int index = i;
                return max( bs(nums,0,index,t), bs(nums,index+1,nums.size()-1,t) );
            }
        }
        cout<<"dfg";
        return bs(nums,0,nums.size()-1,t);
    }
};