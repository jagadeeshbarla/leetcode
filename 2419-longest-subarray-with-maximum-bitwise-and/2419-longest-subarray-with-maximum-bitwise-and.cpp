class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int element = *max_element(nums.begin() , nums.end());
        int count_max = 1;
        int curr = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == element)
            {
                curr++;
            }
            else{
                count_max = max(count_max , curr);
                curr = 0;
            }
        }
        count_max = max(count_max , curr);
        return count_max;
    }
};