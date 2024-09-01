class Solution {
public:
    int numDecodings(string s) {
        
        vector<int>v(s.length(),0);
        vector<int>pc(s.length(),0);
        // int j = s.length()-1;
        // while(s.length() >= 0 && s[j] =='0')
        // {
        //     s.pop_back();
        // }
        if(s[s.length()-1] =='0')
        {
            v[s.length()-1] = 0;
        }
        else
        {
            v[s.length()-1] = 1;
        }
        
        for(int i = s.length()-2 ; i >= 0 ; i--)
        {
            if(s[i] == '0')
            {
                if(s[i+1] =='0')
                {
                    return 0;
                }
                v[i] = 0;
            }
            else
            {
                if(s[i+1] =='0')
                {
                    if(s[i] ==  '1' || s[i] == '2')
                    {
                        if(i+2 >= s.length())
                        {
                            v[i] = 1;
                        }
                        else
                        {
                            v[i] = v[i+2];                   
                        }  
                        // if(i != s.length()-2)
                        // {
                            s[i] = 'n';
                       // }
                        
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    
                    if(s[i] == '1')
                    {
                        if(s[i+1] != 'n')
                        {
                            v[i] = ((v[i+1]-pc[i+1])*2)+pc[i+1];
                            pc[i] += v[i+1]-pc[i+1];
                        }
                        else
                        {
                            v[i] = v[i+1];
                        }
                        
                    }
                    else if(s[i] == '2')
                    {
                        if(s[i+1]=='1'||s[i+1]=='2'||s[i+1]=='3'||s[i+1]=='4'||s[i+1]=='5'||s[i+1]=='6')
                        {
                            v[i] = ((v[i+1]-pc[i+1])*2)+pc[i+1];
                            pc[i] += v[i+1]-pc[i+1];
                        }
                        else
                        {
                            v[i] = v[i+1];
                        }
                    }
                    else
                    {
                        v[i] = v[i+1];
                    }
                
                }
            }
            
        }
        
        cout<<endl;
        for(int i = 0 ; i < v.size() ;i++)
        {
            cout<<pc[i]<<" ";
        }
        cout<<endl;
        cout<<s<<endl;
        
        return v[0];        
    }
};