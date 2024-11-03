class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_size = 1;
        vector<int>dp(nums.size(),1);
        for(int i = nums.size()-2 ; i >= 0 ; i-- ){
            int curr_max = 0;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(nums[j] > nums[i]){
                    curr_max = max(curr_max,dp[j]);                    
                }                
            }
            dp[i] = curr_max + 1;
            max_size = max(max_size , dp[i]);
        }
        return max_size;
    }
};