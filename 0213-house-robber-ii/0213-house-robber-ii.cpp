class Solution {
public:
    
    vector<int> fun (int index,vector<int>&nums,map<int,vector<int>> &dp)
    {
        if(index == 0)
        {
            
            return dp[index] = {nums[0],1};
        }
        if(index < 0)
        {
            return {0,0};
        }
        
        if(dp.count(index) == 1)
        {
            return dp[index];
        }
        vector<int>temp,temp2;
        
        temp = fun(index-2,nums,dp);
        int pick_sum = nums[index] + temp[0];

        temp2 = fun(index-1,nums,dp);
        int not_pick_sum =  temp2[0];
        
        vector<int>curr;
    
        if( pick_sum > not_pick_sum)
        {
            curr.emplace_back(pick_sum);
            if(index == nums.size()-1)
            {
                if(temp[1] == 1)
                {
                    temp[1] = 2;
                }
            }
            curr.emplace_back(temp[1]);
            return dp[index] = curr;
            
        }
        curr.emplace_back(not_pick_sum);
        curr.emplace_back(temp2[1]);
        return dp[index] = curr;
        
    }
    

    
    int rob(vector<int>& nums) {
        if(nums.size() == 2) return max(nums[0],nums[1]);
        
        
        map<int,vector<int>>m;
        vector<int> temp = fun(nums.size()-1,nums,m);
        if(temp[1]  == 2)
        {
            cout<<"d";
            
            
            vector<int>n1,n2;
            for(int i = 1 ; i < nums.size() ;i++)
                {
                    n1.emplace_back(nums[i]);
                }
            for(int i = 0 ; i < nums.size()-1;i++)
            {
                n2.emplace_back(nums[i]);
            }

            map<int,vector<int>>m1;
            vector<int>t1 = fun(n1.size()-1,n1,m1);
            map<int,vector<int>>m2;
            vector<int>t2 = fun(n2.size()-1,n2,m2);
            return max(t1[0],t2[0]);
        }
        return temp[0];
    }
};




