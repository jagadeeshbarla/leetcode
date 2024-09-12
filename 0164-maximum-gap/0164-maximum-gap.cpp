class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return 0;
        }
        map<int,int>m;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            m.insert({nums[i],1});
        }
        int ans = 0;
        map<int,int>::iterator itr;
        map<int,int>::iterator itr_n = m.begin();
        itr_n++;
        map<int,int>::iterator itr_l = m.end();
        itr_l--;
        for(itr = m.begin() ; itr != itr_l ; itr++)
        {
            //cout<<itr->first<<" "<<itr_n->first<<endl;
            ans = max(ans,(itr_n->first - itr->first));
            itr_n++;
        }
        return ans;
    }
};