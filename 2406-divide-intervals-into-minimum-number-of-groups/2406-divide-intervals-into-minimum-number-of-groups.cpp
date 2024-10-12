class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0 ; i < intervals.size() ;i++ ){
            if(ans.size() > 0 && (ans.begin()->first) < intervals[i][0]){
                ans.begin()->second -= 1;
                if(ans.begin()->second < 1){
                    ans.erase( ans.begin()->first);                    
                }
            }                
            ans[intervals[i][1]] += 1;
        }
        
        int ans_f = 0;
        for(auto it : ans){
            ans_f += it.second;
        }
        return ans_f;        
    }
};