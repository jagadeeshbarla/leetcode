class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    { int k,j;
       vector<int> ans;
         for(k=0;k<nums.size();k++) 
          {
            for(j=k+1;j<nums.size();j++)
            {
               if(nums[k]+nums[j]==target)
               {
                ans.push_back(k);
                ans.push_back(j);
                 return ans;
                }
             }
          }

        return ans;
    } 
};
        
        
        
        
 