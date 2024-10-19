class Solution {
public:
    string make_string(string s){
        string ans = s;
        ans += '1';
        for(int i = s.size()-1 ; i>= 0 ; i--){
            ans += (s[i] == '0') ? '1' : '0';
        }
        return ans;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2 ; i <= n ; i++){
            s = make_string(s);
        }
        
        return s[k-1];
    }
};