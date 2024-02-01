class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 1 ; i < nums.size();i+=3)
        {
            //cout<<nums[i-1]<<" "<<nums[i]<<" "<<nums[i+1]<<endl;
            if( (nums[i+1]-nums[i]) <= k  && (nums[i]-nums[i-1]) <= k && (nums[i+1]-nums[i-1]) <= k)
            {
                vector<int>temp;
                temp.emplace_back(nums[i-1]);
                temp.emplace_back(nums[i]);
                temp.emplace_back(nums[i+1]);
                ans.emplace_back(temp);
            }
            else
            {
                //cout<<"c"<<endl;
                return  {};
            }
        }
        
        
        return ans;
        
    }
};