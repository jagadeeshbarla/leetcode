class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int x = (mean * (rolls.size()+n))-sum;
        
        if(x >= n && x<= (n*6))
        {
            vector<int>ans(n,1);
            x -= n;
            for(int i = 0 ;i < n ; i++)
            {
                if(x >= 5)
                {
                    x-=5;
                    ans[i]+=5;
                }
                else
                {
                    ans[i]+=x;
                    break;
                }
            }
            return ans;
        }
        return vector<int>();
    }
};