class Solution {
public:
    int solve(int amount , vector<int>&coins ,int index, map<pair<int,int>,int>&dp)
    {
        pair<int,int>temp;//amount,index
        temp.first = amount;
        temp.second = index;
        
        if(amount < 0 )
        {
            return 0;
        }
        if(amount == 0)
        {
            return 1;
        }
        if(dp.find(temp) != dp.end()) 
        {
            return dp[temp];
        }
        
        int t = 0;
        for(int i = index ; i < coins.size() ; i++)
        {
            t += solve(amount-coins[i],coins,i,dp);
        }
        return dp[temp] = t;
    }
    int change(int amount, vector<int>& coins) {
        map<pair<int,int>,int>dp;
        return solve(amount,coins,0,dp);
    }
};