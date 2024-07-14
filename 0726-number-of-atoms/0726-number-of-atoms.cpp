class Solution {
public:
    int pow(int x)
    {
        int ans = 1;
        for(int j = 0 ; j < x ; j++)
        {
            ans *= 10;
        }
        return ans;
    }
    int stoint(string s)
    {
       
        int n = 0 ;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] < '0' && s[i] >'9')
            {cout<<"d"<<endl;}
           n += pow(s.size()-i-1)*(int(s[i])-48);
        }
        return n;
    }
    string countOfAtoms(string formula) {
        map<string,int>m;
        
        
        stack<pair<string,int>>s;
        
        for(int i = 0 ; i < formula.size() ; i++)
        {
            if(formula[i] == '(')
            {
                s.push(make_pair( "(" , 1 )) ;  
            }
            else if (formula[i] == ')')
            {
                //cout<<"jj"<<endl;
                string num="";
                i++;
                if(i < formula.size() && (formula[i] >= '0' && formula[i] <= '9' ))
                {
                    while(i < formula.size() && (formula[i] >= '0' && formula[i] <= '9' )) //creating the num
                    {
                        num += formula[i++];
                    }
                    //cout<<"num"<<num<<" "<<formula[i]<<endl;
                    if( i < formula.size() )//&& (formula[i] < '0' && formula[i] > '9' ))
                    {
                        //cout<<"kk"<<endl;
                        i--;
                    }
                }
                else
                {
                    num += "1";
                    i--;
                }
                int n = stoint(num);
                
                stack<pair<string,int>>temp;
                while(!s.empty() && s.top().first != "(") // adding num for the given numbers
                {
                    temp.push(make_pair(s.top().first,((s.top().second)*n)  )  );
                    s.pop();
                    
                }
                //cout<<s.top().first<<" ";
                if(!s.empty() && s.top().first == "(")
                {
                    s.pop();
                    //cout<<s.top().first<<endl;
                }
                while(!temp.empty())
                {
                    s.push(temp.top());
                    temp.pop();
                }
            }
            else if(formula[i] >= '0' && formula[i] <= '9') // if it is a number but not in front of a ')'
            {
                string num = "";
                while(i < formula.size() && (formula[i] >= 48 && formula[i] <= 57 ))
                {
                    num += formula[i++];
                }
                int n = stoint(num);
                s.top().second += (n-1);
                i--;
            }
            else if(formula[i] >= 'A' && formula[i] <= 'Z')
            {
                string c_name = "";
                c_name += formula[i++];
                while(i < formula.size() && formula[i] >= 'a' && formula[i] <= 'z')
                {
                    c_name += formula[i++];
                }
                i--;
                s.push(make_pair(c_name,1));
                //cout<<s.top().first<<endl;
            }
        }
        
        while(!s.empty())
        {
            //cout<<s.top().first<<" "<<s.top().second<<endl;
            m[s.top().first] += s.top().second;
            s.pop();
        }
        
        map<string,int>::iterator itr;
        string ans;
        for(itr = m.begin() ; itr != m.end() ; itr++)
        {
            ans += itr->first ;
            if(itr->second > 1)
            {
                ans += to_string(itr->second);
            }
        }
        return ans;
    }
};


// "H20O"
// "H21O"
// "H20O31"
// "H20OgHgH1"
// "H20OgOOHgH1"