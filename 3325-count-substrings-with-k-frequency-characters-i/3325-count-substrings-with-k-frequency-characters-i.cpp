class Solution {
public:
    bool check_functionality(vector<int>&alpha_count , int k){
        for(int i = 0 ; i < alpha_count.size() ; i++ ){
            if(alpha_count[i] >= k){
                return true;
            }
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        vector<int>flag(s.size(),false);
        int ans = 0;
        int window_size = k;
        while(window_size <= s.size()){
            vector<int>alpha_count(26,0);
            for(int i = 0 ; i < window_size ; i++){
                alpha_count[s[i]-'a']++;
            }
            if(check_functionality(alpha_count,k)){
                ans++;
            }
            for(int i = window_size ; i < s.size() ;i++){
                alpha_count[s[i]-'a']++;
                alpha_count[s[i-window_size]-'a']--;
                if(check_functionality(alpha_count,k)){
                    ans++;
                }
            }
            window_size++;
        }
        return ans;        
    }
};