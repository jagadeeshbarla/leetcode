class Solution {
    bool check(vector<int>&curr , vector<int>&base){
        for(int i = 0 ; i < curr.size() ; i++){
            if(curr[i] != base[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>base(26,0),curr(26,0);
        if(s1.size() > s2.size()){
            return false;
        }
        for(int i = 0 ; i <  s1.size() ; i++)
        {
            base[s1[i] - 'a']++;
            curr[s2[i] - 'a']++;
        }
        if(check(curr,base)){
            return true;
        }
        for(int i = s1.size() ; i < s2.size() ; i++){
            curr[s2[i-s1.size()]-'a']--;
            curr[s2[i] - 'a']++;
            if(check(curr,base)){
                return true;
            }
        }
        return false;
    }
};