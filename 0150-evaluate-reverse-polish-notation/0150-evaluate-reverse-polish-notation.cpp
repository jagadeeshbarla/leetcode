class Solution {
    
    void show(stack<string>st)
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
public: 
    bool check_for_operator(string s)
    {
        if( s == "+" || s == "-" || s == "*" || s == "/" ){
            return true;
        }
        return false;
    }
    
    int evalute(int a,int b,string op)
    {
        int val = 0;
        if(op == "+")
        {
            val = a+b;
        }
        else if(op == "*")
        {
            val = a*b;
        }
        else if(op == "-")
        {
            val = a-b;
        }
        else if(op == "/")
        {
            val = a/b;
        }
        else
        {
            cout<<a<<" "<<b<<" "<<op<<endl;
            cout << "error";
        }
        return val;
    }
    
    bool check(stack<string>st)
    {
        string first = st.top();
        st.pop();
        string second = st.top();
        st.pop();
        if(check_for_operator(first) || check_for_operator(second))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int evalRPN(vector<string>& t) 
    {
        stack<string>st;
        for(int i = t.size()-1 ; i >= 0 ; i--)
        {
            if(st.empty())
            {
                st.push(t[i]);
            }
            else if(check_for_operator(t[i]))
            {
                st.push(t[i]);
            }
            else
            {
                string top_s = st.top();
                if(!check_for_operator(top_s))
                {
                    int a = stoi(t[i]);
                    int b = stoi(top_s);
                    st.pop();
                    string op = st.top();
                    st.pop();
                    //int val = 0;
                    st.push(to_string(evalute(a,b,op)));
                    while (st.size()>1 && check(st))
                    {
                        //cout<<"hh";
                        int a = stoi(st.top());
                        st.pop();
                        int b = stoi(st.top());
                        st.pop();
                        string op = st.top();
                        st.pop();
                        st.push(to_string(evalute(a,b,op)));
                        //break;
                    }
                }
                else
                {
                    st.push(t[i]);
                }
                
            }
            //show(st);
        }
        
        // if(st.size() == 0)
        // {
        //     cout<<"zero_error";
        //     return 0;
        // }
        
        // cout<<"L";
        // show(st);
        while(st.size() > 1)
        {
            int a = stoi(st.top());
            st.pop();
            int b = stoi(st.top());
            st.pop();
            string op = st.top();
            st.pop();
            st.push(to_string(evalute(a,b,op)));
        }
        return stoi(st.top());
        
    }
};