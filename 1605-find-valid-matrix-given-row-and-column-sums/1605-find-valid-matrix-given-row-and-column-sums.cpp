class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<int>temp(colSum.size(),0);
        vector<vector<int>>ans(rowSum.size(),temp);
        
        for(int i = 0 ; i < rowSum.size() ; i++)
        {
            ans[i][0] = rowSum[i];
        }
        
        for(int i = 0 ; i < colSum.size()-1; i++) // col iteration
        {
            unsigned long long int curr_sum = 0;
            for(int j = 0 ; j < rowSum.size() ; j++) // row iteration
            {
                curr_sum += ans[j][i];
            }
            curr_sum -= colSum[i];
            if(curr_sum > 0)
            {
                for(int j = 0 ; j < rowSum.size() ; j++)
                {
                    if(curr_sum > 0)
                    {
                        if(ans[j][i] > 0)
                        {
                            if(ans[j][i] >= curr_sum)
                            {
                                ans[j][i] -= curr_sum;
                                ans[j][i+1] += curr_sum;
                                curr_sum = 0;
                            }
                            else
                            {
                                curr_sum -= ans[j][i];
                                ans[j][i+1] += ans[j][i];
                                ans[j][i] = 0;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;        
    }
};