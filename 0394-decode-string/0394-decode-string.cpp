class Solution {
public:
    int con(string n_con)
    {
        int ans = 0;
        for(int i=0;i<n_con.size();i++)
        {
            ans+=(n_con[i]-48)*pow(10,i);
        }
        //cout<<ans<<endl;
        return ans;
    }
    string decodeString(string s) 
    {
        string ans="";
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
            {
                string kk = "";
                kk+=s[i];
                st.push(kk);
            }
            else
            {
                string temp="";
                while(st.top()!="[")
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                
                //number creation
                string n_string ="";
                while(!st.empty())
                {
                    if(st.top().size()==1)
                    {
                        char t = st.top()[0];
                        //cout<<t;
                        if(t>=48 && t<=57)
                        {
                            n_string+=st.top();
                            st.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {break;}
                }
                
                //cout<<n_string<<endl;
                int num = con(n_string);               
                
                string temp_1="";
                for(int i=0;i<num;i++)
                {
                    temp_1+=temp;
                }
             
                reverse(temp_1.begin(),temp_1.end());
                st.push(temp_1);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};