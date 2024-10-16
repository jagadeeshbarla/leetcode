class Solution {
public:
    string longestDiverseString(int a, int b, int c) {       
        string ans = "";
        while(a > 0 && b > 0 && c > 0){
            ans += "abc";
            a--;
            b--;
            c--;
        }
        
        while( a > 0 && b > 0){
            ans += "ab";
            a--;b--;
        }
        while(a > 0 && c > 0){
            ans += "ac";
            a--;c--;
        }
        while(b > 0 && c > 0){
            ans += "bc";
            b--;c--;
        }
        
        char ch;
        int ch_count = 0;
        if( a > 0){
            ch = 'a'; 
            ch_count = a;
        }
        if(b > 0){
            ch = 'b';
            ch_count = b;
        }
        if(c > 0){
            ch = 'c';
            ch_count = c;
        }
        
        if(ans.size() == 0){
            if(ch_count == 1){
                ans+=ch;
                return ans;
            }
            ans += ch;
            ans+= ch;
            return ans;
        }
        if(ans[0] != ch){
            if(ch_count>0){
                ans = ch + ans;
                ch_count--;
            }
            if(ch_count>0){
                ans = ch + ans;
                ch_count--;
            }
        }
        cout<<ans;
        string ans_1 = "";
        for(int i = 0 ; i < ans.size()-1 ; i++){
            ans_1 += ans[i];
            if(ans[i] != ch && ans[i+1] != ch && ch_count > 0){
                ans_1 += ch ;
                ch_count -= 1;
                if(ch_count > 0){
                    ans_1 += ch;
                    ch_count -=1;                    
                }
            }
            else if(ans[i] == ch && ans[i+1] == ch){
                i++;
                ans_1 += ans[i];
            }
            else if(ans[i] == ch && ch_count > 0){
                ans_1+=ch;
                ch_count--;
            }
        }
        ans_1 += ans[ans.size()-1];
        if(ans[ans.size()-1] != ch){
            if(ch_count > 0){
                ans_1 += ch;
                ch_count--;
            }
            if(ch_count > 0){
                ans_1 += ch;
                ch_count--;
            }
        }
        if(ans[ans.size()-1] == ch){
            if(ch_count > 0){
                ans_1 += ch;
                ch_count--;
            }
        }
        return ans_1;
    }
};