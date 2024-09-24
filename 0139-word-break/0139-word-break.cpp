class Solution {
public:
    bool solve(string s , map<string,int>&m , map<string,bool>&dp){
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        if(m.find(s) != m.end()){
            return dp[s] = true;
        }        
        bool ans  = false;
        string temp = "" ;
        for(int i  = 0 ; i < s.size() ; i++){
            temp += s[i];
            if(m.find(temp) != m.end() ){
                string temp_2 = "";
                for(int j = i + 1 ; j < s.size() ; j++){
                    temp_2 += s[j];
                }
                ans |= solve(temp_2,m,dp);
                if(ans == true){
                    return dp[s] = true;
                }
            }
        }
        return dp[s] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>m;
        map<string,bool>dp;
        for(int i = 0 ; i < wordDict.size() ; i++){
            m.insert({wordDict[i],1});
        }
        return solve(s,m,dp);
    }
};