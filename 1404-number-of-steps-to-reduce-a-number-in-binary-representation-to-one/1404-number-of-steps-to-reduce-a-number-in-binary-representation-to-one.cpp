class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int count = 0 ; 
        while(s.size() != 1)
        {
            //cout<<s<<"  ";
            if(s[s.size()-1] == '0')
            {
                s.erase(s.length()-1);
                ans += 1;
            }
            else
            {
                ans+=1;
                char carry = '1';
                for( int i = s.length()-1 ; i >= 0 ; i--)
                {
                    if(s[i] =='1' && carry == '1')
                    {
                        s[i] = '0',carry = '1';
                    }
                    else if(s[i]=='0' && carry == '1')
                    {
                        s[i] = '1',carry = '0';
                    }
                    else
                    {
                        break;
                    }
                }
                if(carry == '1')
                {
                    s = '1'+ s ;
                }
            }
            
            //cout<<" "<<s<<endl;
            // if(count ==20)break;
            // count++;
        }
        return ans;
    }
};


