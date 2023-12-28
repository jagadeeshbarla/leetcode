class Solution {
    long  mod_7 = 1000000007;
public:
    
    int fun(int n , int k , map<vector<int>,int>&dp,int t)
    {
        vector<int>temp;
        temp.emplace_back(n);temp.emplace_back(t);
       if(n == 0 && t == 0)
        {
            dp[temp] = 1;
            return 1;
        }
        
        
        if(t <= 0 || n == 0)
        {
            dp[temp] = 0;
            return 0;
        }
        
        
        if(dp.find(temp) != dp.end())
        {
            return dp[temp];
        }
        
        
        int x = 0;
        for(int i = 1 ; i <= k ; i++)
        {
             x = (x + fun(n-1,k,dp,t-i)) % mod_7;
        }
        dp[temp] = x;
        return dp[temp]  % mod_7; 
    }
    
    
    int numRollsToTarget(int n, int k, int t) {
        map<vector<int>,int>dp;
        vector<int>temp;
        temp.emplace_back(n);temp.emplace_back(t);
        fun(n,k,dp,t) % mod_7 ;
        return dp[temp];
    }
};