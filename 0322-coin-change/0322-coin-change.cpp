class Solution {
public:
    
    int coinchange(vector<int>&c , int amount ,map<int,int>&dp)
    {
        if(amount < 0)
        {
            return INT_MAX;
        }
        if(amount == 0)
        {
           return 0;
        }
        if(dp.count(amount) != 0)
        {
            return dp[amount];
        }
        int t = INT_MAX;
        for(int i = 0 ; i < c.size() ; i++)
        {
            t = min (t ,  coinchange(c,amount-c[i],dp));
        }
        if(t != INT_MAX){t++;}
        //dp.insert({amount,min_c});
        return  dp[amount] = t;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        map<int,int>dp;
        int min_coins = INT_MAX;
        min_coins = coinchange(coins,amount,dp);
        if(min_coins == INT_MAX)
        {
            return -1;
        }
        return min_coins;
    }
};



/*
[1,2,5]
11
[2]
3
[1]
0
[411,412,413,414,415,416,417,418,419,420,421,422]
9864
[3,7,405,436]
8839
[186,419,83,408]
6249
*/