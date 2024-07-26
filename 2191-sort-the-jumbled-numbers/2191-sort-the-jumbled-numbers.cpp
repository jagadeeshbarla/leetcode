class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>temp;
        unordered_map<int,int>m;
        for(int i = 0 ; i < mapping.size() ; i++)
        {
            m.insert({i,mapping[i]});
        }
        
        unordered_map<int,queue<int>>m2;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int curr_num = nums[i];
            int generated_num = 0;
            int mul = 1;
            if(nums[i] == 0)
            {
                generated_num = m[0];
            }
            while( curr_num > 0)
            {
                generated_num += (m[curr_num%10] * mul);
                mul *= 10;
                curr_num /= 10;
            }
            m2[generated_num].push(nums[i]);
            temp.emplace_back(generated_num);
        }
        sort(temp.begin(),temp.end());
        for(int i = 0 ; i < temp.size() ; i++)
        {
            //cout<<temp[i]<<" ";
            nums[i] = m2[temp[i]].front();
            m2[temp[i]].pop();
        }
        return nums;
        
    }
};