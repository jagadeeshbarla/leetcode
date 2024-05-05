class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        sort(nums.begin(),nums.end());
        long long int max = nums[nums.size()-1];
        long long int min = nums[0];
        set<vector<int>> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                long long int sum1 = static_cast<long long int>(nums[i]) + 
                                      static_cast<long long int>(nums[j]) ;
                if( sum1-min > 1000000000 || sum1+max < -1000000000)
                {
                    break;
                }
                for(int k = j+1 ; k < nums.size() ; k++)
                {
                    long long int sum2 = static_cast<long long int>(nums[i]) + 
                                         static_cast<long long int>(nums[j]) +
                                         static_cast<long long int>(nums[k]);
                    if( sum2-min > 1000000000 || sum2+max < -1000000000 )
                    {
                        break;
                    }
                    for(int l = k+1 ; l < nums.size() ;l++)
                    {
                       
                        long long int sum = static_cast<long long int>(nums[i]) + 
                                            static_cast<long long int>(nums[j]) + 
                                            static_cast<long long int>(nums[k]) + 
                                            static_cast<long long int>(nums[l]);

                        if( sum == static_cast<long long int>(target))
                        {
                            vector<int>temp;
                            temp.emplace_back(nums[i]);
                            temp.emplace_back(nums[j]);
                            temp.emplace_back(nums[k]);
                            temp.emplace_back(nums[l]);
                            ans.insert(temp);
                            if(nums[k] > 0)
                            {
                                break;
                            }
                            
                        }
                        if(nums[l] > 0 && target <= nums[i]+nums[j]+nums[k])
                        {
                            break;
                        }
                    }
                    if(nums[k] > 0 && target <= nums[i]+nums[j])
                    {
                        break;
                    }
                }
                if(nums[j] > 0 && target <= nums[i])
                {
                    break;
                }
            }
        }
        vector<vector<int>>ansv(ans.begin(),ans.end());
        return ansv;
    }
};

