class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int ans = -1;
        sort(nums.begin(),nums.end());
        vector<long long int>temp(nums.size(),0);
        
        temp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ;i++)
        {
            temp[i] = nums[i] + temp[i-1];
        }
        
        for(int i = nums.size()-2 ; i >= 1; i--)
        {
            if(temp[i] > nums[i+1])
            {
                return temp[i+1];
            }
        }
        
        return ans;
    }
};