class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long int ans = 0;
        sort(h.begin(),h.end(),greater<int>());
        int i = 0;
        while(i < k)
        {
            if(h[i]-i < 0)
            {
                break;
            }
            ans += h[i]-i;
            i++;
        }
        return ans;
    }
};