class Solution {
    bool check(string s){
        bool flag = false;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1'){
                flag = true;
            }
            else{
                if(flag == true && s[i]=='0'){
                    return false;
                }
            }
        }
        return true;
    }
public:
    long long minimumSteps(string s) {
        if(check(s)){
            return 0;
        }
        long long int ans = 0;
        int j = s.size()-1 ;
        int i = 0 ;
        while(s[i] == '0'){
            i++;
        }
        while(s[j]=='1'){
            j--;
        }
        j++;
        int i2 = i+1;
        while(i2 < j){
            while(s[i2] == '1'){
                i2++;
            }
            ans += (i2-i);
            i++;
            i2++;
        }
        return ans;
    }
};