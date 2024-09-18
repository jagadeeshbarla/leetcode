class Solution {
public:
    string decToBinary(int n)
    {
        string s="";
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1){
                s+='1';
            }
            else{
                s+='0';
            }
        }
        return s;
    }
    int string_to_dec(string s){
        int ans = 0;
        int p = 1;
        for (int i = 31; i >= 10; i--) {
            if(s[i] == '1'){
                ans += p;                
            }
            p*=2;
        }
        return ans;        
    }
    int postive_number_sum(int a,int b){
        string s1 = decToBinary(a);
        string s2 = decToBinary(b);
        int carry = 0;
        string ans(32,'0');
        for (int i = 31; i >= 0; i--) {
            if(s1[i] =='1' && s2[i] == '1'){
                if(carry == 0){
                    ans[i] = '0';
                    carry =1;                    
                }
                else{
                    carry = 1;
                    ans[i] = '1';
                }
            }
            else if(s1[i] =='0' && s2[i] == '0'){
                if(carry == 0){
                    ans[i] = '0';
                    carry = 0;                    
                }
                else{
                    carry = 0;
                    ans[i] = '1';
                }
            }
            else{
                if(carry == 0){
                    ans[i] = '1';
                    carry = 0;                    
                }
                else{
                    carry = 1;
                    ans[i] = '0';
                }
                
            }
        }
        return string_to_dec(ans);
    }
    int cal(int a,int b){
        //cout<<a<<" "<<b<<endl;
        string s1 = decToBinary(a);
        string s2 = decToBinary(b);
        // cout<<s1<<endl;
        // cout<<s2<<endl;
        // cout<<endl;
        int carry = 0;
        string ans(32,'0');
        for (int i = 31; i >= 0; i--){
            if(s1[i] == '1' && s2[i] == '0'){
                ans[i] = '1';
            }
            else if(s1[i] == '0' && s2[i] == '1'){
                int c = 1;
                while(s1[i-c] == '0'){
                    s1[i-c] = '1';
                    c++;                    
                }
                s1[i-c] = '0';
                ans[i] = '1';
            }
        }
        // cout<<s1<<endl;
        // cout<<s2<<endl;
        // cout<<ans<<endl;
        return string_to_dec(ans);        
    }
    
    int sub(int a ,int b){
        if(a < 0){
            return sub(b,a); // b is always negative number;
        }
        int flag = 1;
        if(abs(b) >  a){
            return cal(abs(b),a)*-1;
        }
        else{
            return cal(a,abs(b));            
        }
    }
    
    int getSum(int a, int b) {
        
        if(a == 0  && b != 0){
            return b;
        }
        if(a != 0  && b == 0){
            return a;
        }
        int flag = 1;
        if(a<0 && b<0){
            a*=-1;
            b*=-1;
            flag = -1;
        }
        if( a < 0  && b > 0){
            return sub(a,b);
        }
        if( a > 0  && b < 0){
            return sub(a,b);
        }
        return postive_number_sum(a,b) * flag;
    }
};