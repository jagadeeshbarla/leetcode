class Solution {
public:
    int fact(int n) 
    {
        if (n == 0 || n == 1)
            return 1;
        else
            return n * fact(n - 1);
    }
 
    int solve(vector<int>& nums)
    {
        vector<int>flag(nums.size(),0);
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            for(int j = i + 1 ; j < nums.size() ; j++)
            {
                if(nums[j] > nums[i])
                {
                    for(int k = j + 1 ; k < nums.size() ; k++)
                    {
                        if(nums[k] > nums[j])
                        {
                            sum += 1;
                        }
                    }
                }
            }            
        }
        return sum;
               
    }
    int numTeams(vector<int>& rating) {
        int temp = solve(rating);
        reverse(rating.begin(),rating.end());
        return temp+solve(rating);
    }
};