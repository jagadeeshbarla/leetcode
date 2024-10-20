class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string curr = "";
        int i = 0; 
        while(curr.size() <= target.size() && curr != target){
            curr += 'a';
            while(curr[curr.size()-1] != target[i]){
                ans.emplace_back(curr);
                if(curr[curr.size()-1] == 'z'){
                    curr[curr.size()-1] = 'a';
                    continue;
                }
                curr[curr.size()-1]++;
            }
            ans.emplace_back(curr);
            i++;
        }
        
        return ans;
    }
};