class Solution {
public:
    long long int fun(int target,vector<int>curr_v,map<vector<int>,int>&m,vector<long long int>&dp)
    {
        if(target == 0)
        {
            if(m.count(curr_v) == 0)
            {
                m.insert({curr_v,1});
                return 1;
            }
        }
        if(target <= 0)
        {
            return 0;
        }
        if(dp[target] != -1)
        {
            return dp[target];
        }
        int ans_c = 0;
        for(int i = 1 ; i <= 2 ; i++)
        {
            curr_v.emplace_back(i);
            ans_c += fun(target-i,curr_v,m,dp);
            curr_v.pop_back();
        }
        dp[target] = ans_c;
        return ans_c;
    }
    int climbStairs(int n) {
        if(n == 0)
        {
            return 1;
        }   
        vector<long long int> dp(n+1,-1);
        map<vector<int>,int>m;
        vector<int>curr;
        fun(n,curr,m,dp);
        return dp[n];
    }
};