class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long int sum = 0;
        for(int i = 0 ; i < chalk.size() ;i++)
        {
            sum += chalk[i];
        }
        if(sum <= k)
        {
            
            k %= sum;
        }
        for(int i = 0 ; i < chalk.size() ; i++)
        {
            if(k == 0)
            {
                return i;
            }
            k -= chalk[i];
            if(k < 0)
            {
                return i;
            }
            
        }
        
        return 0;
    }
};